#include <algorithm>
#include <cmath>
#include <cstring>
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
        int cur;
        cin >> cur;
        if (cur < 0)
            el = 1;
        else
            el = 0;
    }
    ll ans1 = 0, ans2 = 0;
    vector<int> pr;
    pr.pb(0);
    for (int i = 0; i < n; i++)
        pr.pb(pr.back() + a[i]);
    vector<array<int, 2>> cnt(n + 1);
    for (int i = n; i >= 0; i--) {
        if (i != n) {
            cnt[i][0] += cnt[i + 1][0];
            cnt[i][1] += cnt[i + 1][1];
        }
        if (pr[i] % 2 == 0)
            cnt[i][0]++;
        else
            cnt[i][1]++;
    }
    for (int i = 0; i < n; i++) {
        int ind = pr[i] % 2;
        ans1 += cnt[i + 1][(ind + 1) % 2];
        ans2 += cnt[i + 1][ind];
        // cerr << "L = " << i << ' ' << "delta = " << cnt[i + 1][ind] << '\n';
    }
    cout << ans1 << ' ' << ans2 << '\n';
}