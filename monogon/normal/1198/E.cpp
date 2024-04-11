
#include <iostream>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>

#define ll long long
using namespace std;

struct edge {
    int v;
    ll flow;
    ll cap;
    int rev;
};

class Graph {
    int V;
    int *level;
    vector<edge> *adj;
public:
    Graph(int V) {
        this->V = V;
        adj = new vector<edge>[V];
        level = new int[V];
    }
    void addEdge(int u, int v, ll cap) {
        edge a{v, 0, cap, adj[v].size()};
        edge b{u, cap, cap, adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool BFS(int s, int t);
    ll sendFlow(int s, ll flow, int t, int start[]);
    ll maxFlow(int s, int t);
};

bool Graph::BFS(int s, int t) {
    for(int i = 0; i < V; i++) {
        level[i] = -1;
    }
    level[s] = 0;
    queue<int> q;
    q.push(s);
    while(q.size()) {
        int u = q.front();
        q.pop();
        for(edge e : adj[u]) {
            if(level[e.v] < 0 && e.flow < e.cap) {
                level[e.v] = level[u] + 1;
                q.push(e.v);
            }
        }
    }
    return level[t] >= 0;
}

ll Graph::sendFlow(int s, ll flow, int t, int start[]) {
    if(s == t) {
        return flow;
    }
    for(; start[s] < adj[s].size(); start[s]++) {
        edge &e = adj[s][start[s]];
        if(level[e.v] == level[s] + 1 && e.flow < e.cap) {
            ll curr_flow = min(flow, e.cap - e.flow);
            ll temp_flow = sendFlow(e.v, curr_flow, t, start);
            if(temp_flow > 0) {
                e.flow += temp_flow;
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}
ll Graph::maxFlow(int s, int t) {
    if(s == t) {
        return -1;
    }
    ll total = 0;
    int it = 0;
    int *start = new int[V + 1];
    while(BFS(s, t)) {
        for(int i = 0; i < V; i++) {
            start[i] = 0;
        }
        while(ll flow = sendFlow(s, LLONG_MAX, t, start)) {
            total += flow;
        }
        it++;
    }
    return total;
}

const int MAX_M = 55;

ll n, x1[MAX_M], y1[MAX_M], x2[MAX_M], y2[MAX_M];
set<ll> xset, yset;
vector<ll> xvec, yvec;
int m;

int main() {
    ios::sync_with_stdio(false);

    // read input and compress
    cin >> n >> m;
    if(m == 0) {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < m; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        x1[i]--;
        y1[i]--;
        xset.insert(x1[i]);
        xset.insert(x2[i]);
        yset.insert(y1[i]);
        yset.insert(y2[i]);
    }
    xvec = vector<ll>(xset.begin(), xset.end());
    yvec = vector<ll>(yset.begin(), yset.end());
    int W = xvec.size();
    int H = yvec.size();

    // row i : i, col i = W * i, source = W + H, sink = W + H + 1
    Graph g(W + H + 2);
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < W - 1; j++) {
            ll x = xvec[j];
            for(int k = 0; k < H - 1; k++) {
                ll y = yvec[k];
                if(x >= x1[i] && x < x2[i] && y >= y1[i] && y < y2[i]) {
                    // add edge with capacity width * height
                    g.addEdge(j, W + k, min(xvec[j + 1] - xvec[j], yvec[k + 1] - yvec[k]));
                }
            }
        }
    }
    for(int i = 0; i < W - 1; i++) {
        g.addEdge(W + H, i, xvec[i + 1] - xvec[i]);
    }
    for(int j = 0; j < H - 1; j++) {
        g.addEdge(W + j, W + H + 1, yvec[j + 1] - yvec[j]);
    }

    cout << g.maxFlow(W + H, W + H + 1) << endl;
}