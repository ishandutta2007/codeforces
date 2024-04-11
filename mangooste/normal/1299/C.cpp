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

#define vec point
struct point {
    ll x, y;
    point(ll x = 0, ll y = 0) :
        x(x), y(y)
    {}
    vec operator - (point a) {
        return vec(x - a.x, y - a.y);
    }
    ll operator % (vec a) {
        return x * a.y - y * a.x;
    }
};
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    vector<ll> pref(n + 1);
    pref[0] = 0;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + a[i];
    }
    vector<point> pts;
    for (int i = 0; i <= n; i++) {
        pts.pb(point(i, pref[i]));
    }
    vector<point> hull;
    hull.pb(pts[0]);
    for (int i = 1; i <= n; i++) {
        while (hull.size() > 1 && (hull.back() - hull[hull.size() - 2]) % (pts[i] - hull.back()) <= 0) {
            hull.pop_back();
        }
        hull.pb(pts[i]);
    }
    cout << fixed << setprecision(10);
    for (int i = 1; i < hull.size(); i++) {
        ll sum = hull[i].y - hull[i - 1].y;
        ll cnt = hull[i].x - hull[i - 1].x;
        double cur = 1.0 * sum / cnt;
        for (int j = 0; j < cnt; j++) {
            cout << cur << '\n';
        }
    }
}