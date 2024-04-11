#include <bits/stdc++.h>

using namespace std;

const int N = 4010;
vector<int> init_g[N];
vector<int> init_id[N];
vector<int> rev_init_g[N];
vector<int> rev_init_id[N];

namespace MaxFlow {
    const int INF = (int)1e9;
 
    struct Edge {
        int from;
        int to;
        int flow;
        int cap;
        int id;
 
        Edge(int from_, int to_, int cap_, int id_): from(from_), to(to_), flow(0), cap(cap_), id(id_) {}
    };
 
    struct Flow {
        vector<Edge> es;
        vector<vector<int>> g;
        vector<int> dist;
        vector<int> start;
        int st{-1};
        int en{-1};
 
        Flow(int n): g(n), dist(n), start(n) {}
 
        void add_edge(int from, int to, int cap, int id) {
            g[from].push_back(es.size());
            g[to].push_back(es.size() + 1);
            es.emplace_back(from, to, cap, id);
            es.emplace_back(to, from, 0, -id);
        }
 
        bool bfs() {
            fill(dist.begin(), dist.end(), INF);
            queue<int> q;
            dist[st] = 0;
            q.push(st);
            while (!q.empty()) {
                int v = q.front();
                q.pop();
                for (int i : g[v])
                    if (es[i].cap - es[i].flow != 0 && dist[es[i].to] > dist[v] + 1) {
                        dist[es[i].to] = dist[v] + 1;
                        q.push(es[i].to);
                    }
            }
            return dist[en] != INF;
        }
 
        int dfs(int v, int lim) {
            if (v == en)
                return lim;
            if (dist[v] >= dist[en])
                return 0;
            for (; start[v] < (int)g[v].size(); start[v]++) {
                int i = g[v][start[v]];
                if (es[i].cap - es[i].flow != 0 && dist[es[i].to] == dist[v] + 1) {
                    int add = dfs(es[i].to, min(lim, es[i].cap - es[i].flow));
                    if (add != 0) {
                        es[i].flow += add;
                        es[i ^ 1].flow -= add;
                        return add;
                    }
                }
            }
            return 0;
        }
 
        int get_flow(int st_, int en_) {
            st = st_;
            en = en_;
            int flow = 0;
            while (bfs()) {
                fill(start.begin(), start.end(), 0);
                int add = 0;
                while ((add = dfs(st, INF)) != 0)
                    flow += add;
            }
            return flow;
        }
    };
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.setf(ios::fixed);
    cout.precision(20);
    
    int l, r, m;
    cin >> l >> r >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        init_g[a].push_back(b);
        init_id[a].push_back(i + 1);
        rev_init_g[b].push_back(a);
        rev_init_id[b].push_back(i + 1);
    }
    cout << 0 << "\n";
    int min_d = N;
    for (int i = 0; i < l; i++)
        min_d = min<int>(min_d, init_g[i].size());
    for (int i = 0; i < r; i++)
        min_d = min<int>(min_d, rev_init_g[i].size());
    for (int k = 1; k <= min_d; k++) {
        int sz = l + r + 2;
        MaxFlow::Flow G(sz);
        for (int i = 0; i < l; i++)
            G.add_edge(sz - 2, i, k, 0);
        for (int i = 0; i < r; i++)
            G.add_edge(i + l, sz - 1, k, 0);
        for (int v = 0; v < l; v++)
            for (int i = 0; i < init_g[v].size(); i++) {
                int to = init_g[v][i];
                int id = init_id[v][i];
                G.add_edge(v, l + to, 1, id);
            }
        G.get_flow(sz - 2, sz - 1);
        set<int> ans;
        for (int v = 0; v < l; v++)
            for (int i : G.g[v]) {
                const auto& e = G.es[i];
                if (e.id > 0 && e.flow == 1)
                    ans.insert(e.id);
            }
        for (int i = 0; i < l; i++) {
            int cnt = 0;
            for (int e : init_id[i])
                if (ans.count(e))
                    cnt++;
            for (int e : init_id[i])
                if (cnt < k && !ans.count(e)) {
                    ans.insert(e);
                    cnt++;
                }
        }
        for (int i = 0; i < r; i++) {
            int cnt = 0;
            for (int e : rev_init_id[i])
                if (ans.count(e))
                    cnt++;
            for (int e : rev_init_id[i])
                if (cnt < k && !ans.count(e)) {
                    ans.insert(e);
                    cnt++;
                }
        }
        cout << ans.size() << " ";
        for (int e : ans)
            cout << e << " ";
        cout << "\n";
    }
}