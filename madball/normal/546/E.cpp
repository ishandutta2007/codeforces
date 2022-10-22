#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <queue>
using namespace std;
typedef long long ll;
const ll inf = 1e+18;

struct Edge {
	ll from, to, cap, flow;
	Edge* rev;
	Edge() {}
	Edge(ll f, ll t, ll c): from(f), to(t), cap(c), flow(0) {}
	operator ll() const {
		return to;
	}
};

struct Network {
	ll n;
	vector<vector<Edge*> > edges;
	vector<ll> dist;
	vector<ll> ptr;
	ll start, end;
	Network() {}
	Network(ll n, ll s, ll e): n(n), edges(n), start(s), end(e), dist(n), ptr(n) {}
	void addedge(ll from, ll to, ll cap) {
		edges[from].push_back(new Edge(from, to, cap));
		edges[to].push_back(new Edge(to, from, 0));
		if ((from == 4) && (to == 9))
			to = 9;
		edges[from].back()->rev = edges[to].back();
		edges[to].back()->rev = edges[from].back();
	}

	bool bfs() {
		ll i, cur;
		for (i = 0; i < n; i++)
			dist[i] = inf;
		dist[start] = 0;
		queue<ll> qu;
		qu.push(start);
		while (!qu.empty()) {
			cur = qu.front();
			qu.pop();
			for (i = 0; i < edges[cur].size(); i++)
				if ((dist[*edges[cur][i]] == inf) && (edges[cur][i]->flow < edges[cur][i]->cap)) {
					dist[*edges[cur][i]] = dist[cur] + 1;
					qu.push(*edges[cur][i]);
				}
		}
		return dist[end] < inf;
	}

	ll dfs(ll e, ll flow) {
		if (!flow)
			return 0;
		if (e == end)
			return flow;
		for (; ptr[e] < edges[e].size(); ptr[e]++) {
			Edge &to = *edges[e][ptr[e]];
			if (dist[to] != dist[e] + 1)
				continue;
			ll res = dfs(to, min(flow, to.cap - to.flow));
			if (res) {
				to.flow += res;
				to.rev->flow -= res;
				return res;
			}
		}
		return 0;
	}

	ll dinic() {
		ll res = 0, add, i;
		while (bfs()) {
			for (i = 0; i < n; i++)
				ptr[i] = 0;
			while (add = dfs(start, inf))
				res += add;
		}
		return res;
	}
};

int main() {
	/*ifstream in("input.txt");
	ofstream out("output.txt");*/

	ll n, m, cur, cur2, suma = 0, sumb = 0, i, j;
	cin >> n >> m;
	Network net(2 * n + 2, 2 * n, 2 * n + 1);
	for (i = 0; i < n; i++) {
		cin >> cur;
		suma += cur;
		net.addedge(2 * n, i, cur);
		net.addedge(i, i + n, inf);
	}
	for (i = 0; i < n; i++) {
		cin >> cur;
		sumb += cur;
		net.addedge(i + n, 2 * n + 1, cur);
	}
	for (i = 0; i < m; i++) {
		cin >> cur >> cur2;
		cur--;
		cur2--;
		net.addedge(cur, cur2 + n, inf);
		net.addedge(cur2, cur + n, inf);
	}

	ll flow = net.dinic();
	if ((flow == suma) && (flow == sumb)) {
		cout << "YES\n";
		vector<vector<ll> > matrix(n, vector<ll>(n, 0));
		for (i = 0; i < n; i++) {
			for (j = 1; j < net.edges[i].size(); j++)
				matrix[i][net.edges[i][j]->to - n] = net.edges[i][j]->flow;
			for (j = 0; j < n; j++)
				cout << matrix[i][j] << ' ';
			cout << '\n';
		}
	}
	else
		cout << "NO";

	return 0;
}