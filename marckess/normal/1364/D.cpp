#include <bits/stdc++.h>
 
#define endl '\n'
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

const int MX = 100005;
int n, m, k, p[MX], pos[MX], ex[MX];
vi adj[MX], x, y;

vi norm (vi c) {
	memset(pos, -1, sizeof(pos));
	int n = c.size();
	forn (i, n)
		pos[c[i]] = i;

	for (int i = 0; i < n;) {
		int to = -1;

		for (int v : adj[c[i]])
			if (pos[v] != -1 && c[(i + 1) % n] != v && c[(i - 1 + n) % n] != v && pos[v] > i)
				to = max(to, pos[v]);

		i++;
		while (i < to) {
			ex[i] = 1;
			i++;
		}
	}

	vi res;
	forn (i, n)
		if (!ex[i])
			res.pb(c[i]);

	return res;
}

void dfs (int u, int col) {
	if (col) x.pb(u);
	else y.pb(u);

	for (int v : adj[u])
		if (p[u] != v) {
			if (p[v] == -1) {
				p[v] = u;
				dfs(v, 1 - col);
			} else {
				vi c = {u};
				int w = u;

				while (w != v) {
					c.pb(p[w]);
					w = p[w];
				}

				//for (int x : c) cout << x << " "; cout << endl;
				c = norm(c);
				//for (int x : c) cout << x << " "; cout << endl;

				if (c.size() <= k) {
					cout << "2" << endl << c.size() << endl;
					for (int x : c) cout << x << " ";
					cout << endl;
				} else {
					cout << "1" << endl;
					forn (i, (k + 1) / 2)
						cout << c[2 * i] << " ";
					cout << endl;
				}

				exit(0);
			}
		}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	forn (i, m) {
		int a, b;
		cin >> a >> b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	memset(p, -1, sizeof(p));
	p[1] = 1;
	dfs(1, 0);

	if (x.size() < y.size()) swap(x, y);

	cout << 1 << endl;
	forn (i, (k + 1) / 2)
		cout << x[i] << " ";
	cout << endl;

	return 0;
}