#include<bits/stdc++.h>
using namespace std;
/// damn you python

int const nax = 3e5 + 10;
vector <tuple <int, int, int>> a[nax];
int n;
int w[nax];
int sz[nax];
long long s;
long long cur;
vector <long long> cost[2];
void dfs (int nod, int parent) {
    sz[nod] = 0;
    for (auto &[i, w, c] : a[nod]) {
        if (i != parent) {
            dfs(i, nod);
            sz[nod] += sz[i];
            s -= 1LL * sz[i] * w;
            while (w > 0) {
                cost[c - 1].push_back(1LL * sz[i] * ((w + 1) / 2));
                w /= 2;
            }

        }
    }
    if (sz[nod] == 0) sz[nod] = 1;
}


void solve() {
    scanf("%d %lld", &n, &s);

    for (int i = 1 ; i < n ; ++ i) {
        int u, v, w, c;
        scanf("%d %d %d %d", &u, &v, &w, &c);
        a[u].emplace_back(v, w, c);
        a[v].emplace_back(u, w, c);
    }
    cost[0].clear();
    cost[1].clear();
    fill(sz, sz + n + 1 , 0);
    dfs(1, 0);

    for (int i = 0 ; i < 2 ; ++ i)
        sort(cost[i].begin(), cost[i].end(), greater <long long>());
    long long res = 0;

    for (long long &x : cost[0])
        res += x;
    int ans = 1e9;

    for (int i = int(cost[0].size()), j = 0 ; j <= int(cost[1].size()) ; ++ j) {
        while (i > 0 && s + res - cost[0][i - 1] >= 0) {
            res -= cost[0][i - 1];
            -- i;
        }
        if (res + s >= 0) ans = min(ans, 2 * j + i);
        if (j < int(cost[1].size())) {
            res += cost[1][j];
        }
    }

    printf("%d\n", ans);
}

int main () {
    int T;
    for (scanf("%d", &T); T -- ;) {
        solve();
        for (int i = 1 ; i <= n ; ++ i)
            a[i].clear();
    }
}