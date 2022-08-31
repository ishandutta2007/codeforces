#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef double ld;
typedef long long ll;
const int inf = 1e9;
struct edge{
    int v, f, w, id;
};
vector < pair < ll, ll > > path;
struct MinCost{
    // 1 - indexation
    int n;
    vector<vector<edge>> e;
    void init(int _n) {
        n = _n;
        e.resize(n + 1);
    }
    void add(int x, int y, int c, int w){
        e[x].push_back((edge){y, c, w, (int)e[y].size()});
        e[y].push_back((edge){x, 0, -w, (int)e[x].size()-1});
    }
    // first - flow, second - cost
    pair<int,int> solve(int S, int T){
        pair<int,int> flow = make_pair(0, 0);
        while(true){
            vector < int > f(n+1), g(n+1), vis(n+1), dis(n+1, inf);
            queue < int > q;
            q.push(S), f[S]=inf, dis[S]=0;
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for (auto &i : e[u]) {
                    if(i.f && dis[u] + i.w < dis[i.v]){
                        dis[i.v] = dis[u] + i.w, f[i.v] = min(f[u], i.f), g[i.v] = i.id;
                        if (!vis[i.v]) q.push(i.v);
                    }
                }
                vis[u] = 0;
            }
            if (!f[T]) break;
            path.emplace_back(f[T], dis[T]);
            flow.first += f[T], flow.second += f[T]*dis[T];
            for(int i = T; i != S;){
                auto &t = e[i][g[i]];
                t.f += f[T], e[t.v][t.id].f -= f[T], i=t.v;
            }
        }
        return flow;
    }
};
int n, m;
const int maxN = (int)1e6 + 100;
ll flow[maxN], tot_cost[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    MinCost mc;
    mc.init(n + 1);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        mc.add(u, v, 1, w);
    }
    mc.solve(1, n);
    for (int i = 0; i < path.size(); i++) {
        flow[i + 1] = flow[i] + path[i].first;
        tot_cost[i + 1] = tot_cost[i] + path[i].first * path[i].second;
//        cout << flow[i + 1] << " " << tot_cost[i + 1] << endl;
    }
    int q;
    cin >> q;
    while (q--) {
        int T;
        cin >> T;
        int l = 1;
        int r = path.size();
        auto compute = [&](int x) -> ld{
            assert(1 <= x && x <= path.size());
            return ((ld)T + tot_cost[x]) / flow[x];
        };
        /*while (r - l > 5) {
            int l1 = (2 * l + r) / 3;
            int r1 = (2 * r + l) / 3;
            if (compute(l1) < compute(r1)) r = r1;
            else l = l1;
        }*/
        ld best = 1e9;
        for (int i = l; i <= r; i++) best = min(best, compute(i));
        cout << fixed << setprecision(10) << best << '\n';
    }
    return 0;
}