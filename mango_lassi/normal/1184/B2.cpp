#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
using ll = long long;
const int INF = 1e9 + 7;

struct MaxFlow {
	struct edge {
		int a, b, c;
	};
	vector<edge> es;
	vector<vector<int> > g;
	vector<int> d, pt;
	MaxFlow(int n) : g(n+1), d(n+1), pt(n+1) {}
	void addEdge(int a, int b, int c) {
		es.push_back({a, b, c});
		g[a].push_back((int)es.size()-1);
		es.push_back({b, a, 0});
		g[b].push_back((int)es.size()-1);
	}
	bool bfs(int source, int sink) {
		queue<int> q({source});
		fill(d.begin(), d.end(), (int)g.size()+1);
		d[source]=0;
		while(!q.empty()) {
			int x=q.front();q.pop();
			if (x==sink) break;
			for (int k:g[x]) {
				edge& e=es[k];
				if (e.c>0&&d[e.b]>d[e.a]+1) {
					d[e.b]=d[e.a]+1;
					q.push(e.b);
				}
			}
		}
		return d[sink]!=(int)g.size()+1;
	}
	int flow(int x, int sink, int fl=INF) {
		if (x==sink||fl==0) return fl;
		for (int& i=pt[x];i<(int)g[x].size();i++) {
			edge& e=es[g[x][i]];
			edge& oe=es[g[x][i]^1];
			if (d[e.b]==d[e.a]+1) {
				if (int pf=flow(e.b, sink, min(e.c, fl))) {
					e.c-=pf;
					oe.c+=pf;
					return pf;
				}
			}
		}
		return 0;
	}
	int getMaxFlow(int source, int sink) {
		int r=0;
		while (bfs(source, sink)) {
			fill(pt.begin(), pt.end(), 0);
			while (int t=flow(source, sink)) r+=t;
		}
		return r;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	vector<vector<ll>> dist(n);
	for (int i = 0; i < n; ++i) {
		dist[i].resize(n, INF);
		dist[i][i] = 0;
	}

	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		dist[a][b] = 1;
		dist[b][a] = 1;
	}
	for (int i = 0; i < n; ++i) {
		for (int a = 0; a < n; ++a) {
			for (int b = 0; b < n; ++b) {
				dist[a][b] = min(dist[a][b], dist[a][i] + dist[i][b]);
			}
		}
	}

	int s, b;
	ll k, h;
	cin >> s >> b >> k >> h;

	int nn = s + b + 2;
	int source = nn-2;
	int sink = nn-1;
	MaxFlow dinic(nn);
	
	vector<tuple<int, int, int>> ships(s);
	for (int i = 0; i < s; ++i) {
		int loc, atk, fuel;
		cin >> loc >> atk >> fuel;
		--loc;
		ships[i] = tie(loc, atk, fuel);
		
		dinic.addEdge(source, i, 1);
	}
	for (int i = s; i < s+b; ++i) {
		int tar, def;
		cin >> tar >> def;
		--tar;
		for (int j = 0; j < s; ++j) {
			int loc, atk, fuel;
			tie(loc, atk, fuel) = ships[j];
			if (dist[loc][tar] <= fuel && atk >= def) {
				dinic.addEdge(j, i, 1);
			}
		}
		dinic.addEdge(i, sink, 1);
	}

	int flow = dinic.getMaxFlow(source, sink);
	ll res = min(flow * k, s * h);
	cout << res << '\n';
}