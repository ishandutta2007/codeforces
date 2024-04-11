#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int64 oo = 100000000000000000LL;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct sat2
{
	int n;
	vector<vector<int>> adj, radj;

	sat2(int n) : n(n), adj(2*n), radj(2*n) {}

	void add_edge(int u, int v)
	{
		adj[u].push_back(v);
		radj[v].push_back(u);
	}

	int neg(int u)
	{
		return 2*n-u-1;
	}

	void implication(int u, int v)
	{
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	void eq(int u, int v){
		implication(u, v);
		implication(v, u);
	}

	void diff(int u, int v){
		eq(u, neg(v));
	}

	vector<bool> value;

	bool solve()
	{
		vector<int> seen(2 * n);
		value.assign(2 * n, false);

		function<void(int, vector<vector<int>>&, vector<int>&)> visit =
				[&](int u, vector<vector<int>> &adj, vector<int> &vec)
		{
			seen[u] = true;
			for (int v : adj[u])
				if (!seen[v])
					visit(v, adj, vec);
			vec.push_back(u);
		};

		vector<int> order;

		for (int u = 0; u < n; ++u)
		{
			if (!seen[u]) visit(u, adj, order);
			if (!seen[neg(u)]) visit(neg(u), adj, order);
		}

		seen.assign(2 * n, false);
		reverse(order.begin(), order.end());

		vector<int> comp, id(2 * n);
		int cc = 0;

		for (int u : order)
			if (!seen[u])
			{
				comp.clear(); ++cc;
				visit(u, radj, comp);
				for (int v : comp)
					id[v] = cc;
			}

		for (int u = 0; u < n; ++u)
			if (id[u] == id[neg(u)]) return false;
			else value[u] = id[u] > id[neg(u)];

		return true;
	}
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> status(n);

	for (int i = 0; i < n; ++i){
		cin >> status[i];
	}

	vector<vi> sw(n);

	for (int i = 0; i < m; ++i){
		int t; cin >> t;

		for (int j = 0; j < t; ++j){
			int s; cin >> s; s--;
			sw[s].push_back(i);
		}
	}

	sat2 S(m);

	for (int i = 0; i < n; ++i){
		int u = sw[i][0], v = sw[i][1];

		if (status[i] == 1) S.eq(u, v);
		else S.diff(u, v);
	}

	cout << (S.solve() ? "YES" : "NO") << endl;

	return 0;
}