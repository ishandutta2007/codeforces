#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int, int> pii;

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

vector<pii> R;

pair<bool, int> parse(string s){
    int n = 0;
    for (int i = 1; i < (int)s.size(); ++i){
        n = 10 * n + s[i] - '0';
    }
    return make_pair(s[0] == '+', n);
}

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    sat2 sat(m);

    for (int i = 0; i < m; ++i){
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);

        R.push_back( make_pair(u, v) );

        for (int j = 0; j < i; ++j){
            int a = R[j].first, b = R[j].second;
            if ((a <= u && v <= b) || (u <= a && b <= v) || (b <= u) || (v <= a))
                continue;

            sat.implication(i, sat.neg(j));
            sat.implication(sat.neg(i), j);
            sat.implication(j, sat.neg(i));
            sat.implication(sat.neg(j),i);
        }
    }
    bool ans = sat.solve();
    if (!ans){
        cout << "Impossible" << endl;
        return 0;
    }
    for (int i = 0; i < m; ++i){
        if (sat.value[i]) cout << "i";
        else cout << "o";
    }
    cout << endl;

    return 0;
}