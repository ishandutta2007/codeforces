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
#define lc o << 1
#define rc o << 1 | 1
#define lowbit(x) (x&(-x))
#define min(x,y) ((x)<(y)?(x):(y))
#define max(x,y) ((x)>(y)?(x):(y))
  
const int maxn=200005;
const LL mod=1e9+7;
int a[maxn];
bool vis[maxn];
int cnt[maxn],bcc[maxn],num[maxn];
int i,j,k,l,m,n;

void dfs(int x,int y)
{
	vis[x]=true;
	num[x]=y;
	bcc[x]=m;
	if(!vis[a[x]])dfs(a[x],y+1);
	else
	{
		if(bcc[a[x]]==m)cnt[m]=y-num[a[x]]+1;
	}
}

LL pow_mod(int x,int y)
{
	LL ans=1,tot=x;
	while(y>0)
	{
		if(y&1)ans=(ans*tot)%mod;
		tot=(tot*tot)%mod;
		y=y>>1;
	}
	return ans;
}

int main()
{
	scan(n);
	for(i=1;i<=n;i++)scan(a[i]);
	memset(vis,0,sizeof(vis));
	memset(cnt,0,sizeof(cnt));
	memset(bcc,0,sizeof(bcc));
	m=0;
	for(i=1;i<=n;i++)
		if(!vis[i])
		{
			m++;
			dfs(i,1);
		}
	LL ans=1,tot=0;
	for(i=1;i<=m;i++)
	{
		if(cnt[i]==0)continue;
		tot+=cnt[i];
		LL temp=pow_mod(2,cnt[i]);
		temp=(temp-2)%mod;
		ans=(ans*temp)%mod;
	}
	ans=(ans*pow_mod(2,n-tot))%mod;
	printf("%lld",ans);
    return 0;
}