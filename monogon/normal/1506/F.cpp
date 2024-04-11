
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
    vector<ll> r(n + 1), c(n + 1);
    vector<pair<ll, ll>> ve;
    rep(i, 1, n + 1) cin >> r[i];
    rep(i, 1, n + 1) cin >> c[i];
    ve.push_back({1, 1});
    rep(i, 1, n + 1) ve.push_back({r[i], c[i]});
    sort(all(ve), [&](pair<ll, ll> a, pair<ll, ll> b) {
        return a.first + a.second < b.first + b.second;
    });
    ll ans = 0;
    rep(i, 0, n + 1) {
        tie(r[i], c[i]) = ve[i];
        ans = max(ans, (r[i] - c[i]) / 2);
    }
    rep(i, 1, n + 1) {
        if(r[i] - c[i] == r[i - 1] - c[i - 1]) {
            if((r[i] - c[i]) % 2 == 0) {
                ans += r[i] - r[i - 1];
            }
        }
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int te;
    cin >> te;
    while(te--) solve();
}