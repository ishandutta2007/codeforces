#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

vector<vector<int> > edges;
vector<vector<int> > endex;
vector<long long> side;
vector<long long> dp;
void dfs(int from, int cur) {
	int res = 1;
	for (int i = 0; i < edges[cur].size(); i++)
		if (edges[cur][i] != from) {
			dfs(cur, edges[cur][i]);
			res += dp[edges[cur][i]];
			side[endex[cur][i]] = dp[edges[cur][i]] * (edges.size() - dp[edges[cur][i]]);
		}
	dp[cur] = res;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, a, b, i, q, chi, chl;
	cin >> n;
	edges = vector<vector<int> >(n);
	endex = vector<vector<int> >(n);
	side = vector<long long>(n - 1);
	dp = vector<long long>(n);
	vector<int> len(n - 1);
	for(i = 0; i < n - 1; i++) {
		cin >> a >> b >> len[i];
		a--;
		b--;
		edges[a].push_back(b);
		edges[b].push_back(a);
		endex[a].push_back(i);
		endex[b].push_back(i);
	}

	dfs(-1, 0);
	long long sum = 0;
	for (i = 0; i < n - 1; i++) {
		sum += side[i] * len[i];
	}
	
	cout.precision(20);
	cin >> q;
	for (i = 0; i < q; i++) {
		cin >> chi >> chl;
		chi--;
		sum -= side[chi] * (len[chi] - chl);
		len[chi] = chl;
		cout << sum * 6.0 / n / (n - 1) << '\n';
	}

	return 0;
}