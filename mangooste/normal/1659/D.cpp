#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    a.push_back(0);

    vector<int> tree(2 * n);

    auto subtract = [&](int l, int r, int value) {
        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) tree[l++] += value;
            if (r & 1) tree[--r] += value;
        }
    };

    auto query = [&](int pos) {
        int tot = 0;
        for (pos += n; pos; pos >>= 1) {
            tot += tree[pos];
        }
        return tot;
    };

    vector<int> ans(n + 1);
    int ones = 0, id = 0;
    for (int i = 0; i < n; i++) {
        if (n - i <= ones) break;
        subtract(i, i + ones, 1);
        a[i] -= query(i);
        if (ones == 0) {
            if (a[i] == 0) {
                assert(id == i);
                id++;
            } else {
                int need = a[i] - i;
                for (int it = 0; it < need; it++) {
                    a[id] -= id;
                    subtract(i, i + it + 1, 1);
                    ans[id++] = 1;
                }
                ans[id++] = 0;
                ones = need;
            }
            continue;
        }

        int extra = a[i];
        for (int it = 0; it < extra; it++) {
            ones++;
            subtract(i, i + ones, 1);
            a[id] -= id;
            ans[id++] = 1;
        }
        ans[id++] = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int tests;
    cin >> tests;
    while (tests--) solve();
}