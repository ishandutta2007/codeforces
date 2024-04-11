#include <stdio.h>

#define MAXN 100005

char A[MAXN],B[MAXN];

int main()
{
    int i,a=0,b=0;
    scanf("%s%s",&A,&B);
    for (i=0;A[i];i++) if (A[i] != B[i]){
        if (A[i] == '4') a++;
        else b++;
    }
    printf("%d",a>b?a:b);
}