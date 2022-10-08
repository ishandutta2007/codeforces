
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
    int te;
    cin >> te;
    while(te--) {
    int m, n;
    cin >> m >> n;
    vector<vector<ll>> a(m, vector<ll>(n));
    rep(i, 0, m) {
        rep(j, 0, n) {
            cin >> a[i][j];
        }
    }
    ll ans = LLONG_MAX;
    rep(j, 0, n) {
        ll mx = LLONG_MIN;
        rep(i, 0, m) {
            mx = max(mx, a[i][j]);
        }
        ans = min(ans, mx);
    }
    ll ans2 = LLONG_MIN;
    rep(i, 0, m) {
        sort(all(a[i]));
        ans2 = max(ans2, a[i][n - 2]);
    }
    cout << min(ans, ans2) << '\n';

    }
}