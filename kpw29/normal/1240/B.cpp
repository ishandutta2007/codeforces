#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost {ios_base::sync_with_stdio(false); cin.tie(0); }
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define REYNA(i,a,b) for(int i=(a);i<(b);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int mod = 1e9+7;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 1001000;
string s;
int n, m, k, a, b;
int tab[maxn];
int dp[maxn];
int LAST[maxn], PIE[maxn];
int dr[maxn];

inline void add(int p, int val) {
	for (; p <= n; p += p & (-p)) dr[p] = max(dr[p], val);
}

inline int get(int p) {
	int res = 0;
	for (; p > 0; p -= p & (-p)) res = max(res, dr[p]);
	return res;
}
	

int main()
{
	boost;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n;
		FOR(i, 0, n) LAST[i] = 0, PIE[i] = 0, dr[i] = 0, dp[i] = 0;
		FOR(i, 1, n) {
			cin >> tab[i];
			LAST[tab[i]] = i;
			if (!PIE[tab[i]]) PIE[tab[i]] = i;
		}
		
		int dist = 0, opt = 0, ost = 0;
		FOR(i, 1, n) {
			if (!PIE[i]) continue;
			++dist;
			
			if (LAST[ost] < PIE[i]) dp[LAST[i]] = 1 + dp[LAST[ost]];
			else dp[LAST[i]] = 1;
			opt = max(opt, dp[LAST[i]]);
			//cout << i << ' ' << dp[LAST[i]] << endl;
			add(LAST[i], dp[LAST[i]]);
			
			ost = i;
		}
		
		cout << dist - opt << "\n";
		
	}
}