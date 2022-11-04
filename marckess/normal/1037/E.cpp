#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m, d[MX], u[MX], v[MX], k, cn, res[MX];
set<int> adj[MX];
stack<int> st;
bitset<MX> ex;

void del (int u) {
	cn--;
	for (int v : adj[u]) {
		d[v]--;
		if (ex[v] && d[v] < k) {
			ex[v] = 0;
			st.push(v);
		}
	}
}

void del () {
	while (st.size()) {
		int u = st.top();
		st.pop();
		del(u);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		cin >> u[i] >> v[i];
		adj[u[i]].insert(v[i]);
		adj[v[i]].insert(u[i]);
		d[u[i]]++, d[v[i]]++;
	}

	cn = n;
	ex.set();

	for (int i = 1; i <= n; i++)
		if (d[i] < k) {
			ex[i] = 0;
			st.push(i);
		}
	del();

	res[m] = cn;

	for (int i = m-1; i > 0; i--) {
		if (ex[u[i]] && ex[v[i]]) {
			adj[u[i]].erase(v[i]);
			adj[v[i]].erase(u[i]);

			d[u[i]]--;
			d[v[i]]--;

			if (d[u[i]] < k) {
				ex[u[i]] = 0;
				st.push(u[i]);
			}

			if (d[v[i]] < k) {
				ex[v[i]] = 0;
				st.push(v[i]);
			}
		}

		del();
		res[i] = cn;
	}

	for (int i = 1; i <= m; i++)
		cout << res[i] << endl;

	return 0;
}