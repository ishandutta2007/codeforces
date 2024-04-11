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
  
const int maxn=200005;
vector<int> g[maxn];
vector<int> son[maxn];
bool vis[maxn];
LL a[maxn];
LL ans[maxn];
LL tot[maxn];
LL ma[maxn];
int n;
bool f=false;

bool cmp(LL x,LL y)
{
    return x>y;
}

void dfs(int x)
{
    vector<LL> q;
    vis[x]=true;
    for(unsigned int i=0;i<g[x].size();i++)
    {
        int v=g[x][i];
        if(!vis[v])
        {
            son[x].push_back(v);
            dfs(v);
        }
    }
    if(son[x].size()>=2)f=true;
    if(son[x].size()==0)
    {
        ans[x]=-1e17;
        tot[x]=a[x];
        ma[x]=tot[x];
        return;
    }
    LL sum=0,res=-1e17;
    for(unsigned int i=0;i<son[x].size();i++)
    {
        sum+=tot[son[x][i]];
        res=max(res,ma[son[x][i]]);
    }
    tot[x]=sum+a[x];
    ma[x]=max(res,tot[x]);
    ans[x]=-1e17;
    q.clear();
    for(unsigned int i=0;i<son[x].size();i++)
    {
        q.push_back(ma[son[x][i]]);
        ans[x]=max(ans[x],ans[son[x][i]]);
    }
    sort(q.begin(),q.end(),cmp);
    if(q.size()>=2)ans[x]=max(ans[x],q[0]+q[1]);
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1);
    if(!f){printf("Impossible");return 0;}
    printf("%lld\n",ans[1]);
    return 0;
}