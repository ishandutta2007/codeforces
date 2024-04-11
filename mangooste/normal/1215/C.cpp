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
    string s, t;
    cin >> s >> t;
    int cnt_a = 0, cnt_b = 0;
    for (auto el : s) {
        cnt_a += (el == 'a');
        cnt_b += (el == 'b');
    }
    for (auto el : t) {
        cnt_a += (el == 'a');
        cnt_b += (el == 'b');
    }
    if (cnt_a % 2 == 1 || cnt_b % 2 == 1)
        return cout << "-1\n", 0;
    vector<pii> ans;
    vector<int> t1, t2;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i])
            continue;
        if (s[i] == 'a')
            t1.pb(i);
        else
            t2.pb(i);
    }
    while (t2.size() > 1) {
        int pos1 = t2.back();
        t2.pop_back();
        int pos2 = t2.back();
        t2.pop_back();
        ans.eb(pos1, pos2);
    }
    while (t1.size() > 1) {
        int pos1 = t1.back();
        t1.pop_back();
        int pos2 = t1.back();
        t1.pop_back();
        ans.eb(pos1, pos2);
    }
    if (t1.size() != 0) {
        ans.eb(t1.back(), t1.back());
        ans.eb(t1.back(), t2.back());
    }
    cout << ans.size() << '\n';
    for (auto el : ans)
        cout << el.first + 1 << ' ' << el.second + 1 << '\n';
}