#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
 
using namespace std;
using ll = long long;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fun function
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        ll h, c, t;
        cin >> h >> c >> t;
        h *= 2, c *= 2, t *= 2;
        ll half = (h + c) / 2;
        if (t <= half) {
            cout << "2\n";
        } else if (t >= h) {
            cout << "1\n";
        } else {
            h /= 2, c /= 2, t /= 2;
            Fun<pair<ll, ll>(pair<ll, ll>, ll a)> Sub = [&](pair<ll, ll> a, ll b) {
                a.first -= a.second * b;
                a.first = abs(a.first);
                return a;
            };
            Fun<pair<ll, ll>(ll)> Get = [&](ll val) {
                ll a = val, b = val - 1;
                pair<ll, ll> cur = mp(a * h + b * c, a + b);
                cur = Sub(cur, t);
                return cur;
            };
            Fun<bool(pair<ll, ll>, pair<ll, ll>)> Compare = [&](pair<ll, ll> a, pair<ll, ll> b) {
                return a.first * b.second < b.first * a.second;
            };
            ll L = 0, R = 1e6 + 1e5;
            while (R - L > 1) {
                ll mid = (L + R) / 2;
                if (Compare(Get(mid), Get(mid + 1))) {
                    R = mid;
                } else {
                    L = mid;
                }
            }
            const int BUBEN = 30;
            ll ans = max(1ll, L);
            for (ll i = L - BUBEN; i <= L + BUBEN; i++) {
                if (i > 0) {
                    if (Compare(Get(i), Get(ans))) {
                        ans = i;
                    }
                }
            }
            cout << ans * 2ll - 1 << '\n';
        }
    }
}