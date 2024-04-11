#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 400000 + 10;

vi adj[maxn];

struct union_find
{
	vector<int> p;

	union_find(int n) : p(n, -1) {}

	bool join(int u, int v)
	{
		if ((u = root(u)) == (v = root(v)))
			return false;
		if (p[u] > p[v])
			swap(u, v);
		p[u] += p[v];
		p[v] = u;
		return true;
	}

	int root(int u)
	{
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
};

int tour[maxn];
int total;

void dfs(int s, int p){
	tour[total++] = s;

	for (auto u : adj[s]){
		if (u == p) continue;

		dfs(u, s);
		tour[ total++ ] = s;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;

	cin >> n >> m >> k;

	int t = ( 2 * n + k - 1) / k;

	union_find uf(n + 1);

	for (int i = 0; i < m; ++i){
		int u, v; cin >> u >> v;

		if (uf.join(u, v)){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	dfs(1, -1);

	for (int i = 0; i < k; ++i){
		int b = i * t, e = (i + 1) * t;

		b = min(b, total);
		e = min(e, total);

		if (e == b){
			cout << 1 << " " << 1 << endl;
		}
		else{
			cout << e - b;

			for (int j = b; j < e; ++j)
				cout << " " << tour[j];
			cout << endl;
		}
	}

	return 0;

}