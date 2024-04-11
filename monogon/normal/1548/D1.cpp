
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
    vector<vector<ll>> a(4, vector<ll>(4, 0));
    rep(i, 0, n) {
        ll x, y;
        cin >> x >> y;
        a[x % 4][y % 4]++;
    }
    ll ans = 0;
    rep(i1, 0, 2) rep(j1, 0, 2) rep(i2, 0, 2) rep(j2, 0, 2) rep(i3, 0, 2) rep(j3, 0, 2) {
        int x1 = i1 * 2, y1 = j1 * 2, x2 = i2 * 2, y2 = j2 * 2, x3 = i3 * 2, y3 = j3 * 2;
        ll b = (gcd(x2 - x1, y2 - y1) + gcd(x3 - x2, y3 - y2) + gcd(x1 - x3, y1 - y3)) / 2;
        if(b % 2 == 0) {
            ll cnt = a[x1][y1];
            if(x2 == x1 && y2 == y1) {
                cnt *= a[x2][y2] - 1;
                if(x3 == x1 && y3 == y1) {
                    cnt *= a[x3][y3] - 2;
                }else {
                    cnt *= a[x3][y3];
                }
            }else {
                cnt *= a[x2][y2];
                if((x3 == x1 && y3 == y1) || (x3 == x2 && y3 == y2)) {
                    cnt *= a[x3][y3] - 1;
                }else {
                    cnt *= a[x3][y3];
                }
            }
            ans += cnt;
        }
    }
    ans /= 6;
    cout << ans << '\n';
}