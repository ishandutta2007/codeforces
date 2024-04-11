#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = (a); i <= (b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, q, p[2 * MX];

struct Edge {
	int u, v, w, ind;
	Edge () {}
	Edge (int u, int v, int w, int ind) : u(u), v(v), w(w), ind(ind) {}
	bool operator < (const Edge &ot) const {
		return w > ot.w;
	}
}e[MX * MX];

int parent (int a) {
	return a == p[a] ? a : p[a] = parent(p[a]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[i] = {u, v, w, i};
	}

	sort(e + 1, e + 1 + m);

	while (q--) {
		int l, r, f = 0;
		cin >> l >> r;
		iota(p, p + 2 * MX, 0);

		for (int i = 1; i <= m; i++)
			if (l <= e[i].ind && e[i].ind <= r) {
				int u = e[i].u, v = e[i].v;

				if (parent(2 * u) == parent(2 * v)) {
					cout << e[i].w << endl;
					f = 1;
					break;
				} else {
					p[parent(2 * u)] = parent(2 * v + 1);
					p[parent(2 * v)] = parent(2 * u + 1);
				}
			}

		if (!f) cout << -1 << endl;
	}

	return 0;
}