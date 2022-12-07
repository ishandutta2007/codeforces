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

const int maxn=300005;
int n,m,s,k;
vi g[maxn],v[maxn];
struct edge
{
    int x,y;
    int a1,a2;
    int ot(int u){return x==u?y:x;}
}e[maxn];
bool vis[maxn];
queue<int> q;

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int p,x,y;
        scanf("%d%d%d",&p,&x,&y);
        if(p==1)v[x].pb(y);
        else 
        {
            e[++k]={x,y,0,0};
            g[x].pb(k);g[y].pb(k);
        }
    }
    vis[s]=true;
    q.push(s);
    int cnt=0;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        cnt++;
        for(int p : v[x])
        {
            if(!vis[p])q.push(p);
            vis[p]=true;
        }
        for(int p : g[x])
        {
            if(e[p].a1!=0)continue;
            if(e[p].y==x)e[p].a1=2;else e[p].a1=1;
            if(!vis[e[p].ot(x)])q.push(e[p].ot(x));
            vis[e[p].ot(x)]=true;
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=k;i++)if(e[i].a1<=1)printf("+");else printf("-");
    printf("\n");
    cnt=0;
    for(int i=1;i<=n;i++)vis[i]=false;
    while(!q.empty())q.pop();
    q.push(s);vis[s]=true;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        cnt++;
        for(int p : v[x])
        {
            if(!vis[p])q.push(p);
            vis[p]=true;
        }
        for(int p : g[x])
        {
            if(e[p].a2!=0)continue;
            if(e[p].x==x)e[p].a2=2;else e[p].a2=1;
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=k;i++)if(e[i].a2<=1)printf("+");else printf("-");
    printf("\n");
    return 0;
}