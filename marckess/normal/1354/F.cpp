#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100, inf = 1e9;

struct FlowGraph {

    struct Edge {
        int to;
        int flow, cap, cost;
        Edge *res;

        Edge () : to(0), flow(0), cap(0), cost(0), res(0) {}
        Edge (int to, int flow, int cap, int cost) : to(to), flow(flow), cap(cap), cost(cost), res(0) {}
    
        void addFlow (int f) {
            flow += f;
            res->flow -= f;
        }
    };

    vector<vector<Edge*>> adj;
    vector<int> dis, pos;
    int n;

    FlowGraph (int n) : n(n), adj(n), dis(n), pos(n) {} 

    void add (int u, int v, int cap, int cost) {
        Edge *x = new Edge(v, 0, cap, cost);
        Edge *y = new Edge(u, cap, cap, -cost);
        x->res = y;
        y->res = x;
        adj[u].pb(x);
        adj[v].pb(y);
    }

    ii maxFlowMinCost (int s, int t) {
        vector<bool> inQueue(n);
        vector<int> dis(n), cap(n);
        vector<Edge*> par(n);
        ll maxFlow = 0, minCost = 0;

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

int n, k, a[MX], b[MX], res[MX];

void solve () {
	cin >> n >> k;
	forn (i, n) cin >> a[i] >> b[i];

	FlowGraph g(2 * n + 5);
	int s = g.n - 1, t = s - 2;

	forn (i, n) {
		g.add(s, i, 1, 0);

		forn (j, n) {
			if (j + 1 == n) {
				g.add(i, n + j, 1, -(a[i] + (k - 1) * b[i]));
			} else if (j < k - 1) {
				g.add(i, n + j, 1, -(a[i] + j * b[i]));
			} else {
				g.add(i, n + j, 1, -((k - 1) * b[i]));
			}
		}
	}

	forn (j, n)
		g.add(n + j, t, 1, 0);

	g.maxFlowMinCost(s, t);
	forn (i, n)
		for (auto *e : g.adj[i])
			if (e->to >= n && e->flow == e->cap)
				res[e->to - n] = i;

	vi v;
	forn (i, n) {
		v.pb(res[i] + 1);
		if (i < k - 1 || i + 1 == n) continue;
		v.pb(-(res[i] + 1));
	}

	cout << v.size() << endl;
	for (int r : v) cout << r << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}