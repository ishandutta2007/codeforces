#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;
const int maxb = 21;

int ans[maxb][1 << maxb] , dp[maxn];

int a[maxn] , total , m;

string s[maxn];

int get(int a , int b)
{
	ll x = 0 , y = 0 , mx = 0;
	for(int i = 1; i <= m; i++)
	{
		x += (1 << (i - 1)) * s[a][m - i];
		y = (y * 2) + s[b][i - 1];
		if(x == y)
			mx = max((ll)i , mx);
	}
	return mx;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	for(int i = 0; i < maxb; i++)
		for(int j = 0; j < (1 << maxb); j++)
			ans[i][j] = 1e8;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> s[i];
		for(int j = 0; j < (int)s[i].size(); j++)
			a[i] = a[i] * 2 + (s[i][j] - '0');
	}
	m = s[1].size();
	dp[0] = m;
	ans[0][0] = m;
	for(int i = 2; i <= n; i++)
	{
		dp[i - 1] = 1e9;
		ll x = 0;
		for(int j = 0; j <= m; j++)
		{
			dp[i - 1] = min(dp[i - 1] , ans[j][x] + m - j + total);
			if(j < m)
				x = x * 2 + s[i][j] - '0';
		}
		total += m - get(i - 1 , i);
		dp[i - 1] = dp[i - 1] - total;
		x = 0;
		for(int j = 0; j <= m; j++)
		{
			ans[j][x] = min(ans[j][x] , dp[i - 1]);
			if(j < m)
				x += (1 << j) * (s[i - 1][m - j - 1] - '0');
		}
	}
	ll ans = 1e15;
	for(int i = 0; i < n; i++)
		ans = min(ans , (ll)dp[i]);
	ans += total;
	cout << ans << endl;
}