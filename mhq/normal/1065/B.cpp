#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    int n;
    ll m;
    cin >> n >> m;
    int mn = n + 5;
    int mx = -10;
    for (int i = 0; i <= n; i++) {
        ll mx_e = (1LL * (n - i) * (n - i - 1)) / 2;
        if (mx_e < m) continue;
        if (i == (n - 1)) continue;
        ll mn_e = (n - i + 1) / 2;
        if (mn_e > m) continue;
        mn = min(mn, i);
        mx = max(mx, i);
    }
    cout << mn << " " << mx;
    return 0;
}