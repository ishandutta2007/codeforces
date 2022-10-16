#include<bits/stdc++.h>
#define f(i,n) for(int i=1;i<=n;i++)
#define F(i,n) for(int i=n;i>=1;i--)
#define FF(i,a,b) for(int i=a;i>=b;i--)
#define ff(i,a,b) for(int i=a;i<=b;i++)
#define pb push_back
#define fi first
#define se second
#define B 1
#define W -1
typedef long long ll;
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

const int MAX=1e5+5;
const ll mod=1e9+7,INF=1<<30;

int n,m;
bool g[3005][3005]={0};
vector<vi> adj;

void init(void)
{
    scanf("%d%d",&n,&m);
    adj.assign(n+1,vi());
    f(i,m)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x][y]=1;
        adj[x].pb(y);
    }
}

void process(void)
{
    int res=0;
    f(i,n) f(j,n) if(i!=j)
    {
        int cnt=0;
        if(!adj[i].empty()) ff(k,0,adj[i].size()-1)
        {
            int u=adj[i][k];
            if(g[i][u]&&g[u][j]) cnt++;
        }
        res+=(cnt*(cnt-1))/2;
    }
    printf("%d",res);
}

int main(void)
{
    init();
    process();
    return 0;
}