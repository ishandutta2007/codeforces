#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100000 + 10;

struct satisfiability_twosat
{
	int n;
	vector<vector<int>> imp;

	satisfiability_twosat(int n) : n(n), imp(2 * n) {}

	void add_edge(int u, int v)
	{
		imp[u].push_back(v);
	}

	int neg(int u) { return (n << 1) - u - 1; }

	void implication(int u, int v)
	{
		add_edge(u, v);
		add_edge(neg(v), neg(u));
	}

	vector<bool> solve()
	{
		int size = 2 * n;
		vector<int> S, B, I(size);

		function<void(int)> dfs = [&](int u)
		{
			B.push_back(I[u] = S.size());
			S.push_back(u);

			for (int v : imp[u])
				if (!I[v]) dfs(v);
				else while (I[v] < B.back()) B.pop_back();

			if (I[u] == B.back())
				for (B.pop_back(), ++size; I[u] < S.size(); S.pop_back())
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

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n, a, b;
	cin >> n >> a >> b;
	
	satisfiability_twosat sat(n);
	map<int,int> pos;
	
	for (int i = 0; i < n; ++i){
		int v; cin >> v;
		pos[v] = i;
	}
	
	for (auto p : pos){
		if (pos.count(a - p.first))
			sat.implication( p.second, pos[ a - p.first ]);
		else
			sat.implication( p.second, sat.neg(p.second) );
		
		if (pos.count(b - p.first))
			sat.implication( sat.neg(p.second), sat.neg(pos[ b - p.first ]));
		else
			sat.implication( sat.neg(p.second), p.second );
	}
	
	vector<bool> asn = sat.solve();
	
	if (asn.empty()) cout << "NO" << endl;
	else{
		cout << "YES" << endl;
		for (auto a : asn) cout << !a << " ";
		cout << endl;
	}
	
	return 0;
}