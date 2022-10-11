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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int sm = 0;
        for (int i = 0; i < n; i++)
            sm += (s[i] - '0');
        const int INF = 1e9;
        int ans = INF;
        for (int i = 0; i < k; i++) {
            deque<int> cur;
            int cur_sm = 0;
            for (int j = i; j < n; j += k) {
                cur_sm += s[j] - '0';
                cur.pb(s[j] - '0');
            }
            // cout << "i = " << i << " cur = ";
            // for (auto el : cur)
            //     cout << el << ' ';
            // cout << '\n';
            int cur_ans = 0;
            cur_ans += sm - cur_sm;
            while (!cur.empty() && cur[0] == 0)
                cur.pop_front();
            while (!cur.empty() && cur.back() == 0)
                cur.pop_back();
            int sz = cur.size();
            vector<pii> dp(sz, mp(0, 0));
            if (sz != 0)
                dp[0] = mp(0, 1);
            for (int i = 1; i < sz; i++) {
                dp[i].first = min(dp[i - 1].second, dp[i - 1].first) + (cur[i] == 0 ? 1 : 0);
                dp[i].second = dp[i - 1].second + (cur[i] == 1 ? 1 : 0);
            }
            int mn = INF;
            mn = min(mn, cur_sm);
            for (int i = 0, sm = 0; i < sz; i++) {
                sm += cur[i];
                if (cur[i] == 1)
                    mn = min(mn, dp[i].first + cur_sm - sm);
            }
            cur_ans += mn;
            // cout << "i = " << i << " cur_ans = " << cur_ans << " cur = ";
            // for (auto el : cur)
            //     cout << el << ' ';
            // cout << '\n';
            ans = min(ans, cur_ans);
        }
        cout << ans << '\n';
    }
}