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

int relax(vector<int> &a, int n) {
    vector<vector<int>> poses(n);
    for (int i = 0; i < n; i++) {
        poses[a[i]].pb(i);
    }
    vector<int> mn(n), mx(n);
    for (int i = 0; i < n; i++) {
        if (poses[i].size() == 0) {
            mn[i] = mx[i] = -1;
        } else {
            mn[i] = *min_element(all(poses[i]));
            mx[i] = *max_element(all(poses[i]));
        }
    }
    vector<int> right_only(n + 1);
    right_only[n] = 0;
    int L_from = -1, cnt_from = 0;
    for (int i = n - 1, all = 0; i >= 0; i--) {
        if (mn[i] == -1) {
            right_only[i] = right_only[i + 1];
        } else {
            all++;
            int cur_R = mx[i], cur_L = mn[i];
            if (cur_R > L_from) {
                cnt_from = 1;
            } else {
                cnt_from++;
            }
            L_from = cur_L;
            right_only[i] = all - cnt_from;
        }
    }
    int ans = n - 1;
    for (int i = 0, all = 0; i < n; i++) {
        if (mn[i] != -1) {
            int cur_ans = 1;
            if (mn[i] == 0 && mx[i] - mn[i] + 1 == poses[i].size()) {
                cur_ans--;
            }
            cur_ans += all;
            cur_ans += right_only[i + 1];
            ans = min(ans, cur_ans);
            all++;
        }
    }
    return ans;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &el : a) {
            cin >> el, el--;
        }
        int ans = n - 1;
        ans = min(ans, relax(a, n));
        for (auto &el : a) {
            el = n - 1 - el;
        }
        reverse(all(a));
        ans = min(ans, relax(a, n));
        cout << ans << '\n';
    }
}