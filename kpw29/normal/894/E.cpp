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
int n, m;
const int maxn = 1000100;
vector <PII> v[maxn];
vector <PII> rev[maxn];
vector <int> top;
vector <int> skl[maxn];
bool odw[maxn];
int SKL[maxn], CC, start;
ll dp[maxn];

void dfs(int x){ 
	odw[x] = 1;
	for (auto u : v[x])
		if (!odw[u.e1]) dfs(u.e1);
	top.pb(x);
}

void revdfs(int x, int spoj) {
	odw[x] = 1;
	for (auto u : rev[x])
		if (!odw[u.e1]) revdfs(u.e1, spoj);
	SKL[x] = spoj;
	skl[spoj].pb(x);
}
ll value[maxn];
ll elo[maxn];
inline ll f(ll wartosc) {
	//x + x - 1 + x - 3 + x - 6 + x - 10 + ..
	ll x = 0, y = 1000000;
	while (x < y) {
		ll mid = (x + y) / 2 + 1;
		if (wartosc - mid * (mid - 1)/2 < 0) y = --mid;
		else x = mid;
	}
	
	return x * wartosc - elo[x];
}

int A[maxn], B[maxn], C[maxn];

int main()
{
	elo[1] = 0; elo[2] = 1;
	for (int i=3; i<=100000; ++i) elo[i] = elo[i-1] + (ll)i * (ll)(i - 1)/2;
	boost;
	cin >> n >> m;
	FOR(i, 1, n) v[0].pb(mp(i, 0)), rev[i].pb(mp(0, 0));
	FOR(i, 1, m) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].pb(mp(b, c));
		rev[b].pb(mp(a, c));
		A[i] = a; B[i] = b; C[i] = c;
	}
	dfs(0);
	cin >> start;
	fill(odw, odw+n+5, 0);
	reverse(top.begin(), top.end());
	for (auto u : top)
		if (!odw[u]) ++CC, revdfs(u, CC);

	FOR(i, 1, m)
		if (SKL[A[i]] == SKL[B[i]]) value[SKL[A[i]]] += f(C[i]);

	for (int i=CC; i>0; --i){
		ll best = 0;
		for (auto ktory : skl[i])
			for (auto u : v[ktory]) 
				if (SKL[ktory] != SKL[u.e1]) best = max(best, u.e2 + dp[SKL[u.e1]]);
		dp[i] = value[i] + best;
	}
	cout << dp[SKL[start]];
}