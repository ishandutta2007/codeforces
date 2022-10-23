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
    cin >> L >> R;
    cout << go(R) - go(L - 1) << '\n';
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