#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[3], b[3], INF = 1e9;

template<typename T>
struct flow_network{
    static constexpr T eps = (T)1e-9;
    int n;
    vector<vector<int>> adj;
    struct edge{
     int from, to;
     T capacity, flow;
    };
    vector<edge> edges;
    int source, sink;
    T flow = 0;
    flow_network(int n, int source, int sink): n(n), source(source), sink(sink), adj(n){ }
    void clear_flow(){
     for(auto &e: edges) e.flow = 0;
     flow = 0;
    }
    int insert(int from, int to, T forward_cap, T backward_cap){
     int ind = (int)edges.size();
     adj[from].push_back(ind);
     edges.push_back({from, to, forward_cap, 0});
     adj[to].push_back(ind + 1);
     edges.push_back({to, from, backward_cap, 0});
     return ind;
    }
    void add_flow(int i, T f){
     edges[i].flow += f;
     edges[i ^ 1].flow -= f;
    }
};
template<typename T>
struct dinic{
    static constexpr T inf = numeric_limits<T>::max();
    flow_network<T> &g;
    vector<int> ptr, level, q;
    dinic(flow_network<T> &g): g(g), ptr(g.n), level(g.n), q(g.n){ }
    bool bfs(){
     fill(level.begin(), level.end(), -1);
     q[0] = g.sink;
     level[g.sink] = 0;
     int beg = 0, end = 1;
     while(beg < end){
         int i = q[beg ++];
         for(auto ind: g.adj[i]){
             auto &e = g.edges[ind];
             auto &re = g.edges[ind ^ 1];
             if(re.capacity - re.flow > g.eps && level[e.to] == -1){
                 level[e.to] = level[i] + 1;
                 if(e.to == g.source) return true;
                 q[end ++] = e.to;
             }
         }
     }
     return false;
    }
    T dfs(int u, T w){
     if(u == g.sink) return w;
     int &j = ptr[u];
     while(j >= 0){
         int ind = g.adj[u][j];
         auto &e = g.edges[ind];
         if(e.capacity - e.flow > g.eps && level[e.to] == level[u] - 1){
             T F = dfs(e.to, min(e.capacity - e.flow, w));
             if(F > g.eps){
                 g.add_flow(ind, F);
                 return F;
             }
         }
         -- j;
     }
     return 0;
    }
    T max_flow(){ // O(V^2 E) ( O(E min(V^2/3, E^1/2)) for unit network )
     while(bfs()){
         for(int i = 0; i < g.n; ++ i) ptr[i] = (int)g.adj[i].size() - 1;
         T sum = 0;
         while(1){
             T add = dfs(g.source, inf);
             if(add <= g.eps) break;
             sum += add;
         }
         if(sum <= g.eps) break;
         g.flow += sum;
     }
     return g.flow;
    }
    pair<T, vector<bool>> min_cut(){
     T cut = max_flow();
     vector<bool> res(g.n);
     for(int i = 0; i < g.n; ++ i) res[i] = (level[i] != -1);
     return {cut, res};
    }
};

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin >> n;
    for(int i=0;i<3;i++) cin >> a[i];
    for(int i=0;i<3;i++) cin >> b[i];

    int source = 0, sink = 7;
    flow_network<int> g(8, source, sink);
    for(int i=0;i<3;i++) g.insert(source, 1 + i, a[i], 0);
    for(int i=0;i<3;i++) g.insert(4 + i, sink, b[i], 0);
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) if((i + 1) % 3 != j) g.insert(1 + i, 4 + j, INF, 0);

    dinic F(g);
    cout << n - F.max_flow() << " ";
    cout << min(a[0], b[1]) + min(a[1], b[2]) + min(a[2], b[0]);
}