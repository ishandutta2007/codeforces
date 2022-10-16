#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct disjoint_set{
	vi d;
	disjoint_set(int n){
		d = vi(n, -1);
	}

	int root(int a){
		return d[a] < 0 ? a : d[a] = root(d[a]);
	}

	bool join(int a, int b){
		a = root(a), b = root(b);
		if (a == b) return false;
		if (d[a] > d[b]) swap(a, b);
		d[a] += d[b];
		d[b] = a;
		return true;
	}
};

bool bfs(int s, vi &color, vi &total, vector<vi> &adj){
	vector<int> q;
	int beg = 0;

	q.push_back(s);
	color[s] = 1;

	pii ans(total[s], 0);
	while (beg < (int)q.size()){
		int u = q[beg++];
		for (auto v : adj[u]){
			if (color[v] != 0){
				if (color[v] == color[u]) {
					return false;
				}
			}
			else{
				color[v] = color[u] * -1;

				if (color[v] == -1) ans.second += total[v];
				else ans.first += total[v];

				q.push_back(v);
			}
		}
	}

	if (ans.first > ans.second){
		for (auto val : q)
			color[val] *= -1;
	}

	return true;
}

vi solve(int N, vector<vector<pii>> &adj){
	disjoint_set ds(N);
	int n = N;

	for (int i = 0; i < N; ++i){
		for (auto e : adj[i])
			if (e.second){
				if (ds.join(i, e.first)){
					n--;
				}
			}
	}

	int pnt = 0;
	vector<int> id(N);

	vector<int> total(n, 0);
	vector<vi> nadj(n);
	vector<int> color(n, 0);

	for (int i = 0; i < N; ++i){
		if (ds.root(i) == i){
			id[i] = pnt++;
			total[id[i]] = -ds.d[i];
		}
	}

	assert(pnt == n);

	for (int i = 0; i < N; ++i){
		for (auto e : adj[i])
			if (!e.second){
				nadj[id[ds.root(i)]].push_back(id[ds.root(e.first)]);
			}
	}

	for (int i = 0; i < n; ++i){
		if (!color[i]){
			bool val = bfs(i, color, total, nadj);
			if (!val) return {-1};
		}
	}

	vector<int> cc;

	for (int i = 0; i < N; ++i){
		assert(color[id[ds.root(i)]] != 0);
		if (color[id[ds.root(i)]] == 1){
			cc.push_back(i + 1);
		}
	}

	return cc;
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<vector<pii>> adj1(n), adj2(n);
	for (int i = 0; i < m; ++i){
		int u, v;
		string s;
		cin >> u >> v >> s;
		u--; v--;
		int w = s == "R" ? 1 : 0;

		adj1[u].push_back({v, w});
		adj1[v].push_back({u, w});

		adj2[u].push_back({v, w ^ 1});
		adj2[v].push_back({u, w ^ 1});
	}

	vi s1 = solve(n, adj1);
	vi s2 = solve(n, adj2);

	int v1 = (s1.size() == 1 && s1[0] == -1) ? oo : (int)s1.size();
	int v2 = (s2.size() == 1 && s2[0] == -1) ? oo : (int)s2.size();

	if (v2 < v1){
		swap(v1, v2);
		s1.swap(s2);
	}

	if (v1 == oo) cout << -1 << endl;
	else{
		cout << s1.size() << endl;
		for (auto v : s1)
			cout << v << " ";
		cout << endl;
	}

	return 0;
}