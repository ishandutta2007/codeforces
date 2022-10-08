
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
    vector<ll> a(n), b(n), c(n);
    rep(i, 0, n) cin >> c[i];
    rep(i, 0, n) cin >> a[i];
    rep(i, 0, n) cin >> b[i];
    ll ans = 0;
    ll last = -1;
    rep(i, 1, n) {
        if(a[i] > b[i]) swap(a[i], b[i]);
        if(last == -1) {
            last = c[i] + 1 + b[i] - a[i];
        }else if(a[i] == b[i]) {
            last = c[i] + 1;
        }else {
            last = max(c[i] + 1 + b[i] - a[i], c[i] + 1 + last - b[i] + a[i]);
        }
        ans = max(ans, last);
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