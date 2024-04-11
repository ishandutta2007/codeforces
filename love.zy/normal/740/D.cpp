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

struct tree
{
    LL num,dis;
    vector<int> son;
}tr[maxn];

int i,j,k,m,n;
int ans[maxn];
int st[maxn];
LL dist[maxn];

void dfs(int x,int now,LL d)
{
    st[now]=x;dist[now]=d;
    int t=lower_bound(dist+1,dist+now+1,d-tr[x].num)-dist-1;
    ans[st[t]]--;ans[x]++;
    for(unsigned int i=0;i<tr[x].son.size();i++)
    {
        int v=tr[x].son[i];
        dfs(v,now+1,d+tr[v].dis);
        ans[x]+=ans[v];
    }
}

int main()
{
    scan(n);dist[0]=-1ll<<60;
    for(i=1;i<=n;i++)scanf("%lld",&tr[i].num);
    for(i=1;i<=n-1;i++)
    {
        scanf("%d",&j);
        scanf("%lld",&tr[i+1].dis);
        tr[j].son.push_back(i+1);
    }
    dfs(1,1,0);
    for(i=1;i<=n;i++)
    {
        if(i>1)printf(" ");
        printf("%d",ans[i]-1);
    }
    return 0;
}