#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
int main()
{
    scanf("%d%d",&n,&k);
    if(k>=n*(n-1)/2) {puts("no solution");return 0;}
    else
    {
        for(int i=1;i<=n;i++)
            printf("%d %d\n",0,i);
    }
    return 0;
}