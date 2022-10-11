#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using ld = long double;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

void solve() {
    cout << fixed << setprecision(10);
    const ld PI = atan2(0, -1);
    ll n;
    cin >> n;
    if (n == 2) {
        cout << "1.00000000000000000000000000\n";
        return;
    }
    ld ans = 0.0;
    ld alp = 360.0 / (2.0 * n);
    // cout << "alp = " << alp << '\n';
    ld ln = 1.0;
    if (n % 2 == 0) {
        ld already = alp;
        for (int i = 1; i < n / 2; i++) {
            ans += ln * cos(already * PI / 180.0);
            already += alp; 
        }
        ans *= 2.0;
        ans += ln;
    } else {
        alp = 180.0 - alp;
        ld R = ln / (2.0 * cos(alp / 2));
        ans = 2 * R;
    }
    cout << fixed << setprecision(10) << ans << '\n';
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--)
        solve();
}