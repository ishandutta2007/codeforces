#include <bits/stdc++.h>
using namespace std;

const int N = 1E5 + 5, M = 1E5 + 5;

int n, m, a[N], dsu[N];
long long ans = 0;

struct edge {
    int u, v, w;
} e[M];

int trace(int u) {
    return dsu[u] < 0 ? u : dsu[u] = trace(dsu[u]);
}

void connect(int u, int v, int w) {
    if ((u = trace(u)) == (v = trace(v))) {
        return;
    }
    ans += 1LL * dsu[u] * dsu[v] * w;
    if (dsu[u] > dsu[v]) {
        swap(u, v);
    }
    dsu[u] += dsu[v];
    dsu[v] = u;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dsu[i] = -1;
    }
    for (int i = 1; i <= m; i++) {
        cin >> e[i].u >> e[i].v;
        e[i].w = min(a[e[i].u], a[e[i].v]);
    }
    sort(e + 1, e + m + 1, [](const edge &u, const edge &v) {
        return u.w > v.w;
    });
    for (int i = 1; i <= m; i++) {
        connect(e[i].u, e[i].v, e[i].w);
    }
    cout << fixed << setprecision(6) << 1.0 * ans / (1LL * n * (n - 1) / 2);
}