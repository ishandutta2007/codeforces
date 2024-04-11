#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> PII;
typedef pair<ll,ll> Pll;
typedef vector<int> VI;
typedef vector<PII> VII;
typedef pair<ll,ll>P;
#define N  200010
#define M  200010
#define fi first
#define se second
#define MP make_pair
#define pi acos(-1)
#define mem(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;i++)
#define per(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define lowbit(x) x&(-x)
#define Rand (rand()*(1<<16)+rand())
#define id(x) ((x)<=B?(x):m-n/(x)+1)
#define ls p<<1
#define rs p<<1|1

const ll MOD=1e9+7,inv2=(MOD+1)/2;
      double eps=1e-4;
      int INF=1<<30;
      ll inf=5e13;
      int dx[4]={-1,1,0,0};
      int dy[4]={0,0,-1,1};

int head[N],vet[N],nxt[N],fa[N],d[N],vis[N],tot;
ll a[N],ans;
P b[N];
vector<P> c[N];

int read()
{
   int v=0,f=1;
   char c=getchar();
   while(c<48||57<c) {if(c=='-') f=-1; c=getchar();}
   while(48<=c&&c<=57) v=(v<<3)+v+v+c-48,c=getchar();
   return v*f;
}

void add(int a,int b)
{
    nxt[++tot]=head[a];
    vet[tot]=b;
    head[a]=tot;
}

ll gcd(ll x,ll y)
{
    if(!y) return x;
    return gcd(y,x%y);
}

void dfs(int u,int fa)
{
    if(fa)
    {
        for(int i=0;i<c[fa].size();i++) c[u].push_back(c[fa][i]);
    }

    for(int i=0;i<c[u].size();i++) c[u][i].fi=gcd(c[u][i].fi,a[u]);
    int m=0;
    for(int i=0;i<c[u].size();i++) b[++m]=c[u][i];
    sort(b+1,b+m+1);
    c[u].clear();
    rep(i,1,m)
    {
        int now=(int)c[u].size()-1;
        if(now==-1||b[i].fi!=c[u][now].fi) c[u].push_back(b[i]);
         else c[u][now].se=(c[u][now].se+b[i].se)%MOD;
    }
    c[u].push_back(MP(a[u],1));
    for(int i=0;i<c[u].size();i++) ans=(ans+c[u][i].fi%MOD*c[u][i].se%MOD)%MOD;
    int e=head[u];
    while(e)
    {
        int v=vet[e];
        if(v!=fa) dfs(v,u);
        e=nxt[e];
    }
}
int main()
{
    int n=read();
    rep(i,1,n) scanf("%I64d",&a[i]);
    tot=0;
    rep(i,1,n) head[i]=0;
    rep(i,1,n-1)
    {
        int x=read(),y=read();
        add(x,y);
        add(y,x);
    }
    dfs(1,0);
    printf("%I64d\n",ans);
    return 0;
}