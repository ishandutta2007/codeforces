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
typedef long long ll;
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
#define maxn 2010
ll tab[maxn], dff, dp[maxn];
int n, k, m;
inline bool check(ll sr)
{
	FOR(i, 0, n) dp[i] = inf;
	dp[0] = 0; dp[1] = 0;
	FOR(i, 2, n)
	{
		dp[i] = i - 1;
		if (abs(tab[i] - tab[i - 1]) <= sr) dp[i] = dp[i - 1];
		for (int j=i-1; j>0; --j)
		{
			ll rozn = abs(tab[j - 1] - tab[i]);
			if (j == 1 || rozn <= sr * (i - j + 1)) dp[i] = min(dp[i], dp[j - 1] + i - j);
		}
	}
	
	FOR(i, 1, n)
		if (dp[i] + n - i <= k) return 1;
		
	return 0;
}

int main()
{
	boost;
	cin >> n >> k;
	FOR(i, 1, n) cin >> tab[i];
	FOR(i, 2, n) dff = max(dff, abs(tab[i] - tab[i - 1]));
	if (n == 1 || k >= n - 1) OUT(0);
	ll x = 0, y = dff;
	while (x < y)
	{
		ll sr = (x + y) / 2;
		if (!check(sr)) x = ++sr;
		else y = sr;
	}
	cout << x;
}