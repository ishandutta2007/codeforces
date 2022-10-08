
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
    vector<ll> c(n);
    rep(i, 0, n) cin >> c[i];
    ll min1 = LLONG_MAX, min2 = LLONG_MAX;
    ll ans = LLONG_MAX;
    ll sum = 0;
    rep(i, 0, n) {
        if(i % 2 == 0) min1 = min(min1, c[i]);
        else min2 = min(min2, c[i]);
        sum += c[i];
        if(i >= 1) {
            int steps = i - 1;
            ll s1 = n - (steps + 1) / 2;
            ll s2 = n - steps / 2;
            ans = min(ans, sum - min1 - min2 + s1 * min1 + s2 * min2);
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