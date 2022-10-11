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
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(10, 0);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - '0']++;
    }
    vector<ll> fact(20, 1ll);
    for (int i = 1; i < 20; i++) {
        fact[i] = fact[i - 1] * i;
    }
    vector<int> maybe;
    for (int i = 0; i < 10; i++) {
        if (cnt[i] != 0) {
            maybe.eb(cnt[i]);
        }
    }
    Fun<ll(int, ll, int)> Go = [&](int pos, ll div, int before) {
        if (pos == maybe.size()) {
            return fact[before] / div;
        } else {
            ll cur_ans = 0;
            for (int len = 1; len <= maybe[pos]; len++) {
                cur_ans += Go(pos + 1, div * fact[len], before + len);
            }
            return cur_ans;
        }
    };
    ll ans = Go(0, 1ll, 0);
    if (cnt[0] == 1) {
        ans -= Go(1, 1ll, 0);
    } else if (cnt[0] > 1) {
        maybe[0]--;
        ans -= Go(0, 1ll, 0);
        ans -= Go(1, 1ll, 0);
    }
    cout << ans << '\n';
}