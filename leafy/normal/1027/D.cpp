#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
const int N=200005;
int n;
int c[N],a[N];
vector<int> G[N],rG[N];
int b[N],vis[N],vs[N],s[N],f[N];
int num;
void dfs(int u)
{
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
        if(!vis[G[u][i]]) dfs(G[u][i]);
    vs[++num]=u;
}
void rdfs(int u,int k)
{
    b[u]=k;f[k]=min(f[k],c[u]);
    for(int i=0;i<rG[u].size();i++)
        if(!b[rG[u][i]]) rdfs(rG[u][i],k);
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&c[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(i!=a[i]) G[i].push_back(a[i]),rG[a[i]].push_back(i);
    }
    for(int i=1;i<=n;i++)
        if(!vis[i]) dfs(i);
    num=0;
    for(int i=n;i;i--)
        if(!b[vs[i]]) 
        {
            f[++num]=c[vs[i]];
            rdfs(vs[i],num);
        }
    for(int i=1;i<=n;i++)
        for(int j=0;j<G[i].size();j++)
            if(b[i]!=b[G[i][j]]) s[b[i]]++;
    int ans=0;
    for(int i=1;i<=num;i++) if(!s[i]) ans+=f[i];
    cout<<ans;
    return 0;
}