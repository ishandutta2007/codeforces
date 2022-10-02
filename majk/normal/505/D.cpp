#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> E, F;
vector<int> D;
vector<bool> V;

int dfs(int u) {
    if (V[u]) return 0;
    V[u] = true;
    int r = 1;
    for (int v:E[u]) r += dfs(v);
    for (int v:F[u]) r += dfs(v);
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int N, M; cin >> N >> M;
    E.resize(N);
    F.resize(N);
    V.assign(N, false);
    D.assign(N,0);
    for (int i = 0; i < M; ++i) {
        int u,v; cin >> u >> v;
        E[u-1].push_back(v-1);
        F[v-1].push_back(u-1);
        D[v-1]++;
    }

    vector<int> Q;
    for (int i = 0; i < N; ++i) if (D[i] == 0) Q.push_back(i);
    for (int q = 0; q < Q.size(); ++q) {
        for (int v:E[Q[q]]) if (!--D[v]) Q.push_back(v);
    }
    
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (D[i]) ans += dfs(i);
    }
    for (int i = 0; i < N; ++i) {
        if (!D[i]) ans += max(0, dfs(i)-1);
    }
    cout << ans << endl;
}