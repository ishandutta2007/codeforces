#include <bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
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
typedef long long int ll;
typedef unsigned long long ull;
typedef pair <int, int> PII;
typedef pair <ll, ll> PLL;
typedef pair <PLL, int> PLLI;
typedef pair <PLL, PLL> PP;
typedef pair <PII, int> PPI;
typedef pair <ll, int> PLI;
typedef unsigned int ui;
const int inf = 1e9+9;
const ll MOD = 1e9+696969;
const long long INF = 1e18+3;
const int maxn = 201000;
int n, m, a, b, arr[maxn], root; char zn;
bool odw[maxn];
vector <PII> v[maxn];
ll dist[maxn];

typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
ordered_set sety[maxn];
int wynik[maxn];
int f[maxn], r[maxn];
inline int Fnd(int a) {
	if (f[a] == a) return a;
	f[a] = Fnd(f[a]);
	return f[a];
}

void dfs(int x){
	odw[x] = 1;
	for (int i=0; i<(int)v[x].size(); ++i) {
		if (odw[v[x][i].e1]) continue;
		dist[v[x][i].e1] = dist[x] + v[x][i].e2;
		dfs(v[x][i].e1);
		r[x] += r[v[x][i].e1];
	}
	for (int i=0; i<(int)v[x].size(); ++i) {
		int u = v[x][i].e1;
		int fx = Fnd(x), fu = Fnd(u);
		if (sety[fx].size() < sety[fu].size()) {
			f[fx] = fu;
			for (auto pp : sety[fx]) sety[fu].insert(pp);
		}
		else {
			f[fu] = fx;
			for (auto pp : sety[fu]) sety[fx].insert(pp);
		}
	}
	wynik[x] = sety[Fnd(x)].order_of_key(mp(dist[x], inf));
	sety[Fnd(x)].insert(mp(dist[x] - arr[x], x));
	r[x]++;
	//cout << x << ": " << dist[x] << endl;
	//for (auto u : sety[Fnd(x)]) cout << u.e1 << ' ';
	//cout << endl;
}
int main()
{
	boost;
	cin >> n;
	FOR(i, 1, n) cin >> arr[i];
	FOR(i, 2, n) {
		int p; a = i;
		cin >> p >> b;
		v[p].pb(mp(a, b));
	}
	FOR(i, 1, n) f[i] = i;
	dfs(1);
	FOR(i, 1, n) cout << wynik[i] << ' ';
		
}