#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 301000;
int n, m, dp[N], tmp[N];
vector<pair<int,int>> e[N];
int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[w].push_back({u, v});
    }
    for (int w = 1; w <= 100000; w++) {
        for (auto [u, v] : e[w]) {
            tmp[v] = max({tmp[v], dp[u] + 1, dp[v]});
        }
        for (auto [u, v] : e[w]) {
            dp[v] = tmp[v];
        }
    }
    printf("%d\n", *max_element(dp + 1, dp + n +1));
}