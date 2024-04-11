#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int q;
ll a, b, m;
const ll INF = (ll)1e18;
void solve() {
    cin >> a >> b >> m;
    if (a == b) {
        cout << 1 << " " << a << '\n';
        return;
    }
    for (int i = 1; i <= 50; i++) {
        ll l = a;
        for (int j = 0; j < i - 2; j++) {
            l = min(INF, 2 * l);
        }
        if (l > b) continue;
        ll c = b - l;
        c -= (1LL << (i - 2));
        if (c < 0) continue;
        vector < ll > ans;
        for (int j = i - 1; j >= 1; j--) {
            ll coef = 1;
            if (j > 1) coef = (1LL << (j - 2));
            ll t = min(m - 1, c / coef);
            c -= coef * t;
            ans.push_back(t + 1);
        }
        if (c != 0) continue;
        ll S = a;
        reverse(ans.begin(), ans.end());
        cout << i << " " << a << " ";
        for (int j = (int)ans.size() - 1; j >= 0; j--) {
            cout << S + ans[j] << " ";
            S += (S + ans[j]);
        }
        cout << '\n';
        return;
    }
    cout << -1;
    cout << '\n';
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> q;
    while (q--) {
        solve();
    }
    return 0;
}