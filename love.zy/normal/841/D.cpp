
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

typedef vector<int> vi;
const int maxn=300005;
int a[maxn],n,m;
struct edge
{
    int x,y;
    void read(){scanf("%d%d",&x,&y);}
    int ot(int p){return p==x?y:x;}
}e[maxn];
vi ans,g[maxn];
bool vis[maxn];

int DFS1(int u,int nu)
{
    vis[u]=true;
    int cnt=0;
    for(int p : g[u])
    {
        if(vis[e[p].ot(u)])continue;
        cnt+=DFS1(e[p].ot(u),p);
    }
    //printf("u:%d nu:%d cnt:%d\n",u,nu,cnt);
    if(a[u]>=0 && a[u]!=(cnt&1)){ans.pb(nu);return 1;}
    return 0;
}

int DFS2(int u,int nu)
{
    vis[u]=true;
    int cnt=0;
    if(a[u]==1)cnt++;
    for(int p : g[u])
    {
        if(vis[e[p].ot(u)])continue;
        cnt+=DFS2(e[p].ot(u),p);
    }
    if(cnt&1 && nu>0)ans.pb(nu);
    return cnt;
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=m;i++)
    {
        e[i].read();
        g[e[i].x].pb(i);
        g[e[i].y].pb(i);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i] || a[i]>=0)continue;
        DFS1(i,0);
    }
    for(int i=1;i<=n;i++)
    {
        if(vis[i] || a[i]==0)continue;
        if(DFS2(i,0)&1){printf("-1\n");return 0;}
    }
    sort(ans.begin(),ans.end());
    printf("%d\n",ans.size());
    for(int p : ans)printf("%d\n",p);
    return 0;
}