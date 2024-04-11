
/*****************************************
Author: lizi
Email: lzy960601@outlook.com
****************************************/
  
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

const int maxn=200005;
int ans[maxn],a[maxn];
vector<int> g[maxn],ys;
int n;

int gcd(int x,int y){return y==0?x:gcd(y,x%y);}

void DFS1(int u,int fa,int now)
{
    if(u==1)
    {
        ans[u]=a[u];
        now=0;
    }else
    {
        ans[u]=gcd(now,a[u]);
        now=ans[u];
    }
    for(int p : g[u])
        if(p!=fa)DFS1(p,u,now);
}

bool cmp(int x,int y){return x>y;}

void DFS2(int u,int fa,int now,bool t)
{
    if(!t && a[u]%now>0)return;
    ans[u]=max(ans[u],now);
    if(a[u]%now>0)t=false;
    for(int p : g[u])
        if(p!=fa)DFS2(p,u,now,t);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].pb(y);g[y].pb(x);
    }
    DFS1(1,0,0);
    for(int i=1;i*i<=a[1];i++)
    {
        if(a[1]%i>0)continue;
        ys.pb(i);
        if(i*i<a[1])ys.pb(a[1]/i);
    }
    sort(ys.begin(),ys.end(),cmp);
    for(int p : ys)DFS2(1,0,p,1);
    for(int i=1;i<=n;i++)printf("%d%c",ans[i],i==n?'\n':' ');
    return 0;
}