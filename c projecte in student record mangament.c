#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_NAME 50
#define STUDENT_COUNT 3
#define FILE_NAME "students.txt"
/* Structure to store one student's record */
struct Student {
    int roll;
    char name[MAX_NAME];
    float marks;
};
/* Function to initialize names and roll numbers */
void initStudents(struct Student s[]) {
    /* Fixed data for project: Nick, Jack, Ram */
    s[0].roll = 1;
    strcpy(s[0].name, "Nick");
    s[0].marks = 0.0;
    s[1].roll = 2;
    strcpy(s[1].name, "Jack");
    s[1].marks = 0.0;
    s[2].roll = 3;
    strcpy(s[2].name, "Ram");
    s[2].marks = 0.0;
}
/* Function to input only marks from user */
void inputMarks(struct Student s[], int n) {
    int i;
    printf("=== ENTER STUDENT MARKS ===");
    for (i = 0; i < n; i++) {
        printf("Student %d", i + 1);
        printf("Name : %s", s[i].name);
        printf("Roll : %d", s[i].roll);
        printf("Enter marks : ");
        scanf("%f", &s[i].marks);
    }
}
/* Function to write records to file */
void writeToFile(struct Student s[], int n) {
    FILE *fp = fopen(FILE_NAME, "w");
    int i;
    if (fp == NULL) {
        printf("Error opening file '%s' for writing.", FILE_NAME);
        exit(1);
    }
    /* Write header (for understanding) */
    fprintf(fp, "STUDENT ACADEMY RECORDS");
    fprintf(fp, "Roll\tName\tMarks");
    /* Write each student's data */
    for (i = 0; i < n; i++) {
        fprintf(fp, "%d\t%s\t%.2f", s[i].roll, s[i].name, s[i].marks);
    }
   fclose(fp);
    printf("All records successfully stored in file '%s'.", FILE_NAME);
}
/* Function to read records from file and display */
void readFromFileAndDisplay() {
    FILE *fp = fopen(FILE_NAME, "r");
    char line[200];
    if (fp == NULL) {
        printf("Error opening file '%s' for reading.", FILE_NAME);
        exit(1);
    }
    printf("=== DISPLAYING DATA FROM FILE ===");
    /* Read line by line and print */
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }
    fclose(fp);
}
/* Function to show menu-like explanation */
void showInstructions() {
    printf("STUDENT ACADEMY RECORD MANAGEMENT PROJECT");
    printf("=========================================");
    printf("1. Program has three fixed students: Nick, Jack, Ram.");
    printf("2. You will enter marks for each student.");
    printf("3. Program will store all records in a file named '%s'.", FILE_NAME);
    printf("4. Finally, program will read the file and display the result.");
}
int main() {
    struct Student students[STUDENT_COUNT];
    /* Step 1: Show instructions to user */
    showInstructions();
    /* Step 2: Initialize student names and roll numbers */
    initStudents(students);
    /* Step 3: Input marks from user */
    inputMarks(students, STUDENT_COUNT);
    /* Step 4: Write all data to file */
    writeToFile(students, STUDENT_COUNT);
    /* Step 5: Read from file and display */
    readFromFileAndDisplay();
    printf("Program finished. Check '%s' file for stored records.", FILE_NAME);
    return 0;
}
