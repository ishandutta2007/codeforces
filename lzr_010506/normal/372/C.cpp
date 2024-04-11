#include <bits/stdc++.h>
using namespace std;
#define ll long long
int n, m, d, a[400], b[400], t[400], now, last, L, R, l, Q[150010];
long long dp[2][150010];
void f1(ll x)
{
	while(L <= R && Q[L] < x) L ++; 
} 
void f3(int l)
{
	while(L <= R && dp[last][Q[R]] < dp[last][l]) R --;
	Q[++ R] = l;
}
void f2(ll y)
{
	while(l <= n && l <= y) f3(l) , l ++;
}
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	for(int i = 1; i <= m; i ++)
		scanf("%d%d%d",&a[i],&b[i],&t[i]);
	for(int i = 1; i <= m; i ++)
	{
		now ^= 1;
		last =now ^ 1;
		L = l = 1, R = 0;
		for(int j = 1; j <= n; j ++)
		{
			ll k1 = j - 1ll * (t[i] - t[i - 1]) * d;
			ll k2 = j + 1ll * (t[i] - t[i - 1]) * d;
			f1(k1);
			f2(k2);
			dp[now][j] = dp[last][Q[L]] + b[i] - abs(a[i] - j);
		}
	}
	long long ans = -10101010;
	for(int i = 1; i <= n; i ++)
		ans = max(ans,dp[now][i]);
	cout << ans << endl;
	return 0;
}