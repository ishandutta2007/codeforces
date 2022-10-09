#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
#define eb emplace_back
#define OUT(x) {cout << x; exit(0); }
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define scanf(...) scanf(__VA_ARGS__)?:0
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair <int, int> PII;
typedef pair <int, int> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef pair <ld, ld> PLD;
typedef pair <PLD, ld> PLDD;
typedef pair <PLL, ll> PLLL;
typedef unsigned int ui;
const int inf = 1e9+9;
const int mod = 1e9+7;
const ll MOD = 1e9+696969;
const long long INF = (ll)1e18+3;
int n, m, a, b, c, DL = 0, CC = 0, T;
#define maxn 1000100
int f[maxn];
ll sum[maxn], ans[maxn], zap[maxn], t[maxn];
bool jest[maxn];
inline int find(int a) {
	if (f[a] == a) return f[a];
	f[a] = find(f[a]);
	return f[a];
}
ll MAX = 0;

inline void lacz(int a, int b) {
	int fa = find(a), fb = find(b);
	f[fa] = fb;
	sum[fb] += sum[fa];
	MAX = max(MAX, sum[fb]);
}

int main() {
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> t[i];
	FOR(i, 1, n) cin >> zap[i];
	MAX = 0;
	for (int i=n; i>0; --i) {
		int kt = zap[i];
		ans[i] = MAX;
		jest[kt] = 1;
		sum[kt] = t[kt];
		MAX = max(MAX, sum[kt]);
		
		f[kt] = kt;
		if (kt <= n && jest[kt + 1]) lacz(kt, kt + 1);
		if (kt > 1 && jest[kt - 1]) lacz(kt - 1, kt);
	}
	
	FOR(i, 1, n) cout << ans[i] << "\n";
}