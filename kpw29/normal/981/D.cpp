#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define REYNA(i, a, b) for (int i=(a); i<(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PII, PII> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int maxn = 1000100;
int n, m, c, b;
ll t[51];

ll AND[51][51];

vector <ll> dp[51][51];

int main()
{
	cin >> n >> b;
	FOR(i, 1, n) cin >> t[i];
	FOR(i, 1, n)
	{
		ll RET = 0;
		FOR(j, i, n)
		{
			RET = (RET + t[j]);
			AND[i][j] = RET;
		}
	}
	
	dp[0][0].pb((1LL << 62) - 1);
	for (int i=1; i<=n; ++i)
		for (int k = b; k > 0; --k)
		{
			for (int j=1; j<=i; ++j)
			{
				for (auto &u : dp[j-1][k-1]) dp[i][k].pb(u & AND[j][i]);
			}
			sort(dp[i][k].begin(), dp[i][k].end());
			dp[i][k].resize(distance(dp[i][k].begin(), unique(dp[i][k].begin(), dp[i][k].end())));
		}
			
	ll tmp = 0;
	for (auto u : dp[n][b]) tmp = max(tmp, u);
	cout << tmp;
}