#include <bits/stdc++.h>

using namespace std;

const int maxn = 1000006;
bool pr[maxn];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 2; i <= maxn; ++i) pr[i] = true;
    for (int i = 2; i <= maxn; ++i) if (pr[i]) for (int j = i * 2; j <= maxn; j += i) pr[j] = false;

    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n, e;
        cin >> n >> e;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i) cin >> a[i];
        vector<int> g(n + 1, 0);
        for (int i = 1; i <= n; ++i) if (a[i] > 1) g[i] = i; else g[i] = (i >= e ? g[i-e] : i - e);
        long long ans = 0;
        for (int i = 1; i <= n; ++i) {
            int u = g[i];
            if (u <= 0 || !pr[a[u]]) continue;
            int v = (u >= e ? g[u - e] : u - e);
            //cout << i << ' ' << u << ' ' << v <<' ' << '\n';
            ans += (u - v) / e;
            if (pr[a[i]]) --ans;
        }
        cout << ans << endl;
    }
    return 0;
}