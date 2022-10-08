
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
    vector<ll> h(n + 2);
    rep(i, 1, n + 1) {
        cin >> h[i];
    }
    if(n % 2 == 1) {
        ll ans = 0;
        for(int i = 2; i < n; i += 2) {
            ans += max({0ll, h[i - 1] - h[i] + 1, h[i + 1] - h[i] + 1});
        }
        cout << ans << '\n';
        return;
    }
    vector<ll> pref(n + 1), suff(n + 2);
    for(int i = 2; i < n; i += 2) {
        pref[i] = pref[i - 2] + max({0ll, h[i - 1] - h[i] + 1, h[i + 1] - h[i] + 1});
        pref[i + 1] = pref[i];
    }
    for(int i = n - 1; i > 1; i -= 2) {
        suff[i] = suff[i + 2] + max({0ll, h[i - 1] - h[i] + 1, h[i + 1] - h[i] + 1});
        suff[i - 1] = suff[i];
    }
    ll ans = LLONG_MAX;
    for(int i = 2; i <= n; i += 2) {
        ans = min(ans, pref[i - 2] + suff[i]);
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