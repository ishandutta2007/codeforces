
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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i, 0, n) cin >> a[i];
    reverse(all(a));
    ll mx = 1e9 + 5;
    ll ans= 0;
    for(ll x : a) {
        ll amt = max(0ll, min(mx - 1, x));
        ans += amt;
        mx = amt;
    }
    cout << ans << '\n';
}