#include <bits/stdc++.h>

using namespace std;
typedef long long i64;
const int N = 2000 + 10;
struct Edge { int u, v, w; };
int n, cnt = 0;
i64 ans[N];
Edge e[N * N];

void chkmin(i64 &x, i64 y) {
    if(x > y) x = y;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = i + 1, w; j <= n; j++) {
            cin >> w;
            e[++cnt] = {i, j, w};
        }
    }
    sort(e + 1, e + cnt + 1, [&] (Edge a, Edge b) {
        return a.w < b.w;
    });
    memset(ans, 0x3f, sizeof(ans));
    for(int i = 1; i <= cnt; i++) {
        i64 ed = 1ll * (n - 3) * e[1].w + e[i].w * 2;
        int u = e[i].u, v = e[i].v, w = e[i].w;
        chkmin(ans[u], ans[v] + w - e[1].w);
        chkmin(ans[v], ans[u] + w - e[1].w);
        chkmin(ans[u], ed);
        chkmin(ans[v], ed);
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << endl;
    return 0;
}