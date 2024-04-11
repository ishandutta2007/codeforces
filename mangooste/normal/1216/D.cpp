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

// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    sort(all(a));
    ll mx = a.back();
    ll g = mx - a[0];
    for (int i = 1; i < n - 1; i++) {
        g = __gcd(g, mx - a[i]);
    }
    ll ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += (mx - a[i]) / g;
    }
    cout << ans << ' ' << g << '\n';
}