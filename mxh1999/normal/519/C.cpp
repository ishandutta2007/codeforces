//Author:mxh1999
//
#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n,m;
int ans=0;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<=n;i++)
    if (2*i<=m)
    {
        int j=(n-i)/2;
        if ((m-2*i)<j)  j=m-2*i;
        if (i+j>ans)    ans=i+j;
    }
    printf("%d\n",ans);
    return 0;
}