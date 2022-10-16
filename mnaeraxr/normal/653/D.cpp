#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 100010;

struct edge{
	double cap, flow;
	int to, rev;
	bool dir;

	edge(double cap, double flow, int to, int rev, bool dir) :
		cap(cap), flow(flow), to(to), rev(rev), dir(dir){}
};

struct graph{
	int n;
	vector<vector<edge>> adj;

	graph(int n) : n(n){
		adj = vector<vector<edge>>(n);
	}

	void add_edge(int u, int v, double w){
		edge e1(w, 0, v, (int)adj[v].size(), true);
		edge e2(w, w, u, (int)adj[u].size(), false);

		adj[u].push_back(e1);
		adj[v].push_back(e2);
	}

	void init(){
		for (int i = 0; i < n; ++i)
			for (auto &e : adj[i])
				e.flow = e.dir ? 0 : e.cap;
	}

	void augment(int u, int i, double f){
		edge &e = adj[u][i];
		e.flow += f;
		adj[e.to][e.rev].flow -= f;
	}

	bool push(double f){
		vector<int> from(n, -1);
		vector<int> index(n, -1);
		from[0] = -2;

		queue<int> q; q.push(0);

		while (!q.empty()){
			int u = q.front(); q.pop();

			for (int i = 0; i < (int)adj[u].size(); ++i){
				auto e = adj[u][i];
				if (from[e.to] == -1 && e.cap - e.flow >= f){
					from[e.to] = u;
					index[e.to] = i;

					q.push(e.to);
				}
			}
		}

		if (from[n - 1] != -1){
			int s = n - 1;

			while (s != 0){
				int i = index[s];
				s = from[s];
				augment(s, i, f);
			}

			return true;
		}
		return false;
	}

	bool test(int total, double f){
		init();

		int s = 1;

		while (total){
			if (s == 0) return false;
			if (push(f * s)){
				total -= s;
				s = min(total, 2 * s);
			}
			else{
				s /= 2;
			}
		}

		return true;
	}
};

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, x;
	cin >> n >> m >> x;

	graph g(n);
	double lo = 0, hi = 0;

	for (int i = 0; i < m; ++i){
		int u, v;
		double w;
		cin >> u >> v >> w;
		g.add_edge(u - 1, v - 1, w);
		hi += w;
	}

	hi /= x;

	int i;

	for (i = 0; (i < 100) && (x * hi > x * lo + 1e-8); ++i){
		double m = (lo + hi) / 2;
		if (g.test(x, m)) lo = m;
		else hi = m;
	}

//	cout << i << endl;

	cout.precision(17);
	cout << fixed << lo * x << endl;

	return 0;
}