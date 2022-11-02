#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

struct Dsu {
    vector<int> p;
    vector<int> rank;
    vector<int*> old_addr;
    vector<int> old_val;

    Dsu(int n): p(n), rank(n) {
        iota(p.begin(), p.end(), 0);
    }

    int get(int v) {
        return v == p[v] ? p[v] : get(p[v]);
    }

    bool unite(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        old_addr.push_back(&p[b]);
        old_val.push_back(p[b]);
        old_addr.push_back(&rank[a]);
        old_val.push_back(rank[a]);
        p[b] = a;
        if (rank[a] == rank[b])
            ++rank[a];  
        return true;
    }

    void reset() {
        old_addr.clear();
        old_val.clear();
    }

    void undo() {
        for (int i = (int)old_val.size() - 1; i >= 0; i--)
            *(old_addr[i]) = old_val[i]; 
    }
};

struct Edge {
    int a;
    int b;
    int w;
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    unordered_map<int, unordered_map<int, vector<int>>> q_at;
    unordered_set<int> bad;
    vector<Edge> edges;
    map<int, vector<int>> edges_at;

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, w;
        cin >> a >> b >> w;
        --a;
        --b;
        edges.push_back({a, b, w});
        edges_at[w].push_back(i);
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++) {
            int id;
            cin >> id;
            --id;
            q_at[edges[id].w][i].push_back(id);
        }
    }

    Dsu dsu(n);
    for (const auto& kv : edges_at) {
        dsu.reset();
        auto w = kv.first;
        const auto& es = kv.second;
        for (const auto& k_mp : q_at[w]) {
            int id = k_mp.first;
            const auto& cur_es = k_mp.second;
            for (int i : cur_es)
                if (!dsu.unite(edges[i].a, edges[i].b))
                    bad.insert(id);
            dsu.undo();
        }
        for (int i : es)
            dsu.unite(edges[i].a, edges[i].b);
    }
    
    for (int i = 0; i < q; i++)
        cout << (bad.count(i) ? "NO" : "YES") << "\n";
}