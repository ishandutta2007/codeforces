#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
int n,a[100010],f,r;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n*n;i++) a[i]=i;
    f=1,r=n*n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<(n>>1);j++)
            printf("%d %d ",a[f++],a[r--]);
        printf("%d %d\n",a[f++],a[r--]);
    }
    return 0;
}