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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto &el : a)
            cin >> el;
        sort(all(a));
        int ans = 0;
        int cur_cnt = 0;
        for (int i = 0; i < n; i++) {
            if (cur_cnt + 1 >= a[i]) {
                ans++;
                cur_cnt = 0;
            } else
                cur_cnt++;
        }
        cout << ans << '\n';
    }
}