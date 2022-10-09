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
const int maxn = 500100;
int tab[maxn];
int n, m, k, a, b, c;

bool wrong[maxn];
int A[maxn], B[maxn], C[maxn];

int f[maxn], sz[maxn];

vector <PIP> changes;

inline int find(int x) {
	while (f[x] != x) x = f[x];
	return x;
}

inline bool lacz(int x, int y, int Time, bool par) {
	x = find(x), y = find(y);
	if (x == y) return 1; //byly w jednej spojnej
	if (!par) return 0;
	if (sz[x] > sz[y]) swap(x, y);
	changes.pb(mp(Time, mp(y, sz[y])));
	changes.pb(mp(Time, mp(-x, f[x])));
	sz[y] += sz[x];
	f[x] = y;
	return 0;
}

inline void przywroc(int Time) { //wszystko ma byc <= Time
	while (!changes.empty() && changes.back().e1 > Time) {
		int x = changes.back().e2.e1;
		if (x > 0) sz[x] = changes.back().e2.e2;
		else f[-x] = changes.back().e2.e2;
		changes.pop_back();
	}
}
bool ans[maxn];
vector <PII> waga[maxn];
vector <int> zap[maxn];
vector <int> kraw[maxn];

int ki[maxn];

int main()
{
	boost;
	cin >> n >> m;
	int mx = 0;
	FOR(i, 1, m) 
	{
		cin >> A[i] >> B[i] >> C[i];
		kraw[C[i]].pb(i);
		mx = max(mx, C[i]);
	}

	int q;
	cin >> q;
	FOR(z, 1, q)
	{
		cin >> ki[z];
		zap[z].resize(ki[z]);
		FOR(i, 0, ki[z]-1) {
			cin >> zap[z][i];
			waga[C[zap[z][i]]].push_back(mp(z, zap[z][i]));
		}
	}
	
	FOR(i, 1, n) f[i] = i, sz[i] = 1;
	//dsu is null
	for (int w=1; w<=mx; ++w)
	{
		for (auto u : waga[w])
			if (lacz(A[u.e2], B[u.e2], w + u.e1, 0)) {
				wrong[u.e1] = 1;
			}
		
		int size = (int)waga[w].size();
		for (int i=0; i<size; ++i)
		{
			if (i > 0 && waga[w][i].e1 == waga[w][i-1].e1) continue;
			int j = i;
			while (j + 1 < size && waga[w][i].e1 == waga[w][j + 1].e1) ++j;
			for (int kk = i; kk <= j; ++kk)
			{
				if (lacz(A[waga[w][kk].e2], B[waga[w][kk].e2], w + 1, 1)) wrong[waga[w][i].e1] = 1;
			}
			przywroc(w);
		}
		for (auto u : kraw[w]) lacz(A[u], B[u], w, 1);
	}

	FOR(i, 1, q)
		if (!wrong[i]) cout << "YES\n";
		else cout << "NO\n";
}