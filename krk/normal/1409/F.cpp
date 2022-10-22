#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 205;
const ll Inf = 1000000000000000000ll;

int n, k;
string s;
string t;
ll dp[Maxn][Maxn][Maxn];

int main()
{
	cin >> n >> k;
	cin >> s;
	cin >> t;
	fill((ll*)dp, (ll*)dp + Maxn * Maxn * Maxn, -Inf);
	dp[0][0][0] = 0;
	for (int i = 0; i < n; i++)
		for (int a = 0; a <= i; a++)
			for (int l = 0; l <= k; l++) if (dp[i][a][l] >= 0) {
				// no upd
				int add = 0;
				if (s[i] == t[1]) add += a;
				int ni = i + 1, na = a, nl = l;
				if (s[i] == t[0]) na++;
				dp[ni][na][nl] = max(dp[ni][na][nl], dp[i][a][l] + add);
				// upd a
				add = 0;
				if (t[0] == t[1]) add += a;
				ni = i + 1, na = a + 1, nl = l + 1;
				dp[ni][na][nl] = max(dp[ni][na][nl], dp[i][a][l] + add);
				// upd b
				add = a;
				ni = i + 1, na = a, nl = l + 1;
				if (t[1] == t[0]) na++;
				dp[ni][na][nl] = max(dp[ni][na][nl], dp[i][a][l] + add);
			}
	ll res = 0;
	for (int a = 0; a <= n; a++)
		for (int l = 0; l <= k; l++)
			res = max(res, dp[n][a][l]);
	cout << res << endl;
    return 0;
}