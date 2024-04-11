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

const int maxn=100005;
double ans,son[maxn],a[maxn];
int n,m,f[maxn];
vi g[maxn];

void DFS(int u,int fa)
{
    f[u]=fa;
    if(fa>=0)son[fa]+=1.0-a[u];
    for(int p : g[u])
        if(fa!=p)DFS(p,u);
    ans+=a[u]*son[u];
}

int main()
{
    scan(n);ans = 0;
    for(int i=0;i<n;i++)scanf("%lf",&a[i]);
    for(int i=1;i<n;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        g[x].pb(y);g[y].pb(x);
    }
    DFS(0,-1);
    scanf("%d",&m);
    while(m--)
    {
        int p;double s;
        scanf("%d%lf",&p,&s);
        double tmp=s-a[p];
        if(f[p]>=0)
        {
            ans-=a[f[p]]*tmp;
            son[f[p]]-=tmp;
        }
        ans+=tmp*son[p];
        a[p]=s;
        printf("%.8lf\n",ans+1.0-a[0]);
    }
    return 0;
}