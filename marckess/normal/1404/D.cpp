#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;

	if (n % 2 == 0) {
		cout << "First" << endl;
		forn (i, n) cout << i + 1 << " ";
		forn (i, n) cout << i + 1 << " ";
		cout << endl;
	} else {
		cout << "Second" << endl;

		vii v(2 * n);
		vvi adj(2 * n + 1);
		vi vis (2 * n + 1);

		for (int i = 1; i <= 2 * n; i++) {
			int x;
			cin >> x;
			x--;
			
			if (!v[x].fi) v[x].fi = i;
			else v[x].se = i;

			if (i <= n) {
				adj[i].pb(n + i);
				adj[n + i].pb(i);
			}
		}

		forn (i, n) {
			adj[v[i].fi].pb(v[i].se);
			adj[v[i].se].pb(v[i].fi);
		}

		ll s = 0;
		vi a, b;

		for (int i = 1; i <= 2 * n; i++) if (!vis[i]) {
			int f = 1, u = i;

			while (u != -1) {
				int to = -1;

				if (f) {
					a.pb(u);
					s += u;
				} else b.pb(u);

				vis[u] = 1;
				f ^= 1;

				for (int v : adj[u])
					if (!vis[v])
						to = v;

				u = to;
			}
		}

		if (s % (2 * n) == 0) for (int x : a) cout << x << " ";
		else for (int x : b) cout << x << " ";
		cout << endl;
	}

	return 0;
}