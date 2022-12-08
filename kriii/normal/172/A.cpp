#include <stdio.h>

int N; char A[22],B[22];

int main()
{
    int i,j;

    scanf ("%d %s",&N,A);
    for (i=1;i<N;i++){
        scanf ("%s",B);
        for (j=0;A[j];j++){
            if (A[j] != B[j]){
                A[j] = '\0'; break;
            }
        }
    }
    for (i=0;A[i];i++);
    printf ("%d",i);

    return 0;
}