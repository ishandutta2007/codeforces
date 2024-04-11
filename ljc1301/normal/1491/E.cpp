#include <bits/stdc++.h>
using namespace std;
const int maxn=200005;
// proof by induction: if fibtree F_k cut into sz=F_k-1, F_k-2, then these are fibtree
int n,f[maxn],he[maxn],ne[maxn<<1],to[maxn<<1],tot,sz[maxn];
bool vis[maxn<<1];
inline void add_edge(int u,int v) { to[tot]=v,vis[tot]=0,ne[tot]=he[u],he[u]=tot++; }
void finde(int u,int fa,int k)
{
    int i;
    sz[u]=1;
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa && !vis[i])
        {
            finde(to[i],u,k),sz[u]+=sz[to[i]];
            if(sz[to[i]]==f[k-2]) throw i;
            if(sz[to[i]]==f[k-1]) throw i^1;
        }
}
bool check(int rt,int k)
{
    if(k<=1) return true;
    try
    {
        finde(rt,-1,k);
    }
    catch(int id)
    {
        vis[id]=vis[id^1]=1;
        return check(to[id],k-2) && check(to[id^1],k-1);
    }
    return false;
}
int main()
{
    int i,u,v;
    scanf("%d",&n);
    if(n==1) { printf("YES\n"); return 0; }
    for(tot=0,i=1;i<=n;i++) he[i]=-1;
    for(i=1;i<n;i++) scanf("%d%d",&u,&v),add_edge(u,v),add_edge(v,u);
    f[0]=f[1]=1;
    for(i=2;f[i-1]<n;i++) f[i]=f[i-1]+f[i-2];
    if(f[i-1]>n) { printf("NO\n"); return 0; }
    printf("%s\n",check(1,i-1)?"YES":"NO");
    return 0;
}