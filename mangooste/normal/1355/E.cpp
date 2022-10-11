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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    c = min(c, a + b);
    vector<int> h(n);
    for (auto &el : h) {
        cin >> el;
    }
    sort(all(h));
    vector<ll> pref(n + 1);
    pref[0] = 0ll;
    for (int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + h[i];
    }
    vector<ll> suf(n + 1);
    suf[n] = 0ll;
    for (int i = n - 1; i >= 0; i--) {
        suf[i] = suf[i + 1] + h[i];
    }

    auto get = [&](int h_to) {
        int i = upper_bound(all(h), h_to) - h.begin();
        ll cur_ans = 0ll;
        int cnt_right = n - i, cnt_left = i;
        ll dup = suf[i] - 1ll * cnt_right * h_to;
        ll ddown = -pref[i] + 1ll * cnt_left * h_to;
        ll mn = min(dup, ddown);
        cur_ans += mn * c;
        dup -= mn;
        ddown -= mn;
        cur_ans += dup * b;
        cur_ans += ddown * a;
        return cur_ans;
    };

    const int INF = 1e9 + 1;
    int L = 0, R = INF;
    while (R - L > 3) {
        int md = (L + R) / 2;
        if (get(md) < get(md + 1)) {
            R = md + 1;
        } else {
            L = md;
        }
    }
    const ll INFll = 1e18;
    ll ans = INFll;
    // cout << "L = " << L << endl;
    for (int i = L - 4; i <= L + 4; i++) {
        if (i >= 0) {
            ans = min(ans, get(i));
        }
    }
    cout << ans << '\n';
}