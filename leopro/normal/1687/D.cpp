#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    solve();
    return 0;
}

#define answer(ans) { cout << (ans) << '\n'; return; }

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    vector<ll> l(a.back() + 3), r(a.back() + 3);
    for (int i = 0; i < a.back() + 3; ++i) {
        l[i] = i * 1LL * i;
        r[i] = i * 1LL * (i + 1);
    }
    int i = 0;
    while (a[0] >= l[i + 1]) i++;
    ll k = 0;
    while (true) {
        ll add = 0;
        int j = i;
        while (r[j] < a.back() + k) {
            ll x = *upper_bound(a.begin(), a.end(), r[j] - k) + k;
            add = max(add, l[j + 1] - x);
            j++;
        }
        while (a[0] + k >= l[i + 1])i++;
        if (add == 0) break;
        k += add;
    }
    cout << k << '\n';
}