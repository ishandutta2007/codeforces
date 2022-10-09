#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 100100
int n, m, k;
ll dp[5010][5010], pref[5010];
int t[5010];
ll suma(int a, int b) {
	return pref[b] - pref[a-1];
}
int main()
{
	cin >> n >> m >> k;
	for (int i=1; i<=n; ++i) cin >> t[i], pref[i] = pref[i-1] + t[i];
	dp[0][0] = 0;
	for (int i=m; i<=n; ++i)
	{
		for (int j=0; j<=k; ++j) dp[i][j] = max(dp[i][j], dp[i-1][j]);
		ll sum = suma(i - m + 1, i);
		for (int j=0; j<k; ++j)
		  dp[i][j+1] = max(dp[i][j+1], dp[i-m][j] + sum);
	}
	cout << dp[n][k];
}