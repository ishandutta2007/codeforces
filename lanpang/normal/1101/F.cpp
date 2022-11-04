#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , q , s;
LL a[maxn] , dp[410][410] , ans;
struct mmp{
	int f , r;
	LL c;
}p;
vector<mmp> v[maxn];

int main()
{
	int i , j , k , l;
	cin >> n >> q;
	for (i = 1 ; i <= n ; i++)
		scanf("%I64d",&a[i]);
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%I64d%d",&s,&p.f,&p.c,&p.r);
		v[s].push_back(p);
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = i ; j <= n ; j++)
			dp[j][0] = a[j]-a[i];
		for (k = 1 ; k <= n ; k++)
		{
			for (j = i ; j <= n ; j++)
				dp[j][k] = dp[j][k-1];
			l = n;
			for (j = n ; j >= i ; j--)
			{
				while (l > i && max(dp[l][k-1],a[j]-a[l]) >= max(dp[l-1][k-1],a[j]-a[l-1])) l--;
				dp[j][k] = min(dp[j][k],max(dp[l][k-1],a[j]-a[l]));
			}
		}
		for (auto j: v[i])
		{
			ans = max(ans,dp[j.f][j.r]*j.c);
			//cout << i << " " << j.f << " " << j.c << " " << j.r << " : " << dp[j.f][j.r]*j.c << "\n";
		}
	}
	cout << ans << "\n";
	return 0;
}