
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int t, n;
ll a;
map<ll, ll> m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    while(t--) {
        cin >> n;
        m.clear();
        for(int i = 0; i < n; i++) {
            cin >> a;
            ll p2 = a & -a;
            m[a / p2] = max(m[a / p2], p2);
        }
        ll ans = 0;
        for(auto p : m) {
            ans += log2(p.second);
        }
        cout << ans << endl;
    }
}