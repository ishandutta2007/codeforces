#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int N = 1005, M = 30005;
int n, m, s, t, x[M], y[M], w[M], ne = -1;
int mn = 2e9+1, ra = -1, rb = -1;
vi adj[N], st;
bitset<N> bs;

bool con (int u) {
	if (u == t) return 1;
	if (bs[u]) return 0;
	bs[u] = 1;

	for (int i : adj[u]) {
		if (i == ne) continue;
		if (con(x[i])) return 1;
		if (con(y[i])) return 1;
	}

	return 0;
}

void obtST (int u) {
	bs[u] = 1;

	for (int i : adj[u]) {
		if (i == ne) continue;
		if (!bs[x[i]]) {
			st.push_back(i);
			obtST(x[i]);
		}
		if (!bs[y[i]]) {
			st.push_back(i);
			obtST(y[i]);
		}
	}
}

int low[N], num[N], cn = 0;
bitset<M> a;

bool ari (int u, int p) {
	bool f = 0, r = 0;
	low[u] = num[u] = ++cn;

	for (int i : adj[u]) {
		int v = u == x[i] ? y[i] : x[i];
		if (v == u || i == p || i == ne) continue;

		if (!num[v]) {
			f = ari(v, i);
			r |= f;
			if (low[v] > num[u] && f)
				a[i] = 1;
			low[u] = min(low[u], low[v]);
		} else {
			low[u] = min(low[u], num[v]);
		}
	}

	return r || u == t;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> s >> t;
	for (int i = 0; i < m; i++) {
		cin >> x[i] >> y[i] >> w[i];
		adj[x[i]].push_back(i);
		adj[y[i]].push_back(i);
	}

	if (!con(s)) {
		cout << 0 << endl << 0 << endl << endl;
		return 0;
	}

	bs.reset();
	obtST(s);

	for (int i : st) {
		ne = i;
		bs.reset();

		if (!con(s)) {
			if (mn > w[i]) {
				mn = w[i];
				ra = i+1;
				rb = -1;
			}
		} else {
			bs.reset(), a.reset();
			memset(low, 0, sizeof(low));
			memset(num, 0, sizeof(num));
			cn = 0;
			ari(s, -1);

			for (int j = 0; j < m; j++)
				if (a[j]) {
					if (mn > w[i] + w[j]) {
						mn = w[i] + w[j];
						ra = i+1;
						rb = j+1;
					}
				}
		}
	}

	if (ra == -1)
		cout << -1 << endl;
	else if (rb == -1)
		cout << mn << endl << 1 << endl << ra << endl;
	else
		cout << mn << endl << 2 << endl << ra << " " << rb << endl;

	return 0;
}