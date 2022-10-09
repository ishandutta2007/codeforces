//bad_solution
#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
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
const int maxn = (1 << 24);
int dp[maxn + 5], n;
string s;
int main()
{
	int all = maxn -1;
	boost;
	cin >> n;
	FOR(i, 1, n)
	{
		cin >> s;
		int val = 0;
		for (int j=0; j < 3; ++j) val |= (1 << (s[j] - 'a'));
		dp[val]++;
	}
	
	FOR(j, 0, 23)
		FOR(i, 0, maxn-1)
		if (i & (1 << j)) dp[i] += dp[i - (1 << j)];
		
	ll wyn = 0;
	FOR(i, 0, maxn-1) wyn ^= (n - dp[i]) * (n - dp[i]);
	cout << wyn;
}