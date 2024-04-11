
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

/*
a k + b l <= x
b k + a l <= y
max (k + l)

k = 0: l <= x/b, l <= y/a
l = 0: k <= x/a, l <= y/b

fix k, then l <= min((x - ak) / b, (y - bk) / a)
*/

void solve() {
    ll x, y, a, b;
    cin >> x >> y >> a >> b;
    if(a > b) {
        swap(a, b);
        swap(x, y);
    }
    ll ans = max(min(x / b, y / a), min(x / a, y / b));
    ll L = 0, R = 2e9;
    if(a != b) {
        while(L < R) {
            ll k = (L + R) / 2;
            if(x - a * k >= 0 && y - b * k >= 0 && (x - a * k) / b < (y - b * k) / a) {
                L = k + 1;
            }else {
                R = k;
            }
        }
        rep(d, L - 10, L + 10) {
            if(d >= 0 && x - a * d >= 0 && y - b * d >= 0) {
                ans = max(ans, d + min((x - a * d) / b, (y - b * d) / a));
            }
        }
        L = 0;
        R = 2e9;

        while(L < R) {
            ll k = (L + R) / 2;
            if(x - a * k >= 0 && y - b * k >= 0 && (x - a * k) / b > (y - b * k) / a) {
                L = k + 1;
            }else {
                R = k;
            }
        }
        rep(d, L - 10, L + 10) {
            if(d >= 0 && x - a * d >= 0 && y - b * d >= 0) {
                ans = max(ans, d + min((x - a * d) / b, (y - b * d) / a));
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