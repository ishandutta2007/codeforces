#include <bits/stdc++.h>
using namespace std;
#define e1 first
#define e2 second
#define pb push_back
#define mp make_pair
#define boost ios_base::sync_with_stdio(false)
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
typedef pair <PLL, pair <int, ll> > PP;
typedef pair <PII, int> PPI;
typedef pair <int, PII> PIP;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 500100;
int n;
struct node {
	ll MIN, DODAJ;
	int SKAD;
};
int R;

node dr[(1 << 20) + 7];
int NEXT[maxn];
vector <int> dep[maxn];
int p[maxn];

inline void insert(int gdzie, int pocz, int kon, int x, int y, int ile) {
	if (x > y) return;
	if (x <= pocz && y >= kon) {
		dr[gdzie].MIN += ile;
		dr[gdzie].DODAJ += ile;
		return;
	}
	
	int sr = (pocz + kon) >> 1;
	if (x <= sr) insert(2 * gdzie, pocz, sr, x, y, ile);
	if (y > sr) insert(2 * gdzie + 1, sr + 1, kon, x, y, ile);
	if (dr[2 * gdzie].MIN < dr[2 * gdzie + 1].MIN) {
		dr[gdzie].MIN = dr[2 * gdzie].MIN;
		dr[gdzie].SKAD = dr[2 * gdzie].SKAD;
	}
	else {
		dr[gdzie].MIN = dr[2 * gdzie + 1].MIN;
		dr[gdzie].SKAD = dr[2 * gdzie + 1].SKAD;
	}
	
	dr[gdzie].MIN += dr[gdzie].DODAJ;
}

void rem(int pos, int step) {
	// << "Removing: " << pos << endl;
	p[pos] = step;
	for (auto u : dep[pos]) insert(1, 1, R, u, u, -1);
	if (NEXT[pos] != -1) insert(1, 1, R, pos + 1, NEXT[pos] - 1, -1);
	insert(1, 1, R, pos, pos, 5 * n);
}

void solve()
{
	cin >> n;
	FOR(i, 1, n) cin >> NEXT[i];
	R = 1;
	while (R <= n) R *= 2;
	FOR(i, 1, 2 * R + 5) {
		node tmp;
		tmp.MIN = 5 * n; tmp.DODAJ = 5 * n; tmp.SKAD = 0;
		dr[i] = tmp;
	}
	
	FOR(i, 1, n) {
		dr[i + R - 1].SKAD = i;
		dr[i + R - 1].MIN = dr[i + R - 1].DODAJ = 0;
	}
	
	for (int i = R - 1; i > 0; --i) {
		dr[i] = dr[2 * i];
	}

	FOR(i, 1, n) dep[i].clear();
	
	FOR(i, 1, n)
		if (NEXT[i] != -1) {
			int xd = NEXT[i];
			insert(1, 1, R, i + 1, xd - 1, 1);
			if (NEXT[i] != n + 1) {
				insert(1, 1, R, i, i, 1);
				dep[xd].pb(i);
			}
		}
	
	FOR(step, 1, n) {
		if (dr[1].MIN == 0) rem(dr[1].SKAD, n - step + 1);
		else {
			cout << "-1\n";
			return;
		}
	}
	
	FOR(i, 1, n) cout << p[i] << ' ';
	cout << "\n";
}
int T;
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--) solve();
}