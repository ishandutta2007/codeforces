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
// using pii = pair<int, int>;
using pii = pair<ll, ll>;
 
#define int long long
#define all(a) a.begin(), a.end()
#define pb push_back
#define eb emplace_back
#define mp make_pair

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, T, a, b;
        cin >> n >> T >> a >> b;
        vector<pii> times(n);
        for (int i = 0; i < n; i++)
            cin >> times[i].second;
        for (int i = 0; i < n; i++)
            cin >> times[i].first;
        times.eb(-1, 2);
        sort(all(times));
        // cout << "times = ";
        // for (int i = 0; i < n; i++)
        //     cout << "(" << times[i].first << ' ' << times[i].second << ") ";
        // cout << "\n";
        int all_easy = 0, all_hard = 0;
        for (int i = 0; i < n + 1; i++)
            if (times[i].second == 0)
                all_easy++;
            else if (times[i].second == 1)
                all_hard++;
        int ans = 0;
        int cnt_easy = 0, cnt_hard = 0;
        for (int i = 0; i < n + 1; i++) {
            if (times[i].second == 0)
                cnt_easy++;
            else if (times[i].second == 1)
                cnt_hard++;
            if (i != n && times[i + 1].first == times[i].first)
                continue;
            int cur_ans = 0;
            int max_time;
            if (i == n)
                max_time = T;
            else
                max_time = times[i + 1].first - 1;
            cur_ans += cnt_easy;
            max_time -= cnt_easy * a;
            cur_ans += cnt_hard;
            max_time -= cnt_hard * b;
            if (max_time < 0)
                continue;
            int can_easy = all_easy - cnt_easy;
            int can_hard = all_hard - cnt_hard;
            int maybe;
            maybe = min(can_easy, max_time / a);
            cur_ans += maybe;
            max_time -= maybe * a;
            maybe = min(can_hard, max_time / b);
            cur_ans += maybe;
            ans = max(ans, cur_ans);
        }
        cout << ans << '\n';
    }
}