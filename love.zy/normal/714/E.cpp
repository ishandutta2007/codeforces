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
  
const int maxn=3005;
const LL inf=1e18;

LL dp[maxn][maxn];
LL a[maxn],b[maxn];
int i,j,n;
LL m;

LL tt(LL x)
{
	return x<0?-x:x;
}

int main()
{
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		a[i]-=i;
		b[i]=a[i];
	}
	sort(b+1,b+n+1);
	for(i=1;i<=n;i++)
	{
		m=inf;
		for(j=1;j<=n;j++)
		{
			m=min(m,dp[i-1][j]);
			dp[i][j]=m+tt(a[i]-b[j]);
		}
	}
	m=inf;
	for(i=1;i<=n;i++)m=min(m,dp[n][i]);
	printf("%lld",m);
    return 0;
}