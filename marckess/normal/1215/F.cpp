#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

struct satisfiability_twosat {
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat (int n) : n(n), imp(2 * n) {}

	void add_edge (int u, int v) { imp[u].push_back(v); }

	int neg (int u) { return (n << 1) - u - 1; }

	void implication (int u, int v) {
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> solve () {
		int size = 2 * n;
		vector<int> S, B, I(size);

		function<void(int)> dfs = [&] (int u) {
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for(int v : imp[u])
				if(!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if(I[u] == B.back())
				for(B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
					I[S.back()] = size;
		};

		for (int u = 0; u < 2 * n; ++u)
			if (!I[u]) dfs(u);

		vector<bool> values(n);

		for (int u = 0; u < n; ++u)
			if (I[u] == I[neg(u)]) return {};
			else values[u] = I[u] < I[neg(u)];

		return values;
	}
};

const int MX = 400005;
int n, p, lim, m, x[MX], y[MX], l[MX], r[MX], u[MX], v[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> p >> lim >> m;
	satisfiability_twosat ts(p + lim + 5);

	forn(i, n) {
		cin >> x[i] >> y[i];
		ts.implication(ts.neg(x[i]), y[i]);
		ts.implication(ts.neg(y[i]), x[i]);
	}

	forn(i, p) {
		cin >> l[i] >> r[i];
		ts.implication(i+1, p+l[i]);
		if (r[i] < lim) ts.implication(i+1, ts.neg(p+r[i]+1));
	}

	forn(i, m) {
		cin >> u[i] >> v[i];
		ts.implication(u[i], ts.neg(v[i]));
		ts.implication(v[i], ts.neg(u[i]));
	}

	forr(i, 2, lim)
		ts.implication(p+i, p+i-1);

	auto res = ts.solve();

	if (res.empty()) cout << -1 << endl;
	else {
		vi st;
		int f;
		forr(i, 1, p)
			if (res[i])
				st.pb(i);

		forr(i, 1, lim)
			if (res[p+i])
				f = i;

		cout << st.size() << " " << f << endl;
		for (int x : st)
			cout << x << " ";
		cout << endl;
	}

	return 0;
}