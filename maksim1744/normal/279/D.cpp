#include "bits/stdc++.h"

using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& k : a)
        cin >> k;

    auto vals = a;
    vals.push_back(0);
    sort(vals.begin(), vals.end());
    vals.erase(unique(vals.begin(), vals.end()), vals.end());

    vector<int> pos(n);
    for (int i = 0; i < n; ++i) {
        pos[i] = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
    }

    vector<int> possible(1 << vals.size(), 0);
    for (int i = 1; i < possible.size(); ++i) {
        int k = 0;
        for (int j = 0; j < vals.size() && k < 3; ++j) {
            if ((i >> j) & 1) {
                possible[i] |= possible[i ^ (1 << j)];
                ++k;
            }
        }
        if (__builtin_popcount(i) <= 2) {
            for (int j = 0; j < vals.size(); ++j) {
                if (!((i >> j) & 1)) continue;
                for (int k = 0; k < vals.size(); ++k) {
                    if (!((i >> k) & 1)) continue;
                    int val = vals[j] + vals[k];
                    int ind = lower_bound(vals.begin(), vals.end(), val) - vals.begin();
                    if (ind < vals.size() && vals[ind] == val)
                        possible[i] |= (1 << ind);
                }
            }
        }
    }

    vector<char> dp_cur(1 << vals.size(), 0);
    dp_cur[1 << pos[0]] = 1;
    dp_cur[(1 << pos[0]) | (1 << 0)] = 1;

    auto can_sum = [&](int mask, int pos) {
        return (possible[mask] >> pos) & 1;
    };

    vector<char> dp_next;
    for (int i = 1; i < n; ++i) {
        dp_next.assign(dp_cur.size(), false);
        for (int j = 0; j < dp_cur.size(); ++j) {
            if (dp_cur[j] && can_sum(j, pos[i])) {
                int mask = j;
                mask |= (1 << pos[i]);
                dp_next[mask] = 1;
                for (int k = 0; k < vals.size(); ++k)
                    if (((mask >> k) & 1) && vals[k] != a[i])
                        dp_next[mask ^ (1 << k)] = 1;
            }
        }
        swap(dp_cur, dp_next);
    }

    int ans = -1;
    for (int i = 0; i < dp_cur.size(); ++i) {
        if (!dp_cur[i]) continue;
        int sz = __builtin_popcount(i);
        if (ans == -1 || ans > sz)
            ans = sz;
    }
    cout << ans << '\n';

    return 0;
}