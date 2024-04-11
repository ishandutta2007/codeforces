#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
ll b[maxN], g[maxN];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    for (int j = 1; j <= m; j++) {
        cin >> g[j];
    }
    sort(b + 1, b + n + 1);
    sort(g + 1, g + m + 1);
    if (b[n] > g[1]) {
        cout << -1;
        return 0;
    }
    if (b[n] == g[1]) {
        ll ans = 0;
        for (int i = 1; i < n; i++) ans += m * b[i];
        for (int i = 1; i <= m; i++) ans += g[i];
        cout << ans;
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n - 2; i++) ans += m * b[i];
    ans += (m - 1) * b[n - 1];
    ans += b[n];
    for (int i = 1; i <= m; i++) ans += g[i];
    cout << ans;
    return 0;
}