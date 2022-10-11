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
    ld alp = 360.0 / (2.0 * n);
    // cout << "alp = " << alp << '\n';
    ld ln = 1.0;
    const ld INF = 1e9;
    ld ans = -INF;
    ld b = 1.0;
    ld a = 0.0;
    {
        ld already = alp;
        for (int i = 0; i < n / 2; i++) {
            a += ln * cos((90.0 - already) * PI / 180.0);
            already += alp;
        }
        a *= 2;
    }
    ld already = alp;
    for (int i = 0; i <= n / 2; i++) {
        // cout << "a = " << a << " b = " << b << '\n';
        ans = max(ans, (a + b) / sqrt(2.0));
        b += 2.0 * ln * cos(already * PI / 180.0);
        a -= 2.0 * ln * cos((90.0 - already) * PI / 180.0);
        already += alp;
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