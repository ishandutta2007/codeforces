#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=2010;
const int INF=1000000000;
int n,h,l,r,a[MAXN],f[MAXN][MAXN],ans;
int main()
{
    scanf("%d%d%d%d",&n,&h,&l,&r);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<h;i++) f[0][i]=-INF;
    for(int i=1;i<=n;i++)
        for(int j=0;j<h;j++)
        {
            f[i][j]=max(f[i-1][(j-a[i]+h)%h],f[i-1][(j-a[i]+1+h)%h]);
            if(j>=l&&j<=r) f[i][j]++;
        }
    for(int i=0;i<h;i++) ans=max(ans,f[n][i]);
    printf("%d\n",ans);
    return 0;
}