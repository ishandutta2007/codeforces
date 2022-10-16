#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

vi adj[maxn];

int col[maxn];

void dfs(int s, int p, int c1, int c2){
	int c = 1;

//	cout << s << " " << p << " " << c1 << " " << c2 << endl;

	for (auto u : adj[s]){
		if (u == p) continue;
		while (c == c1 || c == c2) c++;
		col[u] = c++;

		dfs(u, s, col[u], col[s]);
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n; cin >> n;

	for (int i = 0; i + 1 < n; ++i){
		int u, v; cin >> u >> v;

		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	col[1] = 1;
	dfs(1, -1, 1, -1);

	int m = 0;

	for (int i = 1; i <= n; ++i)
		m = max(m, col[i]);

	cout << m << endl;

	for (int i = 1; i <= n; ++i)
		cout << col[i] << " ";

	cout << endl;

	return 0;
}