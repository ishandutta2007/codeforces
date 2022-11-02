#include<bits/stdc++.h>
using namespace std;

// Order statistics tree (if supported by judge!):
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template<class TK, class TM> using order_tree =
	tree<TK, TM, less<TK>, rb_tree_tag, tree_order_statistics_node_update>;
// iterator	find_by_order(int r) (zero based)
// int		order_of_key(TK v)
template<class TV> using order_set = order_tree<TV, null_type>;

#define x first
#define y second
#define rs resize
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define rep(i,a,b) for(auto i=(a);i!=(b); ++i)
#define REP(i,n) rep(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
template<class T> using min_queue = priority_queue<T, vector<T>, greater<T>>;

template<class T1, class T2>
ostream& operator<<(ostream &out, const pair<T1,T2> &a) { return out << '(' << a.x << ", " << a.y << ')'; }
template<class T1, class T2>
istream& operator>>(istream &in, pair<T1,T2> &a) { return in >> a.x >> a.y; }

const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

// lambda-expression: [] (args) -> retType { body }

ll calculate(const vvi &adj, int a, int b) {
	int n = adj.size();
	vector<bool> vis(n, false);

	ll ans = 0;
	ll ca = 0, cb = 0;
	REP(v, n) {
		if (vis[v]) continue;

		queue<int> q;
		ll cp = 0;
		bool seea = false, seeb = false;

		if (v != a && v != b) {
			vis[v] = true;
			q.push(v);
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur != a && cur != b) cp++;

			for (int nxt : adj[cur]) {
				if (!vis[nxt] && nxt != a && nxt != b) {
					vis[nxt] = true;
					q.push(nxt);
				} else if (nxt == a) seea = true;
				else if (nxt == b) seeb = true;
			}
		}

		if (seea && !seeb) ca += cp;
		if (seeb && !seea) cb += cp;
	}

	return ca*cb;

	/* auto dfs = [&](int v, const auto& f)->void {
		vis[v] = true;
		for (int w : adj[v]) if (!vis[w]) f(w, f);
		ans.pb(v);
	}; */
}

ll run() {
	int n, m, a, b;
	cin >> n >> m >> a >> b;
	a--;
	b--;

	vvi adj(n);

	REP(i, m) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;

		adj[x].pb(y);
		adj[y].pb(x);
	}

	return calculate(adj, a, b);
	/* return calculate(adj, a, b, -1, -1) + calculate(adj, a, b, a, b)
		- calculate(adj, a, b, a, -1) - calculate(adj, a, b, -1, b); */
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cerr << boolalpha;
	(cout << fixed).precision(10);

	int n;
	cin >> n;
	while (n--) {
		ll ans = run();
		cout << ans << endl;
	}

	return 0;
}