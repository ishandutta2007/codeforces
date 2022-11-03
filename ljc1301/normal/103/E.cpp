// |U S_i|>=K
// ~ min cut
// s->i P[i]+M
// i->j j in S[i], inf
// j->t M
// M>>1
// ans=mincut-M*n
// Wrong!
// s->i -P[i]+M
// i->j j in S[i], inf
// j->t M
// ans=mincut+sumP-M*n
//   writing: 30min
// debugging: 15min
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=305;
const int maxv=maxn<<1;
const ll M=1e10;
const ll inf=0x3fffffffffffffffll;
struct EdgE
{
    int to,rev; ll cap;
    EdgE(int v,ll c,int r):to(v),cap(c),rev(r) { }
};
vector<EdgE> G[maxv];
vector<EdgE>::iterator it[maxv];
int n,a[maxn][maxn],m[maxn],b[maxn*maxn],tot,s,t,dis[maxv];
inline void add_edge(int u,int v,ll c)
{
    G[u].push_back(EdgE(v,c,(int)G[v].size())),
    G[v].push_back(EdgE(u,0,(int)G[u].size()-1));
}
queue<int> que;
inline void bfs()
{
    int u;
    vector<EdgE>::iterator it;
    for(u=0;u<=t;u++) dis[u]=-1;
    while(!que.empty()) que.pop();
    dis[s]=0,que.push(s);
    while(!que.empty())
    {
        u=que.front(),que.pop();
        for(it=G[u].begin();it!=G[u].end();++it)
            if(it->cap && dis[it->to]==-1)
                dis[it->to]=dis[u]+1,que.push(it->to);
    }
}
ll dfs(int u,ll cur)
{
    if(u==t) return cur;
    ll f;
    for(;it[u]!=G[u].end();++it[u])
        if(it[u]->cap && dis[it[u]->to]==dis[u]+1
            && (f=dfs(it[u]->to,min(cur,it[u]->cap))))
            return it[u]->cap-=f,G[it[u]->to][it[u]->rev].cap+=f,f;
    return 0;
}
int main()
{
    int i,j;
    ll ans,f;
    scanf("%d",&n);
    for(i=0,tot=0;i<n;i++)
        for(scanf("%d",&m[i]),j=0;j<m[i];j++)
            scanf("%d",&a[i][j]),b[tot++]=a[i][j];
    sort(b,b+tot),tot=unique(b,b+tot)-b;
    s=n<<1,t=s|1;
    for(i=0;i<=t;i++) G[i].clear();
    for(i=0,ans=0;i<n;i++)
        scanf("%d",&j),ans+=j-M,add_edge(s,i,-j+M),add_edge(i+n,t,M);
    for(i=0;i<n;i++)
        for(j=0;j<m[i];j++)
            add_edge(i,lower_bound(b,b+tot,a[i][j])-b+n,inf);
    for(;;)
    {
        if(bfs(),dis[t]==-1) break;
        for(i=0;i<=t;i++) it[i]=G[i].begin();
        while((f=dfs(s,inf))) ans+=f;
    }
    printf("%lld\n",ans);
    return 0;
}