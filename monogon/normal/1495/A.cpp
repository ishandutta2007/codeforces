
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

using ftype = long double;

void solve() {
    int n;
    cin >> n;
    vector<ll> x, y;
    rep(i, 0, 2 * n) {
        ll X, Y;
        cin >> X >> Y;
        if(X == 0) y.push_back(abs(Y));
        else x.push_back(abs(X));
    }
    sort(all(x));
    sort(all(y));
    ftype ans = 0;
    rep(i, 0, n) {
        ans += hypotl(x[i], y[i]);
    }
    cout << fixed << setprecision(10) << ans << '\n';
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