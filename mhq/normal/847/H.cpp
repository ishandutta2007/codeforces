#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int maxn = 5e5;
ll a[maxn];
ll fpm[maxn], fsm[maxn];
ll g[maxn], f[maxn];
int n;
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    fpm[1] = a[1];
    for (int i = 2; i <= n; i++) fpm[i] = max(fpm[i - 1] + 1, a[i]);
    fsm[n] = a[n];
    for (int i = n - 1; i >= 1; i--) fsm[i] = max(fsm[i + 1] + 1, a[i]);
    for (int i = 1; i <= n; i++) f[i] = fpm[i] - a[i] + f[i - 1];
    for (int i = n; i >= 1; i--) g[i] = fsm[i] - a[i] + g[i + 1];
    long long ans = 1e18;
    for (int i = 1; i <= n; i++) ans = min(ans, f[i - 1] + g[i + 1] + max(fpm[i], fsm[i]) - a[i]);
    cout << ans << "\n";
    return 0;
}