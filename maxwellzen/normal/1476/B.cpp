#include <bits/stdc++.h>

using namespace std;
#define ll long long

void solve() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> p(n), sum(n, 0), need(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i<n-1) sum[i+1] = sum[i]+p[i];
    }
    ll ans = 0;
    for (int i = 1; i < n; i++) {
        need[i] = ceil((long double)p[i]*100 / (long double)k);
        if (need[i]>sum[i]) ans = max(ans, need[i]-sum[i]);
    }
    cout << ans << endl;
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        solve();
    }
}