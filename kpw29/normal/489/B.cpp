#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 4010
int n, m, a, b, c;
int dp[110][110];
int t1[110], t2[110];
int main()
{
	cin >> n;
	for (int i=1; i<=n; ++i) cin >> t1[i];
	cin >> m;
	for (int i=1; i<=m; ++i) cin >> t2[i];
	sort(t1+1, t1+n+1);
	sort(t2+1, t2+m+1);
	for (int i=1; i<=n; ++i)
	  for (int j=1; j<=m; ++j)
	  {
	  	dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	  	if (abs(t1[i] - t2[j]) <= 1) dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
	  }
	cout << dp[n][m];
}