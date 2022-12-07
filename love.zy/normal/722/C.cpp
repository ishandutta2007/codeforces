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
  
const int maxn=100005;

bool vis[maxn];
int fat[maxn];
LL sum[maxn];
LL ans[maxn];
LL a[maxn];
int ord[maxn];

int i,j,k,l,m,n;
LL ma;

int find(int x)
{
    if(fat[x]==x)return x;
    else return fat[x]=find(fat[x]);
}

void hb(int x,int y)
{
    int xx=find(x);
    int yy=find(y);
    fat[yy]=fat[xx];
    sum[xx]+=sum[yy];
}

int main()
{
    memset(vis,0,sizeof(vis));
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    for(i=1;i<=n;i++)scanf("%d",&ord[i]);
    for(i=1;i<=n;i++)
    {
        sum[i]=a[i];
        fat[i]=i;
    }
    ma=0;
    for(i=n;i>=1;i--)
    {
        ans[i]=ma;
        int v=ord[i];
        vis[v]=true;
        ma=max(ma,sum[find(v)]);
        if(vis[v+1])
        {
            hb(v,v+1);
            ma=max(ma,sum[find(v)]);
        }
        if(vis[v-1])
        {
            hb(v,v-1);
            ma=max(ma,sum[find(v)]);
        }
    }
    for(i=1;i<=n;i++)printf("%lld\n",ans[i]);
    return 0;
}