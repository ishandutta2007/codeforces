#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxN = (int)1e5 + 10;
int mod = 998244353;
int ssum(int a, int b) {
    int s = a + b;
    if (s >= mod) s -= mod;
    return s;
}
int a[maxN];
ll sum[maxN];
int n, m;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    a[0] = 0;
    a[n + 1] = m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    ll ans = 0;
    sum[n + 1] = 0;
    sum[n] = a[n + 1] - a[n];
    for (int i = n - 1; i >= 0; i--) {
        sum[i] = 1LL * a[i + 1] - a[i] + sum[i + 2];
    }
    ans = sum[0];
    ll cur = 0;
    for (int i = 0; i <= n; i++) {
        if (i % 2 == 0) {
            if (a[i] + 1 < a[i + 1]) {
                ans = max(ans, cur + a[i + 1] - 1 - a[i] + sum[i + 1]);
            }
        }
        else {
            if (a[i] + 1 < a[i + 1]) {
                ans = max(ans, cur + a[i + 1] - 1 - a[i] + sum[i + 2]);
            }
        }
        if (i % 2 == 0) cur += a[i + 1] - a[i];
    }
    cout << ans;
    return 0;
}