#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define x first
#define y second
#define sz(a) (int)a.size()
const int mod = 1e9 + 7;

const int N = 2100;

int n, m;
int A[N];

struct edge {
	int a, b, cap, flow;
	ll cost1, cost2;
	edge() : a(0), b(0), cap(0), flow(0), cost1(0), cost2(0){}
	edge(int a_, int b_, int cap_, int cost_):
	 	a(a_),
	 	b(b_),
	 	cap(cap_),
	 	cost1(cost_),
	 	cost2(-cost_),
	 	flow(0){}
	int other(int v) {
		return (v == a) ? b : a; 
	}
	int capTo(int v) {
		if (v == b) {
			return cap - flow;
		}
		return flow;
	}
	ll costTo(int v) {
		if (v == b) {
			return cost1;
		}
		return cost2;
	}
	void addFlow(int v, int fl) {
		if (v == b) {
			flow += fl;
		}
		else {
			flow -= fl;
		}
	}
} edges[N * 5];

vector <int> g[N];
int p[N];
ll dist[N];
ll dist1[N];
int id[N];

int it = 0;

void calculate_dist(int st) {
	for (int i = 0; i < n + 2; i++) {
		dist[i] = 1e18;
	}
	dist[st] = 0;
	for (int i = 0; i < n + 2; i++) {
		for (int j = 0; j < it; j++) {
			int from = edges[j].a;
			int to = edges[j].b;
		//cout << from << " " << to << " " << edges[j].cost1 << " " << edges[j].cost2 << " " << dist[from] << " " << dist[to] << "\n";
	    	if (dist[to] > dist[from] + edges[j].cost1) {
				dist[to] = dist[from] + edges[j].cost1;
			}
			if (from != n && to != n + 1) {
				if (dist[from] > dist[to] + edges[j].cost2) {
					dist[from] = dist[to] + edges[j].cost2;
				}
			}
		//	cout << dist[from] << " " << dist[to] << "\n";
		}
	}
	for (int j = 0; j < it; j++) {
		int from = edges[j].a;
		int to = edges[j].b;
		edges[j].cost1 += dist[from] - dist[to];
		edges[j].cost2 += dist[to] - dist[from];
	}
	for (int i = 0; i < n + 2; i++) {
		for (auto e : g[i]) {
			assert(edges[e].costTo(edges[e].other(i)) >= 0);
		}
	}
}

bool iteration(int st, int end) {
	for (int i = 0; i < n + 2; i++) {
		dist1[i] = 1e18;
		p[i] = -1;
		id[i] = 0;
	}
	dist1[st] = 0;
	deque <int> q;
	q.push_back(st);
	while (sz(q)) {
		int v = q.front();
		q.pop_front();
		//cout << v << " " << dist1[v] << "\n";
		id[v] = 1;
		for (auto e : g[v]) {
			int to = edges[e].other(v);
			int capTo = edges[e].capTo(to);
			ll costTo = edges[e].costTo(to);
			if (capTo && dist1[to] > dist1[v] + costTo) {
				dist1[to] = dist1[v] + costTo;
				if (id[to] == 0) {
					q.push_back(to);
				}
				else if(id[to] == 1) {
					q.push_front(to);
				}
				id[to] = 1;
				p[to] = e;
			}
		}
	}
	//cout << dist1[end] << " " << dist[end] <<  "\n";
	return dist1[end] + dist[end] < 0;
}

void add_edge(int a, int b, int fl, int c) {
	edges[it] = edge(a, b, fl, c);
	g[a].push_back(it);
	g[b].push_back(it);
	it++;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		edges[it++] = edge(n, i, 1, 0);
		g[n].push_back(it - 1);
		edges[it++] = edge(i, n + 1, 1, 0);
		g[i].push_back(it - 1);
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		add_edge(x, y, 1e9, - A[x] + A[y]);
	}
	calculate_dist(n);
	while (iteration(n, n + 1)) {
		int fl = 1e9;
		for (int v = n + 1; v != n; v = edges[p[v]].other(v)) {
			fl = min(fl, edges[p[v]].capTo(v));
		}
		for (int v = n + 1; v != n; v = edges[p[v]].other(v)) {
			edges[p[v]].addFlow(v, fl);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << A[i] - (dist1[i] + dist[i]) << " ";
	}
	return 0;
}