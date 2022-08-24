#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;
const int maxN = 2 * (int)1e5 + 10;
int cnt[maxN];
int mx_val[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    int mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cnt[i];
        for (int j = 1; j <= cnt[i]; j++) {
            int x;
            cin >> x;
            mx_val[i] = max(mx_val[i], x);
        }
        mx = max(mx, mx_val[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ll d = mx - mx_val[i];
        ans += d * cnt[i];
    }
    cout << ans;
    return 0;
}