/*
    27.03.2019 22:23:22
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

vector<long long> w;
int n;
vector<vector<pair<int, long long>>> g;
vector<pair<long long, long long>> best;
vector<bool> u;

void dfs(int v) {
    u[v] = true;
    best[v] = {0, 0};
    for (auto k : g[v]) {
        if (!u[k.first]) {
            dfs(k.first);
            long long d = w[k.first] - k.second;
            if (best[k.first].first + d >= best[v].first) {
                best[v].second = best[v].first;
                best[v].first = best[k.first].first + d;
            } else if (best[k.first].first + d > best[v].second) {
                best[v].second = best[k.first].first + d;
            }
        }
    }
}

int main() {
    cin >> n;
    g.resize(n);
    w.resize(n);
    best.resize(n);
    u.assign(n, false);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        --u; --v;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    dfs(0);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans = max(ans, best[i].first + best[i].second + w[i]);
    }
    cout << ans << '\n';
    return 0;
}