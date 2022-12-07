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

const int maxn=1005;

int i,j,k,l,m,n,w,sum;
struct hos
{
    int w,b;
}dat[maxn],tot[maxn];
vector<int> g[maxn];
int fat[maxn],ans[maxn][1005];
int vis[maxn];

int find(int now)
{
    if(fat[now]==now)return now;
    else return fat[now]=find(fat[now]);
}

int main()
{
    scanf("%d%d%d",&n,&m,&w);
    for(i=1;i<=n;i++)scanf("%d",&dat[i].w);
    for(i=1;i<=n;i++)scanf("%d",&dat[i].b);
    for(i=1;i<=n;i++)fat[i]=i;
    for(i=1;i<=m;i++)
    {
        scanf("%d%d",&j,&k);
        int x=find(j),y=find(k);
        if(x==y)continue;
        fat[x]=fat[y];
    }
    sum=0;
    for(i=1;i<=n;i++)
    {
        k=find(i);
        if(vis[k]==0)vis[k]=++sum;
        g[vis[k]].push_back(i);
        tot[vis[k]].b+=dat[i].b;
        tot[vis[k]].w+=dat[i].w;
    }
    for(i=1;i<=sum;i++)
    {
        for(j=0;j<=w;j++)ans[i][j]=ans[i-1][j];
        for(j=tot[i].w;j<=w;j++)
            ans[i][j]=max(ans[i][j],ans[i-1][j-tot[i].w]+tot[i].b);
        for(unsigned int t=0;t<g[i].size();t++)
        {
            k=g[i][t];
            for(j=dat[k].w;j<=w;j++)
                ans[i][j]=max(ans[i][j],ans[i-1][j-dat[k].w]+dat[k].b);
        }
    }
    int answer=0;
    for(i=0;i<=w;i++)answer=max(answer,ans[sum][i]);
    printf("%d",answer);
    return 0;
}