#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
ll L, R;
ll go(ll R) {

    ll ans = 0;
    ll le = 0;
    ll ri = 1e9 + 228;
    while (ri - le > 1) {
        ll mid = (le + ri) / 2;
        if (mid * mid <= R) {
            le = mid;
        }
        else {
            ri = mid;
        }
    }
    ans += le;
    le = 0;
    ri = 1e9 + 228;
    while (ri - le > 1) {
        ll mid = (le + ri) / 2;
        if (mid * mid + mid <= R) {
            le = mid;
        }
        else {
            ri = mid;
        }
    }
    ans += le;
    le = 0;
    ri = 1e9 + 228;
    while (ri - le > 1) {
        ll mid = (le + ri) / 2;
        if (mid * mid + 2 * mid <= R) {
            le = mid;
        }
        else {
            ri = mid;
        }
    }
    ans += le;
    return ans;
}
void solve() {
    int n;
    cin >> n;
    int r1, c1, r2, c2, r3, c3;
    cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3;
    int x, y;
    cin >> x >> y;
    int tx = -1;
    int ty = -1;
    if (r1 == r2) {
        tx = r1;
    }
    else if (r1 == r3) {
        tx = r1;
    }
    else {
        assert(r2 == r3);
        tx = r2;
    }
    if (c1 == c2) {
        ty = c1;
    }
    else if (c1 == c3) {
        ty = c1;
    }
    else {
        assert(c2 == c3);
        ty = c2;
    }
    if ((tx == 1 || tx == n) && (ty == 1 || ty == n)) {
        if (x == tx || y == ty) {
            cout << "YES\n";
        }
        else {
            cout << "NO\n";
        }
        return;
    }
    if (tx % 2 != x % 2 && ty % 2 != y % 2) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}