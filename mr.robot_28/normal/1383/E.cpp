#include<bits/stdc++.h>
 
using namespace std;
#define int long long
const int const1 = 1e9 + 7;
signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string s;
	cin >> s;
	int n = s.size();
	vector <int> dist(n);
	for(int i = 0; i < n; i++)
	{
		if(s[i] == '0')
		{
			if(i == 0)
			{
				dist[i] = 1;
			}
			else
			{
				dist[i] = dist[i - 1] + 1;
			}
		}
	}
	vector <int> dp(n + 2), nxt(n + 2, n);
	for(int i = n - 1; i >= 0; i--)
	{
		int a, b;
		if(nxt[0] < n)
		{
			a = dp[nxt[0]];
		}
		else
		{
			a = 0;
		}
		if(dist[i] + 1 < n)
		{
			b = dp[nxt[dist[i] + 1]];
		}
		else
		{
			b = 0;
		}
		dp[i] = (a + b);
		if(dist[i] <= dist.back())
		{
			dp[i]++;
		}
		dp[i] %= const1;
		nxt[dist[i]] = i;
	}
	int ans = n;
	if(nxt[0] < n)
	{
		ans = dp[nxt[0]] * (nxt[0] + 1) % const1;
	}
	cout << ans;
	return 0;
}