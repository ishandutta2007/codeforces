// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
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

const int MX = 1005;
int n, m, to[MX], vis[MX];
ll a[MX];
vi adj[MX];
vii res;

bool kuhn (int u) {
	vis[u] = 1;
	
	for (int v : adj[u])
		if (to[v] == -1 || (!vis[to[v]] && kuhn(to[v]))) {
			to[u] = v;
			to[v] = u;
			return 1;
		}
	
	return 0;
}

void main_() {
	cin >> n >> m;
	forn (i, n)
		cin >> a[i];
	
	forn (i, n)
		if (3 * a[i] > m)
			forn (j, n)
				if (a[i] % a[j] == 0)
				if (2 * a[i] + a[j] <= m)
					adj[i].pb(j);
	
	memset(to, -1, sizeof(to));
	forn (i, n)
		if (3 * a[i] > m) {
			memset(vis, 0, sizeof(vis));
			
			if (!kuhn(i)) {
				cout << -1 << endl;
				return;
			}
		}
	
	forn (i, n)
		if (3 * a[i] > m)
			res.pb({2 * a[i] + a[to[i]], a[i] + a[to[i]]});
	
	forn (i, n)
		if (to[i] == -1)
			res.pb({3 * a[i], 2 * a[i]});
		
	cout << res.size() << endl;
	for (ii &p : res)
		cout << p.fi << " " << p.se << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}