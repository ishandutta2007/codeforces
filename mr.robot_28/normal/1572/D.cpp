#include<bits/stdc++.h>
#define X first
#define Y second
#define sz(a) (int)a.size()
using namespace std;
const int N = 5e5 + 100;
const int mod = 1e9 + 7;
vector <pair <int, int> > edges_weight[4 * N];
struct edge{
    int from, to, cap, flow, cost;
    edge(){}
    edge(int from_, int to_, int cap_, int flow_, int cost_):
        from(from_),
        to(to_),
        cap(cap_),
        flow(flow_), 
        cost(cost_){};
    int costTo(int v){
        if(v == to){
            return cost;
        }
        return -cost;
    }
    int capTo(int v){
        if(v == to){
            return cap - flow;
        }
        return flow;
    }
    int other(int v){
        if(v == to){
            return from;
        }
        return to;
    }
    void addFlow(int v, int fl){
        if(to == v){
            flow += fl;
        }
        else{
            flow -= fl;
        }
    }
};
vector <int> g[N];
vector <edge> edges;
void add_edge(int from, int to, int cap, int cost){
    edges.push_back(edge(from, to, cap, 0, cost));
    g[from].push_back(sz(edges) - 1);
    g[to].push_back(sz(edges) - 1);
}
int dist[N];
int vis[N];
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, k;
    cin >> n >> k;
    int m = (1 << n);
    vector <int> a(m);
    for(int i = 0; i < m; i++){
        cin >> a[i];
    }
    int t = (2 * n - 1) * (k - 1) + 1;
    for(int i = 0; i < m; i++){
        int c = __builtin_popcount(i);
        for(int j = 0; j < n; j++){
            if((1 << j) & i){
                continue;
            }
            int w = i | (1 << j);
            if(c % 2 == 0){
                edges_weight[a[i] + a[w]].push_back({i, w});
            }
            else{
                edges_weight[a[i] + a[w]].push_back({w, i});
            }
        }
    }
    vector <vector <int> > res_edges;
    for(int i = 2e6; i >= 0; i--){
        while(t > 0 && sz(edges_weight[i]) > 0){
            res_edges.push_back({edges_weight[i].back().X, edges_weight[i].back().Y, i});
            edges_weight[i].pop_back();
            t--;
        }
    }
    vector <int> uniq1, uniq2;
    for(auto p : res_edges){
        uniq1.push_back(p[0]);
        uniq2.push_back(p[1]);
    }
    sort(uniq1.begin(), uniq1.end());
    uniq1.resize(unique(uniq1.begin(), uniq1.end()) - uniq1.begin());
    sort(uniq2.begin(), uniq2.end());
    uniq2.resize(unique(uniq2.begin(), uniq2.end()) - uniq2.begin());
    int st = sz(uniq1) + sz(uniq2);
    int en = st + 1;
    n = en + 1;
    for(int x =0 ; x < sz(uniq1); x++){
        add_edge(st, x, 1, 0);
    }
    for(int y = 0; y < sz(uniq2); y++){
        add_edge(y + sz(uniq1), en, 1, 0);
    }
    for(auto p : res_edges){
        p[0] = lower_bound(uniq1.begin(), uniq1.end(), p[0]) - uniq1.begin();
        p[1] = lower_bound(uniq2.begin(), uniq2.end(), p[1]) - uniq2.begin();
        p[1] += sz(uniq1);
        add_edge(p[0], p[1], 1, -p[2]);
    }
    int sumcost = 0;
    while(k--){
        dist[st] = 0;
        vis[st] = 1;
        deque <int> q;
        q.push_back(st);
        for(int i = 0; i < n; i++){
            dist[i] = 1e9;
            vis[i] = 0;
        }
        dist[st] = 0;
        vector <int> p(n, -1);
        while(!q.empty()){
            int v = q.front();
            q.pop_front();
            vis[v] = 1;
            for(auto e : g[v]){
                int to = edges[e].other(v);
                int len = edges[e].costTo(to);
                int capa = edges[e].capTo(to);
                if(capa && dist[v] + len < dist[to]){
                    dist[to] = dist[v] + len;
                    p[to] = e;
                    if(vis[to] == 0){
                        q.push_back(to);
                    }
                    else if(vis[to] == 1){
                        q.push_front(to);
                    }
                    vis[to] = 1;
                }
            }
        }
        if(dist[en] == 1e9){
            break;
        }
        sumcost += dist[en];
        int ver = en;
        while(ver != st){
            int v1 = edges[p[ver]].other(ver);
            edges[p[ver]].addFlow(ver, 1);
            ver = v1;
        }
    }
    cout << -sumcost;
    return 0;
}