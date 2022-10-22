#include<bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
#define rep(i,n) for(int i=0; i<(n); i++)

int N;
vector<vector<int>> E;
int Z[100000];
int P[100000];

void dfs(int p = 0) {
    Z[p] = 1;
    for (int e : E[p]) {
        if (P[p] == e) continue;
        P[e] = p;
        dfs(e);
        Z[p] += Z[e];
    }
}
pair<int, int> Centroid() {
    P[0] = -1;
    dfs();
    int c = 0;
    while (true) {
        bool ok = true;
        for (int e : E[c]) {
            if (Z[e] <= N / 2) continue;
            Z[c] -= Z[e];
            Z[e] += Z[c];
            P[e] = -1; P[c] = e;
            c = e;
            ok = false;
            break;
        }
        if (ok) break;
    }
    for (int e : E[c]) if (Z[e] * 2 == N) return{ c,e };
    return { c,c };
}

bool F[100000] = {};
void dfs2(int p) {
    F[p] = true;
    for (int e : E[p]) {
        if (P[p] == e) continue;
        dfs2(e);
    }
}

void loop() {
    scanf("%d", &N);
    E.resize(N);
    rep(i, N - 1) {
        int u, v; scanf("%d%d", &u, &v); u--; v--;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    auto c = Centroid();
    int ans[2][2];
    if (c.first == c.second) {
        rep(i, 2) { ans[i][0] = 0; ans[i][1] = E[0][0]; }
    }
    else {
        dfs2(c.second);
        int leaf = -1;
        rep(i, N) if (F[i]) if (E[i].size() == 1) leaf = i;
        ans[0][0] = leaf; ans[0][1] = E[leaf][0];
        ans[1][0] = leaf; ans[1][1] = c.first;
    }

    rep(i, 2) printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);

    E.clear();
    rep(i, N) F[i] = false;
}

int main() {
    int T; scanf("%d", &T);
    while (T--) loop();
    return 0;
}