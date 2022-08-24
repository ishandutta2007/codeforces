#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    srand(228);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    vector < int > divs;
    for (int i = 1; 1LL * i * i <= n; i++) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != (n / i)) divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    ll total = 0;
    ll mn = LONG_LONG_MAX;
    ll mx = LONG_LONG_MIN;
    for (int d1 : divs) {
        int d = n / d1;
        for (int d2 : divs) {
            if (d % d2 == 0) {
                int d3 = d / d2;
                ll a1 = d1 + 1;
                ll a2 = d2 + 2;
                ll a3 = d3 + 2;
                mx = max(mx, a1 * a2 * a3 - n);
                mn = min(mn, a1 * a2 * a3 - n);
            }
        }
    }
    cout << mn << " " << mx << '\n';
    return 0;
}