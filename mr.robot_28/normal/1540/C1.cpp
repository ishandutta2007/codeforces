#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define int long long
#define sz(a) (int)a.size()
#define ll long long
const int mod = 1e9 + 7;
const int N = 200;
const int A = 200;
int n, q;
const int N1 = 1e5 + 100;
int c[N], b[N], x[N1], sumpref_c[N], sumpref_b[N];
int dp[N][N * A];
int solve(int x)
{
	dp[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int sumprefA = 0; sumprefA <= sumpref_c[i]; sumprefA++)
		{
			dp[i][sumprefA] = 0;
			if(sumprefA < sumpref_b[i - 1] + i * x)
			{
				continue;
			}
			for(int a = 0; a <= c[i] && a <= sumprefA; a++)
			{
				dp[i][sumprefA] += dp[i - 1][sumprefA - a];
				if(dp[i][sumprefA] >= mod)
				{
					dp[i][sumprefA] -= mod;
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= sumpref_c[n]; i++)
	{
		ans += dp[n][i];
		if(ans >= mod)
		{
			ans -= mod;
		}
	}
	return ans;
}
signed main()
{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		cin >> c[i];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		cin >> b[i];
	}
	cin >> q;
	for(int i = 1; i <= q; i++)
	{
		cin >> x[i];
	}
	for(int i = 1; i <= n; i++)
	{
		sumpref_c[i] = sumpref_c[i - 1] + c[i];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		sumpref_b[i] = sumpref_b[i - 1] + b[i];
	}
	for(int i = 1; i <= n - 1; i++)
	{
		sumpref_b[i] = sumpref_b[i - 1] + sumpref_b[i];
	}
	int all = 1;
	for(int i = 1; i <= n; i++)
	{
		all = 1LL * all * (c[i] + 1) % mod;
	}
	vector <int> xs;
	for(int i = 1; i <= q; i++)
	{
		xs.push_back(x[i]);
	}
	map <int, int> mp;
	sort(xs.begin(), xs.end());
	xs.resize(unique(xs.begin(), xs.end()) - xs.begin());
	for(auto ix : xs)
	{
		bool nosol = 0;
		for(int i = 1; i <= n; i++)
		{
			if(sumpref_b[i - 1] + i * ix > sumpref_c[i])
			{
				nosol = 1;
			}
		}
		if(nosol)
		{
			mp[ix] = 0;
			continue;
		}
		bool allsol = 1;
		for(int i = 1; i <= n; i++)
		{
			if(sumpref_b[i - 1] + i * ix > 0)
			{
				allsol = 0;
			}
		}
		if(allsol)
		{
			mp[ix] = all;
			continue;
		}
		int s = solve(ix);
		mp[ix] = s;
		if(s == all)
		{
			break;
		}
	}
	for(int i = 1; i <= q; i++)
	{
		cout << mp[x[i]] << "\n";
	}
	return 0;
}