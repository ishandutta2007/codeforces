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

using ll = long long;
using namespace std;

// #define int long long
#define all(a) a.begin(), a.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    vector<int> cnt(4);
    cin >> cnt[0] >> cnt[1] >> cnt[2] >> cnt[3];
    int n = accumulate(all(cnt), 0);
    for (int fir = 0; fir < 4; fir++) {
        if (cnt[fir] == 0)
            continue;
        vector<int> cur_cnt = cnt;
        cur_cnt[fir]--;
        vector<int> a(n);
        a[0] = fir;
        bool ok = true;
        for (int i = 1; i < n; i++) {
            bool fnd = false;
            for (int d = -1; d <= 1; d += 2)
                if (0 <= a[i - 1] + d && a[i - 1] + d < 4 && cur_cnt[a[i - 1] + d] != 0)
                    fnd = true;
            if (!fnd) {
                ok = false;
                break;
            }
            if (a[i - 1] == 0) {
                a[i] = 1;
                cur_cnt[1]--;
                continue;
            }
            if (a[i - 1] == 3) {
                a[i] = 2;
                cur_cnt[2]--;
                continue;
            }
            if (cur_cnt[a[i - 1] - 1] != 0) {
                a[i] = a[i - 1] - 1;
                cur_cnt[a[i]]--;
                continue;
            }
            a[i] = a[i - 1] + 1;
            cur_cnt[a[i]]--;
        }
        if (ok) {
            cout << "YES\n";
            for (auto i : a)
                cout << i << ' ';
            cout << '\n';
            return 0;
        }
    }
    cout << "NO\n";
}