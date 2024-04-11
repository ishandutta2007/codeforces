#include <bits/stdc++.h>
#define FOR(i, l, r) for(int i = l; i <= r; i++)
#define ROF(i, r, l) for(int i = r; i >= l; i--)
#define db double
#define ll long long
using namespace std;
const int N = 5e6 + 10;
int n, m;
int mn[N], a[N], mx, buc[N], L;
void dfs(int u, int mnv) {
    if(mn[u] <= mnv) return;
    FOR(i, mnv, min(m / u, mn[u] - 1)) if(mn[u * i] > i) dfs(u * i, i);
    FOR(i, L, min(m / u, mnv - 1)) if(mn[u * i] > mnv) dfs(u * i, mnv);
    if(a[u]) buc[mn[u]]--;
    mn[u] = mnv;
    if(a[u]) buc[mn[u]]++;
}
void add(int x, int y) {
    dfs(x * y, max(mn[x], y));
}
void solve() {
    cin >> n >> m;
    FOR(i, 1, m + 1) mn[i] = m + 1, a[i] = 0, buc[i] = 0;
    mx = m + 1;
    FOR(i, 1, n) {
        int x;
        cin >> x;
        a[x] = 1;
    }
    mn[1] = 1;
    FOR(i, 1, m) if(a[i]) buc[mn[i]]++;
    int ans = m + 1;
    L = m + 1;
    ROF(i, m, 2) {
        L = i;
        FOR(j, 1, m / i) add(j, i);
        while(buc[mx] == 0) mx--;
        if(mx <= m && !a[1]) ans = min(ans, mx - i);
    }
    while(buc[mx] == 0) mx--;
    if(a[1]) ans = min(ans, mx - 1);
    cout << ans << endl;
}
int main() {
    ios :: sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    for(cin >> t; t--; ) {
        solve();
    }
    return 0;
}