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
#define maxn 2001000
int a, b, c, n, m, k;
int dp[200010];
int main()
{
	boost;
	cin >> n >> m;
	dp[0] = 1;

	for (int i=1; i<=n; ++i) {
	  cin >> a;
	  for (int i=m+1000; i>=0; --i)
	    if (dp[i]) {
			if (dp[i + a] == 0) dp[i + a] =dp[i] + 1;
			else dp[i + a] = min(dp[i + a], dp[i] + 1);
		}
	}
	int wyn = inf;
	for (int i=1; i<=m+1000; ++i)
	  if (dp[i] && i >= m) wyn = min(wyn, dp[i]);
	cout << wyn - 1;
}