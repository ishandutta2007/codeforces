#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 2005;
typedef bitset < maxN > bs;
int n, m[2];
bs all[maxN];
bs rev[maxN];
bool a[2][maxN][maxN];
bool has[2][maxN][maxN];
int transform(int x) {
    if (x > 0) return 2 * (x - 1);
    else return (((-x) - 1) * 2) + 1;
}
bool bad[maxN];
bool used[maxN];
bool can[maxN][maxN];
int t;
void go(int v) {
    used[v] = true;
    for (int i = 0; i < t; i++) {
        if (can[v][i] && !used[i]) {
            used[i] = true;
            go(i);
        }
    }
}
bool nbad[maxN];
void lastDfs(int v) {
    nbad[v] = true;
    for (int j = 0; j < t; j++) {
        if (can[v][j] && !nbad[j]) {
            lastDfs(j);
        }
    }
}
void ok(int a, int b) {
    memset(used, 0, sizeof used);
    go(a);
    go(b);
    for (int i = 0; i < t; i++) {
        if (used[i] || used[i ^ 1]) continue;
        if (bad[i]) continue;
        bool ff = false;
        for (int j = 0; j < t; j++) {
            if (can[i][j] && used[j ^ 1]) ff = true;
        }
        if (!ff) {
            go(i);
        }
    }
    for (int i = 0; i < t; i++) {
        if (used[i]) lastDfs(i);
    }
    for (int i = 0; i < t; i++) {
        if (nbad[i] && nbad[i ^ 1]) assert(false);
        if (!used[i] && !used[i ^ 1]) assert(false);
    }
    for (int i = 0; i < n; i++) {
        assert(used[2 * i] ^ used[2 * i + 1]);
        if (used[2 * i]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    exit(0);
}
void dfs(int v) {
    used[v] = true;
    for (int i = 0; i < t; i++) {
        if (!can[i][v]) continue;
        if (used[i]) continue;
        bad[i] = true;
        dfs(i);
    }
}
void solve() {
    t = 2 * n;
    for (int i = 0; i < t; i++) {
        all[i] &= 0;
        all[i][i] = true;
        a[0][i][i] = true;
        for (int j = 0; j < t; j++) {
            if (!a[0][i][j]) continue;
            all[i][j] = true;
        }
    }
    for (int k = 0; k < t; k++) {
        for (int i = 0; i < t; i++) {
            if (!a[0][i][k]) continue;
            all[i] |= all[k];
        }
    }
    memset(bad, 0, sizeof bad);
    memset(used, 0, sizeof used);
    memset(can, 0, sizeof can);
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (all[i][j]) can[i][j] = true;
            if (all[i][j] && all[i][j ^ 1]) bad[i] = true;
        }
    }
    for (int i = 0; i < t; i++) {
        rev[i] &= 0;
        for (int j = 0; j < t; j++) {
            rev[i][j] = all[i][j ^ 1];
        }
    }
    for (int i = 0; i < t; i++) {
        if (!used[i] && bad[i]) dfs(i);
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            if (!has[1][i][j]) continue;
            if (bad[i] || bad[j]) continue;
            if (((rev[i] & all[j]).count()) > 0) continue;
            ok(i, j);
        }
    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < t; j++) {
            swap(a[1][i][j], a[0][i][j]);
            swap(has[1][i][j], has[0][i][j]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m[0] >> m[1];
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < m[i]; j++) {
            int x, y;
            cin >> x >> y;
            x = transform(x);
            y = transform(y);
            a[i][y ^ 1][x] = true;
            a[i][x ^ 1][y] = true;
            has[i][x ^ 1][y ^ 1] = true;
        }
    }
    for (int i = 0; i < 2; i++) {
        solve();
    }
    cout << "SIMILAR";
}