#include <bits/stdc++.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);
    int num = (n-2)/4;
    for(int i=0; i<num; i++)
        printf("4");
    printf("5\n");
    for(int i=0; i<=num; i++)
        printf("5");
}