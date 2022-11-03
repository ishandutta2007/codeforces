#include <bits/stdc++.h>
using namespace std;
// reverse-able
// bud cannot change to leaf and vice versa
// hang to root
const int maxn=200005;
int n,he[maxn],ne[maxn<<1],to[maxn<<1],tot,s,ans;
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
int dfs(int u,int fa) // remain leaf: 1
{
    int t=0,i;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
            t+=dfs(to[i],u);
    if(t) ans+=t-1;
    return !t;
}
int main()
{
    int T,i,u,v;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(tot=0,i=1;i<=n;i++) he[i]=-1;
        for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
        for(s=ans=0,i=he[1];~i;i=ne[i])
            s+=dfs(to[i],1);
        if(s) ans+=s;
        else ans++;
        printf("%d\n",ans);
    }
    return 0;
}