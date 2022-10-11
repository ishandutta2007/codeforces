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
using pii = pair<int, int>;
 
// #define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int n = n1 + n2 + n3;
    vector<int> a1(n1), a2(n2), a3(n3);
    vector<int> where(n, -1);
    for (auto &el : a1) {
        cin >> el, el--;
        where[el] = 1;
    }
    for (auto &el : a2) {
        cin >> el, el--;
        where[el] = 2;
    }
    for (auto &el : a3) {
        cin >> el, el--;
        where[el] = 3;
    }
    vector<int> pref1(n + 1);
    pref1[0] = 0;
    for (int i = 0; i < n; i++) {
        pref1[i + 1] = pref1[i];
        if (where[i] == 1) {
            pref1[i + 1]++;
        }
    }
    vector<int> suf2(n + 2);
    suf2[n + 1] = 0;
    for (int i = n; i > 0; i--) {
        suf2[i] = suf2[i + 1];
        if (where[i - 1] == 2) {
            suf2[i]++;
        }
    }
    vector<int> pref3(n + 1);
    pref3[0] = 0;
    for (int i = 0; i < n; i++) {
        pref3[i + 1] = pref3[i];
        if (where[i] == 3) {
            pref3[i + 1]++;
        }
    }
    vector<int> vals(n + 1);
    for (int i = 0; i <= n; i++) {
        vals[i] = suf2[i + 1] + pref3[i];
    }
    int ans = n;
    vector<int> suf_min(n + 1);
    suf_min[n] = vals[n];
    for (int i = n - 1; i >= 0; i--) {
        suf_min[i] = min(suf_min[i + 1], vals[i]);
    }
    ans = min(ans, suf_min[0] + n1);
    int bad = 0;
    for (int i = 1; i <= n; i++) {
        if (where[i - 1] == 2) {
            bad++;
        }
        int cur_ans = (n1 - pref1[i]) + bad + suf_min[i];
        ans = min(ans, cur_ans);
    }
    cout << ans << '\n';
}