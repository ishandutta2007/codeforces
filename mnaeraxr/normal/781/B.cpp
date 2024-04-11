#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

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

	int n; cin >> n;

	vector<string> L(n), S(n);

	satisfiability_twosat sat(n);

	for (int i = 0; i < n; ++i){
		string a, b;
		cin >> a >> b;

		L[i] = a.substr(0, 3);
		S[i] = a.substr(0, 2) + b[0];

		for (int j = 0; j < i; ++j){
			if (S[i] == L[j])
				sat.implication( sat.neg(i), sat.neg(j) );

			if (S[j] == L[i])
				sat.implication( sat.neg(j), sat.neg(i) );

			if (S[i] == S[j])
				sat.implication( sat.neg(i), j );

			if (L[i] == L[j]){
				sat.implication(i, sat.neg(i) );
				sat.implication(j, sat.neg(j) );
			}
		}
	}

	vector<bool> answer = sat.solve();

	if (answer.size()){
		cout << "YES" << endl;

		for (int i = 0; i < n; ++i)
			cout << (answer[i] ? L : S)[i] << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;

}