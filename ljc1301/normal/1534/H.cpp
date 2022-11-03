#include <bits/stdc++.h>
using namespace std;
// determine which subtree; dp
typedef pair<int,int> pii;
const int maxn=100005;
int n,he[maxn],ne[maxn<<1],to[maxn<<1],tot,ans[maxn],/*dfn[maxn],sz[maxn],*/temp[maxn];
// bool ins[maxn];
vector<pii> val[maxn]; // ans: given u in subtree; val: children's ans
inline void add_edge(int u,int v) { to[tot]=v,ne[tot]=he[u],he[u]=tot++; }
void dfs1(int u,int fa)
{
    int i;
    /*dfn[u]=tot++,sz[u]=1,*/val[u].clear();
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
            dfs1(to[i],u),/*sz[u]+=sz[to[i]],*/
            val[u].push_back(make_pair(max(ans[to[i]],1),to[i]));
    sort(val[u].begin(),val[u].end(),greater<pii>());
    for(ans[u]=0,i=0;i<(int)val[u].size();i++)
        ans[u]=max(ans[u],i+val[u][i].first);
}
void dfs2(int u,int fa)
{
    int i,m=(int)val[u].size(),cur;
    if(fa!=-1)
        for(i=m-1;i && val[u][i-1]<val[u][i];i--)
            swap(val[u][i-1],val[u][i]);
    for(temp[m]=/*0*/1,i=m-1;i;i--) temp[i]=max(temp[i+1],i-1+val[u][i].first);
    for(i=0,cur=/*0*/1;i<m;cur=max(cur,i+val[u][i].first),i++)
        if(val[u][i].second!=fa)
            val[val[u][i].second].push_back(make_pair(max(cur,temp[i+1]),u));
    for(i=he[u];~i;i=ne[i])
        if(to[i]!=fa)
            dfs2(to[i],u);
    // printf("%d:",u); for(i=0;i<m;i++) printf(" %d(%d)",val[u][i].first,val[u][i].second); printf("\n");
}
vector<int> init(int N,vector<pii> e)
{
    int i,cur,j;
    n=N;
    vector<int> res;
    if(n==1) { res.push_back(0); return res; }
    for(tot=0,i=1;i<=n;i++) he[i]=-1; // ins[i]=0;
    for(i=0;i<n-1;i++)
        add_edge(e[i].first,e[i].second),add_edge(e[i].second,e[i].first);
    /*tot=0,*/dfs1(1,-1),dfs2(1,-1);
    for(i=1;i<=n;res.push_back(cur),i++)
        if(val[i].size()==1) cur=val[i][0].first;
        else
            for(cur=0,j=1;j<(int)val[i].size();j++)
                cur=max(cur,j-1+val[i][j].first+val[i][0].first);
    return res;
}
int solve(int u,int fa)
{
    int i,m=val[u].size(),t;
    if(m==1 && val[u][0].second==fa) return printf("? %d\n",u),fflush(stdout),scanf("%d",&u),u;
    // ins[u]=1;
    for(i=0;i<m;i++)
        if(val[u][i].second!=fa)
            if((t=solve(val[u][i].second,u))!=u)
                return /*ins[u]=0,*/t;
    // ins[u]=0;
    return u;
}
int main()
{
    int i,cur,j,ans,s,t,u;
    scanf("%d",&n);
    if(n==1) { printf("0\n! 1 1\n"),fflush(stdout); return 0; }
    for(tot=0,i=1;i<=n;i++) he[i]=-1; // ins[i]=0;
    for(i=1;i<n;i++) scanf("%d%d",&s,&t),add_edge(s,t),add_edge(t,s);
    /*tot=0,*/dfs1(1,-1),dfs2(1,-1);
    for(i=1,ans=0;i<=n;ans=max(ans,cur),i++)
        if(val[i].size()==1) cur=val[i][0].first;
        else
            for(cur=0,j=1;j<(int)val[i].size();j++)
                cur=max(cur,j-1+val[i][j].first+val[i][0].first);
    printf("%d\n",ans),fflush(stdout);
    scanf("%d",&u),s=t=u;
    // for(i=1;i<=n;i++) assert(!ins[i]);
    // ins[u]=1;
    for(i=0;i<(int)val[u].size() && t==u;i++)
        ((s==u)?s:t)=solve(val[u][i].second,u);
    // ins[u]=0;
    printf("! %d %d\n",s,t),fflush(stdout);
    return 0;
}