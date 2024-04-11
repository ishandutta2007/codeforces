#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define B 1
#define W -1
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5,INF=1e9;
const ll mod=1e9+7,INFLL=1e18;

bool vis[MAX];
int n,q;
int h[MAX],num[MAX];
ll weight[MAX];
double res=0,d;
vector<vi> adj;
vii ed;
vi wt;

int dfs(int u)
{
    int res=1;
    ff(i,0,adj[u].size()-1)
    {
        int v=adj[u][i];
        if(!vis[v])
        {
            vis[v]=1;
            h[v]=h[u]+1;
            res+=dfs(v);
        }
    }
    return num[u]=res;
}

void init(void)
{
    ed.pb(mp(0,0));
    wt.pb(0);
    cin>>n;
    adj.assign(n+1,vi());
    d=1.0*n*(n-1)/6.0;
    ff(i,1,n-1)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].pb(v);
        adj[v].pb(u);
        ed.pb(mp(u,v));
        wt.pb(w);
    }
}

void process(void)
{
    vis[1]=1;
    num[1]=dfs(1);
    ff(i,1,ed.size()-1)
    {
        int u=ed[i].fi,v=ed[i].se;
        if(h[u]>h[v]) weight[i]=1LL*(n-num[u])*num[u];
        else weight[i]=1LL*(n-num[v])*num[v];
    }
    ff(i,1,n) res+=1.0*wt[i]*weight[i];
    cin>>q;
    ff(i,1,q)
    {
        int p,nw;
        cin>>p>>nw;
        res-=1.0*weight[p]*(wt[p]-nw);
        wt[p]=nw;
        printf("%.9lf\n",res/d);
    }
}

int main(void)
{
    init();
    process();
    return 0;
}