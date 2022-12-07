#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN=200010;
const int INF=1000000000;
int n,a[MAXN],f[MAXN],c[MAXN],ans;
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    f[0]=0,c[0]=0;
    for(int i=1;i<=n;i++) c[i]=INF;
    for(int i=1;i<=n;i++)
    {
        f[i]=lower_bound(c,c+n+1,a[i])-c;
        c[f[i]]=min(c[f[i]],a[i]);
    }
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    printf("%d\n",ans);
    return 0;   
}