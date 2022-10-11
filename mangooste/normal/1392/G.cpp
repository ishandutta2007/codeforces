#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename A, typename B>
bool setmin(A &a, const B &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<typename A, typename B>
bool setmax(A &a, const B &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m, k;
    string start, need;
    cin >> n >> m >> k >> start >> need;

    const int N = 1 << k;
    vector dp_min(N, n), dp_max(N, -1);

    vector<int> p(k);
    iota(all(p), 0);
    for (int i = 0; i <= n; i++) {
        int mask_need = 0, cur_mask = 0;
        for (int j = 0; j < k; j++) {
            mask_need ^= int(start[j] - '0') << p[j];
            cur_mask ^= int(need[j] - '0') << p[j];
        }
        setmin(dp_min[mask_need], i);
        setmax(dp_max[cur_mask], i);

        if (i == n) continue;
        int a, b;
        cin >> a >> b;
        a--, b--;
        swap(p[a], p[b]);
    }

    int ans = -1, from = -1, to = -1;
    for (int mask = N - 1; mask >= 0; mask--) {
        for (int bit = 0; bit < k; bit++) {
            if (mask >> bit & 1) continue;
            int prev_mask = mask ^ (1 << bit);
            setmin(dp_min[mask], dp_min[prev_mask]);
            setmax(dp_max[mask], dp_max[prev_mask]);
        }
        
        if (dp_max[mask] - dp_min[mask] >= m && setmax(ans, __builtin_popcount(mask))) {
            from = dp_min[mask];
            to = dp_max[mask];
        }
    }
    cout << 2 * ans + k - count(all(start), '1') - count(all(need), '1') << '\n';
    cout << from + 1 << ' ' << to << '\n';
}