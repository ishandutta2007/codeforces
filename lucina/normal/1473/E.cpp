#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;
const int64_t INF = 1e17;
template <typename T>
using min_heap = priority_queue <T, vector <T>, greater <T>>;
using state = tuple <int64_t, int, char, char>;
vector <pair <int, int>> g[nax];
int64_t dp[nax][2][2];
min_heap <state> pq;
int n, m;

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1, u, v, w ; i <= m ; ++ i) {
        scanf("%d %d %d", &u, &v, &w);
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }

    for (int i = 1 ; i <= n ; ++ i) {
        for (int w = 0 ; w < 2 ; ++ w)
            dp[i][w][0] = dp[i][w][1] = INF;
    }

    dp[1][0][0] = 0;
    pq.emplace(0LL, 1, 0, 0);

    while (!pq.empty()) {

        auto [val, node, free_used, add_min] = pq.top();
        pq.pop();

        if (dp[node][free_used][add_min] != val) continue;

        for (const auto &[to, w] : g[node]) {
            if (val + w < dp[to][free_used][add_min]) {
                dp[to][free_used][add_min] = val + w;
                pq.emplace(val + w, to, free_used, add_min);
            }

            if (!free_used && val < dp[to][1][add_min]) {
                dp[to][1][add_min] = val;
                pq.emplace(val, to, 1, add_min);
            }

            if (!add_min && val + w + w < dp[to][free_used][1]) {
                dp[to][free_used][1] = val + w + w;
                pq.emplace(val + w + w, to, free_used, 1);
            }
        }
    }

    for (auto &[x, y] : g[1]) dp[x][1][1] = min(dp[x][1][1], int64_t(y));

    for (int i = 2 ; i <= n ; ++ i) {
        printf("%lld ", dp[i][1][1]);
    }
    puts("");
}