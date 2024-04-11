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
const int maxn = 300100;
int n, k, m, a, b, c, A[maxn], B[maxn], parent[maxn];
vector <int> v[maxn];
int TIME, low[maxn], pre[maxn];
vector <PII> przedzialy;
bool odw[maxn];
vector <int> graf[maxn];

void dfs(int x, int par) {
	odw[x] = 1;
	parent[x] = par;
	pre[x] = ++TIME;
	low[x] = pre[x];
	for (auto u : v[x])
		if (!odw[u]) dfs(u, x), low[x] = min(low[x], low[u]);
		else if (u != par) low[x] = min(low[x], pre[u]);
}
int MAKS, MIN, ILE;

void przejdz(int x) {
	odw[x] = 1;
	for (auto u : graf[x])
		if (!odw[u]) przejdz(u);
	MAKS = max(MAKS, x);
	MIN = min(MIN, x);
	ILE++;
}

inline ll F(ll x) {
	return x * (x + 1) / 2;
}
vector <PII> stos;
PII tab[maxn];
int BIG;
void wywal() {
	sort(przedzialy.begin(), przedzialy.end());
	
	for (auto u : przedzialy) {
		while (!stos.empty() && stos.back().e2 >= u.e2) stos.pop_back();
		stos.pb(u);
	}
	
	tab[0] = mp(0, 0);
	int sz = stos.size();
	for (int i=0; i<sz; ++i) tab[i + 1] = stos[i];
	BIG = sz + 1;
	tab[BIG] = mp(n + 1, n + 1);
}
ll pref[maxn];
ll fun(PII a, PII b) {
	assert(a.e1 != b.e1);
	ll part1 = a.e2 - a.e1;
	ll part2 = F(b.e2 - a.e1 - 1) - F(b.e2 - a.e1 - 1 - (b.e1 - a.e1 - 1));
	return part1 + part2;
}
int l, r;

ll answerQuery() {
	int pocz = -1, kon = -1;
	cin >> l >> r;
	int x = 0, y = BIG;
	while (x < y) {
		int sr = (x + y) / 2;
		if (tab[sr].e1 < l) x = ++sr;
		else y = sr;
	}
	pocz = x;
	x = 0, y = BIG;
	while (x < y) {
		int sr = (x + y) / 2 + 1;
		if (tab[sr].e2 > r) y = --sr;
		else x = sr;
	}
	kon = x;
	if (pocz > kon/* || pocz == 0 || kon == BIG*/) return F(r - l + 1); //mozemy wybrac cokolwiek
	assert(kon >= 1);
	ll na_przedziale = pref[kon - 1] - pref[pocz - 1];
	ll na_poczatku = fun(mp(l - 1, l - 1), tab[pocz]), na_koncu = fun(tab[kon], mp(r + 1, r + 1));
	return na_przedziale + na_poczatku + na_koncu;
}

int main()
{
	boost;
	cin >> n >> m;
	FOR(i, 1, m) {
		cin >> a >> b;
		v[a].pb(b);
		v[b].pb(a);
		A[i] = a; B[i] = b;
	}
	
	FOR(i, 1, n)
		if (!odw[i]) dfs(i, i);
	FOR(i, 1, m) {
		a = A[i], b = B[i];
		if (pre[a] > pre[b]) swap(a, b);
		if (low[b] != pre[b]) graf[a].pb(b), graf[b].pb(a);
	}
	
	fill(odw, odw+n+10, false);
	FOR(i, 1, n) {
		if (!odw[i]) {
			MAKS = -1; MIN = n + 1;
			ILE = 0;
			przejdz(i);
			if (ILE > 1) przedzialy.pb(mp(MIN, MAKS));
		}
	}
	
	wywal();
	
	for (int i=1; i<=BIG; ++i) pref[i] = pref[i-1] + fun(tab[i], tab[i+1]);
	int q;
	cin >> q;
	while (q--) cout << answerQuery() << "\n";
}