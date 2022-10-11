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
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &el : a) {
        cin >> el;
    }
    vector<int> pref_sums(n + 1);
    pref_sums[0] = 0;
    for (int i = 0; i < n; i++) {
        pref_sums[i + 1] = pref_sums[i] + a[i];
    }
    int ans = 0;
    for (int max_el = 30; max_el >= -30; max_el--) {
        vector<int> ans_left, ans_right;
        int mn = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == max_el) {
                ans_left.pb(mn);
                mn = min(mn, pref_sums[i + 1]);
            } else if (a[i] > max_el) {
                mn = pref_sums[i + 1];
            } else {
                mn = min(mn, pref_sums[i + 1]);
            }
        }
        int mx = -1e9;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] == max_el) {
                mx = max(mx, pref_sums[i + 1]);
                ans_right.pb(mx);
            } else if (a[i] > max_el) {
                mx = -1e9;
            } else {
                mx = max(mx, pref_sums[i + 1]);
            }
        }
        reverse(all(ans_right));
        int sz = ans_right.size();
        for (int i = 0; i < sz; i++) {
            ans = max(ans, -ans_left[i] + ans_right[i] - max_el);
        }
    }
    cout << ans << '\n';
}