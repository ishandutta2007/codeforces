#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 5;

int bs[N];
int pa[2][N];
vector<int> g[N];

void dfs(int u, int id) {
    bs[u] |= 1 << id;
    for (int v : g[u]) {
        if ((bs[v] >> id) & 1) continue;
        pa[id][v] = u;
        dfs(v, id);
    }
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, s; cin >> n >> m >> s;
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
    }
    for (int k = 0; k < 20; ++k) {
        vector<int> vs[2];
        for (int v : g[s]) {
            vs[(v >> k) & 1].push_back(v);
        }
        for (int i = 1; i <= n; ++i)
            bs[i] = 0;
        bs[s] = 3;
        for (int o = 0; o < 2; ++o) {
            for (int v : vs[o]) {
                if ((bs[v] >> o) & 1) continue;
                pa[o][v] = s;
                dfs(v, o);
            }
        }
        int found = -1;
        for (int i = 1; i <= n; ++i) {
            if (bs[i] == 3 && i != s) found = i;
        }
        if (found != -1) {
            cout << "Possible\n";
            vector<int> p1 = {found}, p2 = {found};
            while (p1.back() != s) {
                p1.push_back(pa[0][p1.back()]);
            }
            while (p2.back() != s) {
                p2.push_back(pa[1][p2.back()]);
            }
            set<int> st;
            for (auto x: p2) st.insert(x);
            int meet = found;
            for (auto x : p1) {
                if (x != s and st.find(x) != st.end())
                    meet = x;
            }
            reverse(p1.begin(), p1.end());
            reverse(p2.begin(), p2.end());
            while (p1.back() != meet) p1.pop_back();
            while (p2.back() != meet) p2.pop_back();
            cout << p1.size() << '\n';
            for (size_t i = 0; i < p1.size(); ++i)
                cout << p1[i] << " \n"[i + 1 == p1.size()];
            cout << p2.size() << '\n';
            for (size_t i = 0; i < p2.size(); ++i)
                cout << p2[i] << " \n"[i + 1 == p2.size()];

            return 0;
        }
    }
    cout << "Impossible\n";
    return 0;
}