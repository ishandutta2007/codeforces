#include <bits/stdc++.h>

using namespace std;

int n, m, l;
long long a[100005];
int dad[100005];
int ans;
int mark[100005];

int anc(int u) {
    if (dad[u] == u) return u;
    return dad[u] = anc(dad[u]);
}
void join(int u, int v) {
    u = anc(u), v = anc(v);
    if (u == v) return;
    --ans;
    dad[v] = u;
}
void act(int u) {
    if (mark[u]) return;
    mark[u] = 1;
    ++ans;
    if (u > 1 && mark[u - 1]) join(u, u - 1);
    if (u < n && mark[u + 1]) join(u, u + 1);
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m >> l;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) dad[i] = i;
    for (int i = 1; i <= n; ++i) if (a[i] > l) act(i);
    while (m--) {
        int t; cin >> t;
        if (t == 0) cout << ans << '\n';
        else {
            int u, x; cin >> u >> x;
            a[u] += x;
            if (a[u] > l) act(u);
        }
    }
    return 0;
}