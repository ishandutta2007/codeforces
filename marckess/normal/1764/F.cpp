#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, p[MX];
ll a[MX][MX];
vvi ve;
vi adj[MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

int join (int a, int b) {
	a = parent(a), b = parent(b);
	if (a == b) return 0;
	p[a] = b;
	return a;
}

int cn = 0;
void dfs (int u, int p) {
	cn++;
	for (auto v : adj[u])
		if (v != p)
			dfs(v, u);
}

vii led;

void main_() {
	cin >> n;
	
	iota(p, p + MX, 0);
	
	forr (i, 1, n) {
		forr (j, 1, i) {
			cin >> a[i][j];
			a[j][i] = a[i][j];
			ve.pb({a[i][j], j, i});
		}
	}
	
	sort(all(ve), greater<vi>());
	for (vi &v : ve) {
		if (join(v[1], v[2])) {
			adj[v[1]].pb(v[2]);
			adj[v[2]].pb(v[1]);
			led.pb({v[1], v[2]});
		}
	}
	
	for (auto [u, v] : led) {
		cn = 0;
		dfs(v, u);
		
		ll w = (a[u][u] - a[u][v]) / cn;
		cout << u << " " << v << " " << w << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}