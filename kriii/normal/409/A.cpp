#include <stdio.h>

int w[3][3] = {0,1,-1,-1,0,1,1,-1,0};
char A[22],B[22];
int a;

int main()
{
    scanf ("%s %s",A,B);
    for (int i=0;A[i];i+=2){
        int p,q;
        if (A[i] == '[') p = 2;
        else if (A[i] == '(') p = 1;
        else p = 0;
        if (B[i] == '[') q = 2;
        else if (B[i] == '(') q = 1;
        else q = 0;
        a += w[p][q];
    }

    if (a == 0) printf ("TIE");
    else if (a < 0) printf ("TEAM 1 WINS");
    else printf ("TEAM 2 WINS");
    
    return 0;
}