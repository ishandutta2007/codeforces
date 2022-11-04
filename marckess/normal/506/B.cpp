#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 100005;
int n, m, u, v, res = 0;
vi adj[MX];

struct DSU {
	int p[MX], rk[MX], tam[MX];
	bitset<MX> esP, cicl;

	void init (int n) {
		for (int i = 0; i <= n; i++) {
			p[i] = i;
			rk[i] = 0;
			tam[i] = 1;
			esP[i] = 1;
			cicl[i] = 0;
		}
	}

	int parent (int a) {
		return a == p[a] ? a : p[a] = parent(p[a]);
	}

	void joint (int a, int b) {
		a = parent(a), b = parent(b);
		if (a == b)
			return;

		if (rk[a] > rk[b]) {
			tam[a] += tam[b];
			cicl[a] = cicl[a] | cicl[b];
			esP[b] = 0;
			p[b] = a;
		} else {
			tam[b] += tam[a];
			cicl[b] = cicl[a] | cicl[b];
			esP[a] = 0;
			p[a] = b;

			if (rk[a] == rk[b])
				rk[b]++;
		}
	}
};

int bs[MX];
DSU ds;

void dfs (int u) {
	bs[u] = 1;

	for (int v : adj[u]) {
		ds.joint(u, v);
		
		if (!bs[v])
			dfs(v);
		else if (bs[v] == 1) {
			ds.cicl[ds.parent(u)] = 1;
		}
	}

	bs[u] = 2;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		cin >> u >> v;
		adj[u].push_back(v);
	}

	ds.init(n);
	for (int i = 1; i <= n; i++) {
		if (!bs[i]) {
			dfs(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (ds.esP[i]) {
			res += ds.tam[i];
			if (!ds.cicl[i])
				res--; 
		}
	}

	cout << res << endl;

	return 0;
}