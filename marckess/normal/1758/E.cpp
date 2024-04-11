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
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005, mod = 1000000007;
int n, m, h, val[MX + MX];
vvi a;
vii adj[MX + MX];

int f;
void dfs (int u) {
	for (auto [v, w] : adj[u]) {
		if (val[v] == -1) {
			val[v] = MOD(w - val[u], h);
			dfs(v);
		} else {
			if ((val[u] + val[v]) % h != w) {
				f = 0;
			}
		}
	}
}

void main_() {
	cin >> n >> m >> h;
	a = vvi(n, vi(m));
	
	f = 1;
	forn (i, n + m) {
		adj[i].clear();
		val[i] = -1;
	}
	
	forn (i, n)
	forn (j, m) {
		cin >> a[i][j];  
		
		if (a[i][j] != -1) {
			adj[i].pb({n + j, a[i][j]});
			adj[n + j].pb({i, a[i][j]});
		}
	}
	
	int cn = 0;
	forn (i, n + m)
		if (val[i] == -1) {
			cn++;
			val[i] = 0;
			dfs(i);
		}
	
	ll res = 1;
	forn (i, cn - 1)
		(res *= h) %= mod;
	cout << f * res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}