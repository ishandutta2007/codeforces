#include <bits/stdc++.h>

using namespace std;

#define endl '\n'

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200000 + 10;

vector<pii> adj[maxn];
int value[maxn];

void solve(int n){
	memset(value, 0, sizeof value);
	value[1] = oo;

	priority_queue<pii> pq;
	pq.push({value[1], 1});


	while (!pq.empty()){
		pii cur = pq.top(); pq.pop();
		int u = cur.second, val = cur.first;

		if (val < value[u]) continue;

		for (auto e : adj[u]){
			int nval = min(val, e.second);
			int v = e.first;

			if (nval > value[v]){
				value[v] = nval;
				pq.push({value[v], v});
			}
		}
	}
}

struct edge{
	int u, v, l, r;
};

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	vector<edge> E(m);
	vector<int> B(m);

	int answer = 0;

	for (int i = 0; i < m; ++i){
		int u, v, l, r;
		cin >> u >> v >> l >> r;

		E[i] = {u, v, l, r};
		B[i] = l;
	}

	sort(B.begin(), B.end());
	B.resize(unique(B.begin(), B.end()) - B.begin());

	for (auto l : B){
		for (int i = 1; i <= n; ++i)
			adj[i].clear();

		for (int i = 0; i < m; ++i){
			if (E[i].l <= l && l <= E[i].r){
				int u = E[i].u, v = E[i].v, w = E[i].r;

				adj[u].push_back({v, w});
				adj[v].push_back({u, w});
			}
		}

		solve(n);

		answer = max(answer, value[n] - l + 1);
	}

	if (answer == 0)
		cout << "Nice work, Dima!" << endl;
	else
		cout << answer << endl;

	return 0;
}