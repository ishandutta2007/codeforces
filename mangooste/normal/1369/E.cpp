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

void Main();

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(10);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    Main();
#ifdef LOCAL
    cout << "\nTime: " << (int)ceil((double)1000 * clock() / CLOCKS_PER_SEC) << " ms";
#endif
}

int n, m;
vector<int> a, x, y, cnt;
vector<vector<int>> want;

void Main() {
    cin >> n >> m;
    a.resize(n);
    for (auto &el : a) {
        cin >> el;
    }
    x.resize(m);
    y.resize(m);
    cnt.resize(n);
    want.resize(n);
    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        x[i]--, y[i]--;
        if (x[i] > y[i]) {
            swap(x[i], y[i]);
        }
        cnt[x[i]]++;
        cnt[y[i]]++;
        want[x[i]].push_back(i);
        want[y[i]].push_back(i);
    }
    vector<int> cur_type(m, -1);
    set<pair<int, int>> can;
    for (int i = 0; i < m; i++) {
        int cx = (a[x[i]] >= cnt[x[i]] ? 1 : 0);
        int cy = (a[y[i]] >= cnt[y[i]] ? 1 : 0);
        int type = cx * 2 + cy;
        can.insert(make_pair(-type, i));
        cur_type[i] = type;
    }
    vector<char> used(m, 0);
    vector<int> ans;
    while (!can.empty() && (int)ans.size() < m) {
        auto [type, num] = *can.begin();
        type *= -1;
        can.erase(can.begin());
        if (type == 0) {
            break;
        }
        ans.push_back(num);
        cnt[x[num]]--;
        cnt[y[num]]--;
        used[num] = 1;
        if (cnt[x[num]] == a[x[num]]) {
            for (auto el : want[x[num]]) {
                if (!used[el]) {
                    can.erase(make_pair(-cur_type[el], el));
                    cur_type[el] += 2;
                    can.insert(make_pair(-cur_type[el], el));
                }
            }
        }
        if (cnt[y[num]] == a[y[num]]) {
            for (auto el : want[y[num]]) {
                if (!used[el]) {
                    can.erase(make_pair(-cur_type[el], el));
                    cur_type[el]++;
                    can.insert(make_pair(-cur_type[el], el));
                }
            }
        }
    }
    if ((int)ans.size() != m) {
        cout << "DEAD\n";
        return;
    }
    reverse(ans.begin(), ans.end());
    cout << "ALIVE\n";
    for (auto &el : ans) {
        cout << el + 1 << ' ';
    }
    cout << '\n';
}