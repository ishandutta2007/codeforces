#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) ((int)((a).size()))

template<typename Fun>
struct y_combinator {
    const Fun fun;

    explicit y_combinator(const Fun&& fun) : fun(std::forward<const Fun>(fun)) {}

    template<typename... Args>
    auto operator()(Args&&... args) const {
        return fun(std::ref(*this), std::forward<Args>(args)...);
    }
};

const string YES = "ACCEPTED";
const string NO = "REJECTED";

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<ll> mask(k);
    for (auto &x : mask) {
        int c;
        cin >> c;
        while (c--) {
            int pos;
            cin >> pos;
            x |= 1ll << (pos - 1);
        }
    }

    if (n == 1) {
        cout << YES << '\n';
        return 0;
    }

    vector<bool> used(n);
    vector<vector<int>> bits(k);
    vector<int> extra(k);

    for (int i = 0; i < k; i++) {
        for (int j = 0; j < n; j++) {
            if (!(mask[i] >> j & 1)) continue;
            bits[i].push_back(j);
            if (!used[j]) {
                used[j] = true;
                extra[i]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (!used[i]) {
            cout << NO << '\n';
            return 0;
        }
    }

    bool ans = true;
    fill(all(used), false);

    y_combinator([&](auto dfs, int pos, ll mask) -> void {
        if (pos == k) {
            int p1 = n - 1;
            while (p1 >= 0 && (mask >> p1 & 1)) p1--;
            int p2 = 0;
            while (p2 < n && !(mask >> p2 & 1)) p2++;
            ans &= p1 < p2;
            return;
        }

        int cur_ones = 0;
        for (int i : bits[pos]) {
            cur_ones += mask >> i & 1;
            mask &= -1 ^ (1ll << i);
        }
        for (int i = 0; i < cur_ones; i++) {
            mask |= 1ll << bits[pos].end()[-i - 1];
        }

        for (int ones = 0;; ones++) {
            dfs(pos + 1, mask);
            if (ones == extra[pos]) break;
            mask |= 1ll << bits[pos].end()[-cur_ones - ones - 1];
        }
    })(0, 0);

    cout << (ans ? YES : NO) << '\n';
}