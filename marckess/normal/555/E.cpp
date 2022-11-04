#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005, LMX = 18;
int n, m, q, a[MX], b[MX], d[MX], s, t, cmp[MX], cnc = 0;
int p[LMX][MX], lvl[MX];
vi adj[MX], gra[MX];
bitset<MX> bs;

int low[MX], num[MX], cn = 0;
stack<int> st;
void ari (int u, int p) {
	low[u] = num[u] = ++cn;
	st.push(u);

	for (int i : adj[u]) {
		if (i == p) continue;
		int v = u == a[i] ? b[i] : a[i];

		if (num[v]) {
			low[u] = min(low[u], num[v]);
		} else {
			ari(v, i);
			if (low[v] > num[u]) {
				cnc++;
				while (1) {
					int w = st.top();
					st.pop();
					cmp[w] = cnc;
					if (w == v) break;
				}
			}
			low[u] = min(low[u], low[v]);
		}
	}
}

void dfs (int u, int l) {
	lvl[u] = l;
	bs[u] = 1;
	for (int v : gra[u])
		if (!bs[v]) {
			p[0][v] = u;
			dfs(v, l+1);
		}
}

int LCA (int u, int v) {
	if (lvl[u] < lvl[v]) swap(u, v);

	for (int j = LMX-1; j >= 0; j--)
		if ((lvl[u] - lvl[v]) & (1 << j))
			u = p[j][u];

	if (u == v) return u;

	for (int j = LMX-1; j >= 0; j--) 
		if (p[j][u] != p[j][v]) {
			u = p[j][u];
			v = p[j][v];
		}

	return p[0][u] != p[0][v] ? -1 : p[0][u];
}

void go (int u) {
	int r = d[u];
	bs[u] = 1;

	for (int v : gra[u])
		if (!bs[v]) {
			go(v);
			int e = d[v];

			if (e && abs(e) != u) {
				if (r && (r < 0) != (e < 0)) {
					cout << "No" << endl;
					exit(0);
				}
				if (!r || lvl[abs(r)] > lvl[abs(e)]) r = e;
			}
		}

	d[u] = r;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		adj[a[i]].push_back(i);
		adj[b[i]].push_back(i);
	}

	for (int i = 1; i <= n; i++)
		if (!num[i]) {
			ari(i, -1);
			if (st.size()) {
				cnc++;
				while (st.size()) {
					cmp[st.top()] = cnc;
					st.pop();
				}
			}
		}

	for (int i = 0; i < m; i++)
		if (cmp[a[i]] != cmp[b[i]]) {
			gra[cmp[a[i]]].push_back(cmp[b[i]]);
			gra[cmp[b[i]]].push_back(cmp[a[i]]);
		}

	n = cnc;
	for (int i = 1; i <= n; i++)
		if (!bs[i]) {
			p[0][i] = i;
			dfs(i, 0);
		}

	for (int j = 1; j < LMX; j++)
		for (int i = 1; i <= n; i++)
			p[j][i] = p[j-1][p[j-1][i]];

	while (q--) {
		cin >> s >> t;
		s = cmp[s], t = cmp[t];
		int lca = LCA(s, t);
		if (lca == -1 || (s != lca && d[s] < 0) || (t != lca && d[t] > 0)) {
			cout << "No" << endl;
			return 0;
		}
		if (s != lca && (!d[s] || lvl[d[s]] > lvl[lca])) d[s] = lca;
		if (t != lca && (!d[t] || lvl[-d[t]] > lvl[lca])) d[t] = -lca;
	}

	bs.reset();
	for (int i = 1; i <= n; i++)
		if (!bs[i])
			go(i);
	cout << "Yes" << endl;

	return 0;
}