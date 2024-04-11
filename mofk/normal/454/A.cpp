#include<stdio.h>
int main(void)
{
    int n,i,j;
    char a[105][105];
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) a[i][j]='*';
    }
    for(i=0;i<(n-1)/2;i++)
    {
        for(j=(n-1)/2-i;j<=(n-1)/2+i;j++) a[i][j]='D';
    }
    for(i=0;i<n;i++) a[(n-1)/2][i]='D';
    for(i=(n+1)/2;i<n;i++)
    {
        for(j=i-(n-1)/2;j<=3*(n-1)/2-i;j++) a[i][j]='D';
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++) printf("%c",a[i][j]);
        printf("\n");
    }
}