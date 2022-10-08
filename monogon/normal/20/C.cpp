
#include <bits/stdc++.h>

#define ll long long
using namespace std;

struct edge {
    int v;
    ll d;
    edge(int v, ll d): v(v), d(d) {}
    bool operator<(const edge &e) const {
        return d == e.d ? v > e.v : d > e.d;
    }
};

const int N = 1e5 + 5;

int n, m, a, b;
ll w;
vector<edge> adj[N];
ll dist[N];
int par[N];
const ll INF = 1e18;

void dijkstra(int s) {
    fill(par, par + N, -1);
    fill(dist, dist + N, INF);
    priority_queue<edge> Q;
    Q.emplace(s, dist[s] = 0);
    while(Q.size()) {
        edge e = Q.top();
        Q.pop();
        for(edge f : adj[e.v]) {
            if(f.d + e.d < dist[f.v]) {
                Q.emplace(f.v, dist[f.v] = f.d + e.d);
                par[f.v] = e.v;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    while(m--) {
        cin >> a >> b >> w;
        adj[a].emplace_back(b, w);
        adj[b].emplace_back(a, w);
    }
    dijkstra(1);
    if(dist[n] == INF) {
        cout << -1 << endl;
        return 0;
    }
    stack<int> st;
    st.push(n);
    while(par[st.top()] != -1) {
        st.push(par[st.top()]);
    }
    while(st.size()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}