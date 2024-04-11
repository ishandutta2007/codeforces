// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 1005;

int n, k, f[N], sz[N], c, g[N][N];

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

vector<int> b[N];

void inline merge(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return;
    if (sz[x] > sz[y]) swap(x, y);
    f[x] = y, sz[y] += sz[x];
    for (int v: b[x]) b[y].pb(v);
}

void inline solve(vector<int> a) {
    if (a.size() <= 1) return;
    int m = a.size();
    vector<int> z; ++c;
    
    for (int i = 0; i < m; i += k) {
        int j = min(i + k - 1, m - 1);
        int now = a[i];
        for (int k = i + 1; k <= j; k++) {
            for (int x: b[now]) {
                for (int y: b[a[k]]) {
                    g[x][y] = c;
                }
            }
            merge(a[k], now);
            now = find(now);
        }
        z.pb(now);
    }
    solve(z);
}
 
int main() {
    read(n), read(k);
    vector<int> t;
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1, b[i].pb(i), t.pb(i);
    solve(t);
    printf("%d\n", c);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            printf("%d ", g[i][j]);
    
    return 0;
}