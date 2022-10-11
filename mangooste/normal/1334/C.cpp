#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    if (n == 1) {
        cout << a[0] << '\n';
        return;
    }
    vector<ll> pref(n);
    pref[0] = max(0LL, a[0] - b[n - 1]);
    for (int i = 1; i < n; i++)
        pref[i] = pref[i - 1] + max(0LL, a[i] - b[i - 1]);
    vector<ll> suf(n);
    suf[n - 1] = max(0LL, a[n - 1] - b[n - 2]);
    for (int i = n - 2; i > 0; i--)
        suf[i] = suf[i + 1] + max(0LL, a[i] - b[i - 1]);
    ll ans = 0;
    for (int fir = 0; fir < n; fir++) {
        ll cur_ans = a[fir];
        if (fir != n - 1)
            cur_ans += suf[fir + 1];
        if (fir != 0)
            cur_ans += pref[fir - 1];
        if (fir == 0)
            ans = cur_ans;
        else
            ans = min(ans, cur_ans);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int tt;
    cin >> tt;
    while (tt--) 
        solve();
}