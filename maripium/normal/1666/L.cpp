#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    
    int N, M, S; cin >> N >> M >> S; --S;
    vector<vector<int>> adj(N);
    for (int i = 0; i < M; ++i) {
      int v, u; cin >> v >> u;
      adj[--v].push_back(--u);
    };

    vector<int> par(N, -1);
    vector<int> root(N, -1);
    function<void(int, int, int)> dfs = [&](int v, int p, int r) {
        par[v] = p;
        root[v] = r;
        for (int u : adj[v]) {
            if (u == S) continue;
            if (root[u] == -1) {
                dfs(u, v, r);
            } else if (root[u] != r) {
                vector<int> p0;
                vector<int> p1;
                int s = u;
                while (s != -1) {
                  p0.push_back(s);
                  s = par[s];
                }
                s = v;
                while (s != -1) {
                  p1.push_back(s);
                  s = par[s];
                }
                reverse(p0.begin(), p0.end());
                reverse(p1.begin(), p1.end());
                p1.push_back(u);

                cout << "Possible\n";
                cout << int(p0.size()) << '\n';
                for (int v : p0) cout << v + 1 << ' '; cout << '\n';
                cout << int(p1.size()) << '\n';
                for (int v : p1) cout << v + 1 << ' '; cout << '\n';
                exit(0);
            }
        }
    };

    for (int v : adj[S]) {
        if (root[v] == -1) {

          dfs(v, S, v);
        } else {
          vector<int> p0 = {S, v};
          int s = v;
          vector<int> p1;
          while (s != -1) {
              p1.push_back(s);
              s = par[s];
          }
          reverse(p1.begin(), p1.end());

          cout << "Possible\n";
                cout << int(p0.size()) << '\n';
                for (int v : p0) cout << v + 1 << ' '; cout << '\n';
                cout << int(p1.size()) << '\n';
                for (int v : p1) cout << v + 1 << ' '; cout << '\n';
                exit(0);
        }
    }
    cout << "Impossible\n";
    return 0;
}