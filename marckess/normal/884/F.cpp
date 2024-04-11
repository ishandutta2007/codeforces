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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int inf = 1e9, MX = 200;

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

int n, b[MX];
string s;

FlowGraph g(MX);

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	forn (i, n) cin >> b[i];

	for (int i = 0; i < n; i++)
		g.add(0, s[i] - 'a' + 2, 1, 0);

	for (int i = 0; i < n / 2; i++) {
		for (char c = 'a'; c <= 'z'; c++) {
			int cost = 0;
			
			if (s[i] == c && s[n - i - 1] == c) cost = max(b[i], b[n - i - 1]);
			else if (s[i] == c) cost = b[i];
			else if (s[n - i - 1] == c) cost = b[n - i - 1]; 

			g.add(c - 'a' + 2, 30 + i, 1, -cost);
		}

		g.add(30 + i, 1, 2, 0);
	}

	cout << -g.maxFlowMinCost(0, 1).se << endl;

	return 0;
}