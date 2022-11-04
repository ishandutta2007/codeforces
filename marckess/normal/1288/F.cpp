#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int inf = 1e9;

struct FlowGraph {

    struct Edge {
        int to;
        int flow, cap, cost, ind;
        Edge *res;

        Edge () : to(0), flow(0), cap(0), cost(0), res(0) {}
        Edge (int to, int flow, int cap, int cost, int ind = -1) : to(to), flow(flow), cap(cap), cost(cost), ind(ind), res(0) {}
    
        void addFlow (int f) {
            flow += f;
            res->flow -= f;
        }
    };

    vector<vector<Edge*>> adj;
    vector<int> dis, pos;
    int n;

    FlowGraph (int n) : n(n), adj(n), dis(n), pos(n) {} 

    void add (int u, int v, int cap, int cost, int ind = -1) {
        Edge *x = new Edge(v, 0, cap, cost, ind);
        Edge *y = new Edge(u, 0, 0, -cost, ind);
        x->res = y;
        y->res = x;
        adj[u].pb(x);
        adj[v].pb(y);
    }

    ii maxFlowMinCost (int s, int t) {
        vector<bool> inQueue(n);
        vector<int> dis(n), cap(n);
        vector<Edge*> par(n);
        int maxFlow = 0, minCost = 0;

        while (1) {
            fill(all(dis), inf);
            fill(all(par), nullptr);
            fill(all(cap), 0);
            dis[s] = 0;
            cap[s] = inf;
            queue<int> q;
            q.push(s);

            while (q.size()) {
                int u = q.front();
                q.pop();
                inQueue[u] = 0;

                for (Edge *v : adj[u]) {
                    if (v->cap > v->flow && dis[v->to] > dis[u] + v->cost) {
                        dis[v->to] = dis[u] + v->cost;
                        par[v->to] = v;
                        cap[v->to] = min(cap[u], v->cap - v->flow);
                        
                        if (!inQueue[v->to]) {
                            q.push(v->to);
                            inQueue[v->to] = 1;
                        }
                    }
                }
            }

            if (!par[t]) break;

            maxFlow += cap[t];
            minCost += cap[t] * dis[t];
            for (int u = t; u != s; u = par[u]->res->to)
                par[u]->addFlow(cap[t]);
        }

        return {maxFlow, minCost};
    }
};

const int MX = 405;
int n1, n2, m, r, b, off, dis[MX], vis[MX], p[MX];
string s1, s2, rt;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n1 >> n2 >> m >> r >> b >> s1 >> s2;

	int tot = n1 + n2 + 10;
	int s = tot;
	int t = tot - 1;
	int _t = tot - 2;

	FlowGraph *g = new FlowGraph(tot + 1);
	g->add(_t, 0, inf, 0);

	for (int i = 0; i < n1; i++)
		if (s1[i] == 'R') {
			g->add(s, i + 1, 1, 0);
			g->add(0, t, 1, 0);
			g->add(0, i + 1, inf, 0);

			/*
			add(0, i + 1, 1, -inf, -1);
			add(0, i + 1, inf, 0, -1);
			*/
			off++;
		} else if (s1[i] == 'B') {
			g->add(s, _t, 1, 0);
			g->add(i + 1, t, 1, 0);
			g->add(i + 1, _t, inf, 0);

			/*
			add(i + 1, 404, 1, -inf, -1);
			add(i + 1, 404, inf, 0, -1);
			*/
			off++;
		} else {
			g->add(0, i + 1, inf, 0);
			g->add(i + 1, _t, inf, 0);
		}

	for (int i = 0; i < n2; i++)
		if (s2[i] == 'R') {
			g->add(s, _t, 1, 0);
			g->add(n1 + i + 1, t, 1, 0);
			g->add(n1 + i + 1, _t, inf, 0);

			/*
			add(n1 + i + 1, 404, 1, -inf, -1);
			add(n1 + i + 1, 404, inf, 0, -1);
			*/
			off++;
		} else if (s2[i] == 'B') {
			g->add(s, n1 + i + 1, 1, 0);
			g->add(0, t, 1, 0);
			g->add(0, n1 + i + 1, inf, 0);

			/*
			add(0, n1 + i + 1, 1, -inf, -1);
			add(0, n1 + i + 1, inf, 0, -1);
			*/
			off++;
		} else {
			g->add(0, n1 + i + 1, inf, 0);
			g->add(n1 + i + 1, _t, inf, 0);
		}

	rt.assign(m, 'U');
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;

		g->add(u + 1, n1 + v + 1, 1, r, i);
		g->add(n1 + v + 1, u + 1, 1, b, i);
	}

	ii res = g->maxFlowMinCost(s, t);

	if (res.fi != off) {
		cout << -1 << endl;
	} else {
		cout << res.se << endl;

		for (int i = 1; i <= n1; i++)
			for (auto * e : g->adj[i]) {
				if (e->flow == 1 && e->cost == r)
					rt[e->ind] = 'R';
				if (e->res->flow == 1 && e->res->cost == b)
					rt[e->ind] = 'B';
			}

		cout << rt << endl;
	}

	return 0;
}