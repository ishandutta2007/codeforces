
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
    ll c;
    cin >> n >> c;
    vector<ll> a(n), b(n - 1), days(n), money(n);
    rep(i, 0, n) {
        cin >> a[i];
    }
    rep(i, 0, n - 1) cin >> b[i];
    ll ans = LLONG_MAX;
    rep(i, 0, n) {
        if(i > 0) {
            days[i] = days[i - 1] + max(0LL, (b[i - 1] - money[i - 1] + a[i - 1] - 1) / a[i - 1]);
            money[i] = money[i - 1] - b[i - 1] + (days[i] - days[i - 1]) * a[i - 1];
            days[i]++;
        }
        ll d = days[i] + max(0LL, (c - money[i] + a[i] - 1) / a[i]);
        ans = min(ans, d);
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