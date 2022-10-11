#include <bits/stdc++.h>

using namespace std;

const int mod = int(1e9) + 7;

struct graph {
    int n;
    vector<vector<pair<int, char>>> g;

    graph() {}

    inline void resize(int n) {
        if (int(g.size()) < n)
            g.resize(n);
    }

    inline void add_edge(int v, int u, char w) {
        resize(v + 1);
        resize(u + 1);
        g[v].emplace_back(u, w);
    }

    vector<int> dist;

    void bfs() {
        dist.resize(n, n);
        dist[0] = 0;
        vector<int> que{0};
        que.reserve(n);
        for (int st = 0; st < int(que.size()); st++) {
            int v = que[st];
            for (auto [u, i] : g[v])
                if (dist[u] > dist[v] + 1) {
                    dist[u] = dist[v] + 1;
                    que.push_back(u);
                }
        }
    }

    inline void solve(int sz) {
        n = int(g.size());
        bfs();
        vector<int> st{0};
        st.reserve(n);
        vector<int> c(n, -1);
        c[0] = 0;
        int num = 1;
        vector<int> ans(n);
        while (!st.empty()) {
            int i = int(st.size()) - 1;
            while (i >= 0 && c[st[i]] == c[st.back()])
                i--;
            vector<int> ord;
            for (int d = 0; d < 10; d++, num++)
                for (int j = i + 1; j < int(st.size()); j++)
                    for (auto [v, w] : g[st[j]])
                        if (dist[v] == dist[st[j]] + 1 && w == d && c[v] == -1) {
                            c[v] = num;
                            ans[v] = (ans[st[j]] * 10ll + d) % mod;
                            ord.push_back(v);
                        }
            while (int(st.size()) > i + 1)
                st.pop_back();
            reverse(ord.begin(), ord.end());
            for (auto v : ord)
                st.push_back(v);
        }
        for (int i = 1; i < sz; i++)
            cout << ans[i] << '\n';
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    graph gr;
    int sz = n;
    for (int i = 0; i < m; i++) {
        int v, u;
        cin >> v >> u;
        v--, u--;
        auto s = to_string(i + 1);
        for (int rep = 0; rep < 2; rep++) {
            int prev = v;
            for (int i = 0; i < int(s.size()) - 1; i++) {
                gr.add_edge(prev, sz, s[i] - '0');
                prev = sz++;
            }
            gr.add_edge(prev, u, s.back() - '0');
            swap(v, u);
        }
    }
    gr.solve(n);
}