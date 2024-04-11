#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector cnt(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            cnt[i][x - 1]++;
        }
    }

    vector<vector<int>> ans;
    while (true) {
        vector<int> shift(n, -1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cnt[i][j] >= 2) {
                    shift[i] = j;
                    break;
                }
            }
        }
        if (count(all(shift), -1) == n) break;

        for (int i = 0; i < 2 * n; i++) {
            int pos = (i + 1) % n;
            if (shift[pos] != -1 && shift[(pos + 1) % n] == -1) {
                shift[(pos + 1) % n] = shift[pos];
            }
        }
        ans.push_back(shift);
        for (int i = 0; i < n; i++) {
            cnt[i][shift[i]]--;
            cnt[(i + 1) % n][shift[i]]++;
        }
    }

    for (int cnt = 1; cnt < n; cnt++) {
        vector<int> cur(n);
        for (int i = 0; i < n; i++) {
            cur[i] = (i + n - cnt) % n;
        }
        for (int it = 0; it < cnt; it++) {
            ans.push_back(cur);
        }
    }

    cout << len(ans) << '\n';
    for (auto &v : ans) {
        for (int i = 0; i < n; i++) {
            cout << v[i] + 1 << " \n"[i == n - 1];
        }
    }
}