#include <bits/stdc++.h>
using namespace std;
const int maxn=1000005;
const int maxloga=21;
const int maxa=1<<maxloga;
int n,f[maxa|1],g[maxa|1],a[maxn];
int main()
{
    int i,ans=0,j,k;
    scanf("%d",&n);
    for(i=0;i<maxa;i++) f[i]=g[i]=-1;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        g[a[i]]=f[a[i]],f[a[i]]=i;
    }
    for(i=maxa-1;i>=0;i--)
        for(j=0;j<maxloga;j++)
            if(i&(1<<j))
                if(f[i]>f[i^(1<<j)])
                    g[i^(1<<j)]=max(f[i^(1<<j)],g[i]),f[i^(1<<j)]=f[i];
                else if(f[i]!=f[i^(1<<j)])
                    g[i^(1<<j)]=max(g[i^(1<<j)],f[i]);
                else g[i^(1<<j)]=max(g[i^(1<<j)],g[i]);
    for(i=0;i+2<n;i++)
    {
        k=0;
        for(j=maxloga-1;j>=0;j--)
            if(!(a[i]&(1<<j)) && g[k|(1<<j)]>i)
                k|=1<<j;
        ans=max(ans,a[i]|k);
    }
    printf("%d\n",ans);
    return 0;
}