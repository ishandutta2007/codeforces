#include <bits/stdc++.h>

using namespace std;

int n, m, ta, tb, k;
int a[200005], b[200005];

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> ta >> tb >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> b[i];
    if (k >= n || k >= m) return cout << -1 << endl, 0;
    int ans = 0;
    for (int i = 1; i <= n && i <= k + 1; ++i) {
        int j = k - i + 1;
        int t = lower_bound(b + 1, b + m + 1, a[i] + ta) - b;
        t += j;
        if (t > m) return cout << -1 << endl, 0;
        ans = max(ans, b[t] + tb);
    }
    cout << ans << endl;
    return 0;
}