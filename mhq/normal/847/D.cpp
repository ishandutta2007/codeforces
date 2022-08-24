#include <bits/stdc++.h>

using namespace std;
int n, T;
int a[400000];
int f[400000];
int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> T;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) {
        a[i] = max(a[i], i);
        if (a[i] >= T) continue;
        long long j = min(1ll * n + 1, 1ll * T - 1 + i - a[i]);
        f[j + 1]--;
        f[i]++;
    }
    for (int i = 1; i <= n; i++) f[i] = f[i - 1] + f[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << "\n";
    return 0;
}