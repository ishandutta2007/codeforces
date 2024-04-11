
#include <bits/stdc++.h>

#define ll long long
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) for(int i = (a); i < (b); i++)
using namespace std;
template<typename T>
using minpq = priority_queue<T, vector<T>, greater<T>>;

void solve() {
    int n;
    cin >> n;
    map<pair<ll, ll>, int> cnt;
    rep(i, 0, n) {
        ll x, y, u, v;
        cin >> x >> y >> u >> v;
        x -= u; y -= v;
        ll g = gcd(x, y);
        x /= g;
        y /= g;
        cnt[{x, y}]++;
    }
    ll ans = 0;
    for(auto &pa : cnt) {
        pair<ll, ll> pt;
        int c;
        tie(pt, c) = pa;
        ans += 1LL * c * cnt[make_pair(-pt.first, -pt.second)];
    }
    cout << ans/2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) {
        solve();
    }
}