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
#define FOR(i, a, b) for(int i=(a); i<=(b); ++i)
typedef long long ll;
typedef unsigned int ull;
typedef pair <int, int> PII;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ll, ll> PLL;
typedef pair <PII, PII> PP;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const ll INF = 1e18;
#define maxn 1010
int n, m, k, a, b, c;
vector <int> v[maxn];
int com[maxn], SKL;
bool odw[maxn];
int WAGA[maxn], ZYSK[maxn];
int wg[maxn], pi[maxn];
vector <int> sk[maxn];

void dfs(int x) {
	com[x] = SKL;
	odw[x] = 1;
	sk[SKL].pb(x);
	for (auto u : v[x])
	  if (!odw[u]) dfs(u);
}

int dp[maxn][maxn];
int main() {
	boost;
	cin >> n >> m >> k;
	FOR(i, 1, n) cin >> wg[i];
	FOR(i, 1, n) cin >> pi[i];
	SKL = 0;
	FOR(i, 1, m) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
	}
	
	FOR(i, 1, n)
	  if (!odw[i]) {
		  ++SKL;
		  dfs(i);
	  }

	FOR(i, 1, n)
	  WAGA[com[i]] += wg[i], ZYSK[com[i]] += pi[i];

	dp[0][0] = 0;
	FOR(i, 1, SKL) {
		FOR(zap, 0, k) {
			dp[i][zap] = dp[i-1][zap];
			if (zap - WAGA[i] >= 0) dp[i][zap] = max(dp[i][zap], dp[i-1][zap - WAGA[i]] + ZYSK[i]);
			for (auto u : sk[i]) {
				if (zap >= wg[u]) dp[i][zap] = max(dp[i][zap], dp[i-1][zap - wg[u]] + pi[u]);
			}
		}
	}
	
	int wyn = 0;
	FOR(i, 1, k) wyn = max(wyn, dp[SKL][i]);
	cout << wyn;
}