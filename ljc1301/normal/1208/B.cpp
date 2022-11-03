#include <bits/stdc++.h>
using namespace std;
const int maxn=2005;
int n,a[maxn],b[maxn],m;
bool vis[maxn];
int main()
{
    int i,j,ans=0;
    scanf("%d",&n),ans=n;
    for(i=0;i<n;i++) scanf("%d",&a[i]),b[i]=a[i];
    sort(b,b+n),m=unique(b,b+n)-b;
    for(i=0;i<n;i++) a[i]=lower_bound(b,b+m,a[i])-b;
    for(i=0;i<m;i++) vis[i]=0;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<m;j++) vis[j]=0;
        for(j=0;j<i;j++)
            if(!vis[a[j]])
                vis[a[j]]=1;
            else break;
        if(j<i) break;
        for(j=n-1;;j--)
            if(vis[a[j]])
                break;
            else vis[a[j]]=1;
        ans=min(ans,j-i+1);
    }
    printf("%d\n",ans);
    return 0;
}