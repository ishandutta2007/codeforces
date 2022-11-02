#include<cstdio>
#include<iostream>
using namespace std;

#define maxn 100010
int a[maxn];
int f[maxn][2];
int n,m;

int main()
{
    scanf("%d",&n);
    a[0]=-1;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        f[i][0]=1;
        if (i!=1)   f[i][1]=2;
    }
    for (int i=2;i<=n;i++)
    {
        if (a[i]>a[i-1])    {f[i][0]=f[i-1][0]+1;f[i][1]=max(f[i][1],f[i-1][1]+1);}
        if (a[i]>a[i-2]+1)  f[i][1]=max(f[i][1],f[i-2][0]+2);
    }
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        if (f[i][1]>ans)    ans=f[i][1];
        if (i<n)    f[i][0]++;
        if (f[i][0]>ans)    ans=f[i][0];
    }
    printf("%d\n",ans);
}