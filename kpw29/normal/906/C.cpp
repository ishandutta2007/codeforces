#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define e1 first
#define e2 second
#define OUT(x) {cout << x; exit(0); }
#define scanf(...) scanf(__VA_ARGS__)?:0
#define boost ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long int ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, PII> PIP;
typedef pair <PII, int> PPI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
const int mod = 1e9+7;
const int inf = 1e9+9;
const int MOD = 1e9+696969;
const ll INF = 4e18 + 3;

const int maxn = 22;
int dp[(1 << maxn) + 5];
PII skad[(1 << maxn) + 5];
int adj[maxn + 5];
int n, m;
int main()
{
	boost;
	cin >> n >> m;
	if (n == 1 || 2 * m == n * (n - 1)) OUT(0);
	FOR(i, 1, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		adj[a] += (1 << b);
		adj[b] += (1 << a);
	}
	int pot = (1 << n);
	fill(dp, dp + pot + 3, inf);
	
	for (int i = 1; i < pot; ++i) {
		int edges = 0;
		for (int j=0; j < n; ++j)
			if (i & (1 << j)) edges += __builtin_popcount(adj[j] & i);
		int bc = __builtin_popcount(i);
		if (edges == bc * (bc - 1)) dp[i] = 0, skad[i] = mp(-1, -1);
		
		for (int j=0; j < n; ++j)
			if (i & (1 << j)) {
				int w = (adj[j] | i);
				if (dp[i] + 1 < dp[w]) {
					dp[w] = dp[i] + 1;
					skad[w] = mp(i, j);
				}
			}
	}

	vector <int> help;
	int zbior = pot - 1;
	while (skad[zbior].e1 != -1) {
		help.pb(skad[zbior].e2 + 1);
		zbior = skad[zbior].e1;
	}
	
	reverse(help.begin(), help.end());
	cout << (int)help.size() << endl;
	for (auto u : help) cout << u << ' ';
}