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
const int maxn = 100100;

long double res[maxn];
ll r[maxn];
vector <int> v[maxn];
int n;

void dfs(int x) {
	r[x] = 1;
	for (auto u : v[x]) {
		dfs(u);
		r[x] += r[u];
	}
}

void zn(int x, int p) {
	for (auto u : v[x]) {
		res[u] = res[x] + (r[x] - r[u] - 1) * 0.5 + 1;
		zn(u, x);
	}
}

int main()
{
	boost;
	cin >> n;
	FOR(i, 2, n) {
		int p;
		cin >> p;
		v[p].pb(i);
	}
	dfs(1);
	res[1] = 1;
	zn(1, 1);
	cout << fixed << setprecision(15);
	FOR(i, 1, n) cout << res[i] << ' ';
}