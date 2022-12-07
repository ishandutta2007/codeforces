#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <deque>
#include <bitset>
#include <algorithm>
  
using namespace std;
  
const double eps=1e-10;
const double pi=3.1415926535897932384626433832795;
const double eln=2.718281828459045235360287471352;
  
#define LL long long
#define IN freopen("in.txt", "r", stdin)
#define OUT freopen("out.txt", "w", stdout)
#define scan(x) scanf("%d", &x)
#define scan2(x, y) scanf("%d%d", &x, &y)
#define scan3(x, y, z) scanf("%d%d%d", &x, &y, &z)
#define sqr(x) (x) * (x)
#define pr(x) printf("Case %d: ",x)
#define prn(x) printf("Case %d:\n",x)
#define prr(x) printf("Case #%d: ",x)
#define prrn(x) printf("Case #%d:\n",x)
#define lowbit(x) (x&(-x))
  
const LL mod=1000000007;
const int maxn=100005;

LL er[505];
LL ans=0;

struct gauss
{
    LL cnt[66][2];
    LL num[66];
    LL s,tot;
    
    void init()
    {
        memset(cnt,0,sizeof(cnt));
        memset(num,0,sizeof(num));
        s=tot=0;
    }

    void add(LL w)
    {
        s|=w;
        for(int i=60;i>=0;i--)
        {
            if(w&((1ll)<<i))
                if(num[i]==0)
                {
                    num[i]=w;
                    tot++;
                    break;
                }
            w=min(w,w^num[i]);
        }
    }

    void insert(LL w)
    {
        for(int i=0;i<=60;i++)cnt[i][(w>>i)&1]++;
    }

    void cal()
    {
        for(int i=0;i<=60;i++)
        {
            if(s&((1ll)<<i))
                ans=(ans+ ((cnt[i][0]+cnt[i][1])*(cnt[i][0]+cnt[i][1]-1)/2)%mod * er[i+tot-1])%mod;
            else 
                ans=(ans+ (cnt[i][0]*cnt[i][1]%mod) * er[i+tot])%mod;
        }
    }
}what;

struct edge
{
    int to;
    LL cost;
    edge(int to=0,LL cost=0):to(to),cost(cost){}
};

vector<edge> g[maxn];
LL dep[maxn];
bool vis[maxn];
int n,m,i;

void dfs(int u,int fat,LL w)
{
    vis[u]=true;
    dep[u]=w;
    what.insert(w);
    for(unsigned int i=0;i<g[u].size();i++)
    {
        edge now=g[u][i];
        if(now.to==fat)continue;
        if(vis[now.to])
        {
            what.add(dep[u]^dep[now.to]^now.cost);
            continue;
        }
        dfs(now.to,u,w^now.cost);
    }
}

int main()
{
    ans=0;er[0]=1;
    for(i=1;i<=500;i++)er[i]=(er[i-1]*2)%mod;
    memset(vis,0,sizeof(vis));
    memset(dep,0,sizeof(dep));
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        int x,y;
        LL co;
        scanf("%d %d %I64d",&x,&y,&co);
        g[x].push_back(edge(y,co));
        g[y].push_back(edge(x,co));
    }
    for(i=1;i<=n;i++)
        if(!vis[i])
        {
            what.init();
            dfs(i,0,0);
            what.cal();
        }
    printf("%I64d",ans);
    return 0;;
}