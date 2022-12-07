/*****************************************
Author: lizi
Email: lzy960601@outlook.com
*****************************************/
  
#include<bits/stdc++.h>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define mp make_pair
#define pb push_back
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
#define fi first
#define se second
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn=200005;
struct edge
{
    int to;
    LL cost;
    bool operator < (const struct edge &p)const
    {return cost>p.cost;}
};
vector<edge> e[maxn];
int s,cs=0,n,m,fa[maxn][20],du[maxn],seq[maxn],cnt=0,sum[maxn],dep[maxn];
LL dis[maxn];
bitset<maxn> vis;
vi g[maxn],f[maxn],son[maxn];

void Dijkstra(int st)
{
    priority_queue<edge> q;
    while(!q.empty())q.pop();
    vis.reset();
    for(int i=1;i<=n;i++)dis[i]=1e18;
    dis[st]=0;q.push({st,0});
    while(!q.empty())
    {
        edge t=q.top();q.pop();
        int id=t.to;
        vis.set(id);
        for(edge p : e[id])
            if(dis[p.to]>dis[id]+p.cost)
            {
                dis[p.to]=dis[id]+p.cost;
                q.push({p.to,dis[p.to]});
            }
        while(!q.empty() && vis.test(q.top().to))q.pop();
    }
}

int lca(int x,int y)
{
    if(dep[x]>dep[y])swap(x,y);
    for(int i=cs;i>=0;i--)
        if(dep[fa[y][i]]>=dep[x])y=fa[y][i];
    if(x==y)return x;
    for(int i=cs;i>=0;i--)
        if(fa[y][i]!=fa[x][i]){x=fa[x][i];y=fa[y][i];}
    return fa[y][0];
}

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    int u=1;
    while(u<=n){u<<=1;cs++;}
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        e[x].pb({y,(LL)z});e[y].pb({x,(LL)z});
    }
    Dijkstra(s);
    for(int i=1;i<=n;i++)
        for(edge p : e[i])
            if(dis[i]+p.cost==dis[p.to])
            {
                g[i].pb(p.to);
                f[p.to].pb(i);
                du[p.to]++;
            }
    queue<int> q;
    while(!q.empty())q.pop();
    q.push(s);
    /*printf("f\n");
    for(int i=1;i<=n;i++)
    {
        printf("%d:",i);
        for(int p : f[i])printf(" %d",p);
        printf("\n");
    }*/
    while(!q.empty())
    {
        int x=q.front();q.pop();
        seq[++cnt]=x;
        if(x==s)dep[x]=1;
        else 
        {
            int fat=f[x][0];
            for(unsigned int i=1;i<f[x].size();i++)
                fat=lca(fat,f[x][i]);
            //printf("%d %d\n",x,fat);
            fa[x][0]=fat;dep[x]=dep[fat]+1;
            for(int i=1;(1<<i)<=n;i++)
                fa[x][i]=fa[fa[x][i-1]][i-1];
            son[fat].pb(x);
        }
        for(int p : g[x])
        {
            du[p]--;
            if(du[p]==0)q.push(p);
        }
    }
    int ans=0;
    for(int i=cnt;i>=2;i--)
    {
        int u=seq[i];
        sum[u]=1;
        for(int p : son[u])sum[u]+=sum[p];
        ans=max(ans,sum[u]);
    }
    printf("%d\n",ans);
    return 0;
}