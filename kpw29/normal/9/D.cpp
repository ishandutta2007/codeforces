#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false);}
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef unsigned long long ll;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 150
ll dp[maxn][maxn];

int main()
{
	dp[0][0] = 1;
	dp[1][1] = 1;
	FOR(i, 2, 35)
	{
		FOR(wys, 1, i)
			FOR(h1, 0, 35)
				FOR(h2, 0, 35) dp[i][1 + max(h1, h2)] += dp[wys - 1][h1] * dp[i - wys][h2];
	}
	int n, h;
	cin >> n >> h;
	ll ret = 0;
	for (int i=h; i<=35; ++i) ret += dp[n][i];
	cout << ret;
}