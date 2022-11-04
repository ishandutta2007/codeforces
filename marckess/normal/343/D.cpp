#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const int MX = 500005;
int n, u, v, q, op, cn, p[MX];
int ini[MX], fin[MX];
vi adj[MX];

struct ST {
	int st[4*MX], ps[MX];

	void init (int i, int j, int pos) {
		st[pos] = 0;

		if (i < j) {
			int m = (i+j)/2;
			init(i, m, pos*2);
			init(m+1, j, pos*2+1);
		} else {
			ps[i] = pos;
		}
	}

	void update (int i, int k) {
		int pos = ps[i];
		st[pos] = k;
		pos /= 2;

		while (pos >= 1) {
			st[pos] = max(st[pos*2], st[pos*2+1]);
			pos /= 2;
		}
	}

	void update (int i, int j, int pos, int a, int b, int k) {
		if (b < i || j < a)
			return;

		if (a <= i && j <= b) {
			st[pos] = k;
			return;
		}

		int m = (i+j)/2;
		update(i, m, pos*2, a, b, k);
		update(m+1, j, pos*2+1, a, b, k);
	}

	int query (int i, int j, int pos, int a, int b) {
		if (b < i || j < a)
			return 0;

		if (a <= i && j <= b)
			return st[pos];

		int m = (i+j)/2;
		return max ( query(i, m, pos*2, a, b), query(m+1, j, pos*2+1, a, b) );
	}

	int query (int i, int j, int pos, int x) {
		if (i == j)
			return st[pos];

		st[pos*2] = max(st[pos], st[pos*2]);
		st[pos*2+1] = max(st[pos], st[pos*2+1]);

		int m = (i+j)/2;
		if (i <= x && x <= m)
			return query(i, m, pos*2, x);
		return query(m+1, j, pos*2+1, x);
	}
}e, f;

void dfs (int u) {
	ini[u] = cn++;

	for (int v : adj[u])
		if (v != p[u]) {
			p[v] = u;
			dfs(v);
		}

	fin[u] = cn-1;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    cin >> n;
    for (int i = 1; i < n; i++) {
    	cin >> u >> v;
    	adj[u].push_back(v);
    	adj[v].push_back(u);
    }

    cn = 1;
    p[1] = 1;
    dfs(1);
    e.init(1, n, 1);
    f.init(1, n, 1);

    cin >> q;
    for (int i = 1; i <= q; i++) {
    	cin >> op >> u;

    	if (op == 1) {
    		f.update(1, n, 1, ini[u], fin[u], i);
    	} else if (op == 2) {
    		e.update(ini[u], i);
    	} else {
    		cout << (f.query(1, n, 1, ini[u]) > e.query(1, n, 1, ini[u], fin[u])) << endl;
    	}
    }

    return 0;
}