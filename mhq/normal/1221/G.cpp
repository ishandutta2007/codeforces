#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 42;
vector < int > g[maxN];
int deg[maxN];
bool ed[maxN][maxN];
ll f() {
    return (1LL << n);
}
const int maxK = 20;
bool bad[(1 << maxK) + 10];
int from[(1 << maxK) + 10];
bool other_bad[(1 << maxK) + 10];
int cnt[(1 << maxK) + 10];
ll indep() {
    int half = n / 2;
    for (int i = 0; i < half; i++) {
        for (int j = i + 1; j < half; j++) {
            if (ed[i][j]) {
                bad[(1 << i) + (1 << j)] = true;
            }
        }
        for (int j = half; j < n; j++) {
            if (ed[i][j]) {
                from[(1 << i)] |= (1 << (j - half));
            }
        }
    }
    for (int bit = 0; bit < half; bit++) {
        for (int mask = 0; mask < (1 << half); mask++) {
            if (mask & (1 << bit)) {
                bad[mask] |= bad[mask ^ (1 << bit)];
                from[mask] |= from[mask ^ (1 << bit)];
            }
        }
    }
    int other_half = n - half;
    for (int i = half; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ed[i][j]) {
                other_bad[(1 << (i - half)) + (1 << (j - half))] = true;
            }
        }
    }
    for (int bit = 0; bit < other_half; bit++) {
        for (int mask = 0; mask < (1 << other_half); mask++) {
            if (mask & (1 << bit)) {
                other_bad[mask] |= other_bad[mask ^ (1 << bit)];
            }
        }
    }
    for (int mask = 0; mask < (1 << other_half); mask++) {
        if (!other_bad[mask]) cnt[mask] = 1;
    }
    for (int bit = 0; bit < other_half; bit++) {
        for (int mask = 0; mask < (1 << other_half); mask++) {
            if (mask & (1 << bit)) {
                cnt[mask] += cnt[mask ^ (1 << bit)];
            }
        }
    }
    int all = (1 << other_half) - 1;
    ll tot = 0;
    for (int my_mask = 0; my_mask < (1 << half); my_mask++) {
        if (bad[my_mask]) continue;
        int bad_guys = from[my_mask];
        int good_guys = all ^ bad_guys;
        tot += cnt[good_guys];
    }
    return tot;
}
bool used[maxN];
void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        dfs(to);
    }
}
ll ones() {
    // just number of conn
    int tot = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            dfs(i);
            tot++;
        }
    }
    return (1LL << tot);
}
ll f01() {
    int tot = 0;
    for (int i = 0; i < n; i++) if (deg[i] == 0) tot++;
    return (1LL << tot);
}
int clr[maxN];
bool ALL_OK = true;
void other_dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) {
            if (clr[to] != clr[v] ^ 1) {
                ALL_OK = false;
                return;
            }
        }
        else {
            clr[to] = clr[v] ^ 1;
            other_dfs(to);
        }
    }
}
ll f02() {
    int tot = 0;
    memset(used, 0, sizeof used);
    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            tot++;
            other_dfs(i);
        }
    }
    if (!ALL_OK) return 0;
    return (1LL << tot);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    if (m == 0) {
        cout << 0;
        return 0;
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        deg[a]++;
        deg[b]++;
        g[a].push_back(b);
        g[b].push_back(a);
        ed[a][b] = ed[b][a] = true;
    }
    ll x = f();
    ll y = indep();
    ll z = ones();
    ll t = f01();
    ll q = f02();
    cout << x - 2 * y - z + 2 * t + q;

    return 0;
}