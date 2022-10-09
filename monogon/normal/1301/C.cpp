
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t;
ll n, m;

ll solve2(ll n, ll m) {
    ll val = (n - m) / (m + 1);
    ll k = (n - m) % (m + 1);
    return k * (k - 1) / 2 * (val + 1) * (val + 1) + (m + 1 - k) * (m - k) / 2 * val * val + k * (m + 1 - k) * val * (val + 1) + m * (n - m) + m * (m - 1) / 2 + m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n >> m;
        cout << solve2(n, m) << endl;
    }
}