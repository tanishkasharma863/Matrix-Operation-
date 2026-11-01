/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/

#include <stdio.h>

#define MAX 10

// Structure to store matrix
struct Matrix {
    int row, col;
    int a[MAX][MAX];
};

// Function to input matrix
void inputMatrix(struct Matrix *m) {
    int i, j;

    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m->row, &m->col);

    printf("Enter matrix elements:\n");

    for(i = 0; i < m->row; i++) {
        for(j = 0; j < m->col; j++) {
            scanf("%d", &m->a[i][j]);
        }
    }
}

// Function to display matrix
void displayMatrix(struct Matrix m) {
    int i, j;

    for(i = 0; i < m.row; i++) {
        for(j = 0; j < m.col; j++) {
            printf("%d ", m.a[i][j]);
        }
        printf("\n");
    }
}

// Function for matrix addition
void addition(struct Matrix m1, struct Matrix m2) {
    int i, j;
    struct Matrix result;

    if(m1.row != m2.row || m1.col != m2.col) {
        printf("Addition not possible!\n");
        return;
    }

    result.row = m1.row;
    result.col = m1.col;

    for(i = 0; i < m1.row; i++) {
        for(j = 0; j < m1.col; j++) {
            result.a[i][j] = m1.a[i][j] + m2.a[i][j];
        }
    }

    printf("Addition Result:\n");
    displayMatrix(result);
}

// Function for matrix multiplication
void multiplication(struct Matrix m1, struct Matrix m2) {
    int i, j, k;
    struct Matrix result;

    if(m1.col != m2.row) {
        printf("Multiplication not possible!\n");
        return;
    }

    result.row = m1.row;
    result.col = m2.col;

    for(i = 0; i < result.row; i++) {
        for(j = 0; j < result.col; j++) {
            result.a[i][j] = 0;

            for(k = 0; k < m1.col; k++) {
                result.a[i][j] +=
                m1.a[i][k] * m2.a[k][j];
            }
        }
    }

    printf("Multiplication Result:\n");
    displayMatrix(result);
}

// Function for matrix transpose
void transpose(struct Matrix m) {
    int i, j;
    struct Matrix result;

    result.row = m.col;
    result.col = m.row;

    for(i = 0; i < m.row; i++) {
        for(j = 0; j < m.col; j++) {
            result.a[j][i] = m.a[i][j];
        }
    }

    printf("Transpose Result:\n");
    displayMatrix(result);
}

// Main function
int main() {
    struct Matrix m1, m2;
    int choice;

    do {
        printf("\n--- MATRIX OPERATIONS ---\n");
        printf("1. Addition\n");
        printf("2. Multiplication\n");
        printf("3. Transpose\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter first matrix:\n");
                inputMatrix(&m1);

                printf("Enter second matrix:\n");
                inputMatrix(&m2);

                addition(m1, m2);
                break;

            case 2:
                printf("Enter first matrix:\n");
                inputMatrix(&m1);

                printf("Enter second matrix:\n");
                inputMatrix(&m2);

                multiplication(m1, m2);
                break;

            case 3:
                printf("Enter matrix:\n");
                inputMatrix(&m1);

                transpose(m1);
                break;

            case 4:
                printf("Exiting program...");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 4);

    return 0;
}

