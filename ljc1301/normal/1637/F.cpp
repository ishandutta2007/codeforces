#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200005;
int n,rt,he[maxn],to[maxn<<1],ne[maxn<<1],tot;
ll a[maxn],maxx[maxn],ans;
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
void dfs(int u,int fa)
{
    int i;
    ll max2=0;
    maxx[u]=0;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
        {
            dfs(to[i],u);
            if(maxx[to[i]]>maxx[u]) max2=maxx[u],maxx[u]=maxx[to[i]];
            else max2=max(max2,maxx[to[i]]);
        }
    // printf("%d %lld\n",u,maxx[u]-max2);
    if(a[u]>=maxx[u]) ans+=a[u]-maxx[u],maxx[u]=a[u];
    // ans+=maxx[u]-max2;
}
int main()
{
    int i,u,v;
    ll max1=0,max2=0;
    scanf("%d",&n);
    for(tot=0,i=1;i<=n;i++) he[i]=-1,scanf("%lld",&a[i]);
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    for(rt=1,i=2;i<=n;i++)
        if(a[i]>a[rt])
            rt=i;
    // printf("%d\n",rt);
    ans=0;
    for(i=he[rt];~i;i=ne[i])
    {
        dfs(to[i],rt);
        if(maxx[to[i]]>max1) max2=max1,max1=maxx[to[i]];
        else max2=max(max2,maxx[to[i]]);
    }
    // printf("rt: %lld %lld %lld\n",max1,max2,a[rt]);
    printf("%lld\n",ans+a[rt]-max1+a[rt]-max2);
    return 0;
}