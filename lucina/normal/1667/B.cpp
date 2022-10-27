#include<bits/stdc++.h>
using namespace std;
const int nax = 5e5 + 10;
const int INF = 1e9;
int dp[nax];
int n;
int64_t a[nax];

//struct segtree {
//    int sg[nax << 2];
//    void update(int v, int l, int r, int pos, int val) {
//        if (l == r) {
//            sg[v] = val;
//            return;
//        }
//        int mid = l + r >> 1;
//        if (pos <= mid) update(v << 1, l, mid, pos, val);
//        else update(v << 1 | 1, mid + 1, r, pos, val);
//        sg[v] = max(sg[v << 1], sg[v << 1 | 1]);
//    }
//    int get(int v, int x, int y, int l, int r) {
//        if (l == x && r == y) return sg[v];
//        int mid = x + y >> 1;
//        if (r <= mid) return get(v << 1, x, mid, l, r);
//        if (l > mid) return get(v << 1 | 1, mid + 1, y, l, r);
//        return max(get(v << 1, x, mid, l, mid), get(v << 1 | 1, mid + 1, y, mid + 1, r));
//    }
//
//    void clean() {
//        fill(sg + 1, sg + n * 4 + 1, -INF);
//    }
//}sg[2];


template <typename T>
struct fenwick {
    vector <T> bit;
    int n;
    fenwick (int n, T val = T()) : n(n) {
        bit.resize(n + 1, val);
    }
    void update(int idx, int val) {
        for (; idx <= n ; idx += idx & -idx)
            bit[idx] = max(bit[idx], val);
    }

    int get(int idx) {
        int res = -INF;
        for (; idx > 0 ; idx -= idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }
};

template <typename T>
struct suf_fenwick {
    vector <T> bit;
    int n;
    suf_fenwick (int n, T val = T()) : n(n) {
        bit.resize(n + 1, val);
    }
    void update(int idx, int val) {
        for (; idx > 0 ; idx -= idx & -idx)
            bit[idx] = max(bit[idx], val);
    }

    int get(int idx) {
        int res = -INF;
        for (; idx <= n; idx += idx & -idx)
            res = max(res, bit[idx]);
        return res;
    }

};

int f[nax];

void solve() {
    cin >> n;
    vector <int64_t> com;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i], a[i] += a[i - 1];
        com.push_back(a[i]);
    }
    sort(com.begin(), com.end());
    com.erase(unique(com.begin(), com.end()), com.end());
    auto where = [&](int64_t x) -> int {
        return lower_bound(com.begin(), com.end(), x) - com.begin() + 1;
    };
    int m = com.size();
    fenwick <int> f1(m, -INF);
    suf_fenwick <int> f2(m, -INF);
    fill(f + 1, f + 1 + m, -INF);

    for (int i = 1 ; i <= n ; ++ i) {
        dp[i] = i * (a[i] == 0 ? 0 : (a[i] < 0 ? -1 : 1));
        int idx = where(a[i]);
        dp[i] = max(dp[i], f[idx]);
        if (idx > 1) dp[i] = max(dp[i], f1.get(idx - 1) + i);
        if (idx + 1 <= m) dp[i] = max(dp[i], f2.get(idx + 1) - i);

        f[idx] = max(f[idx], dp[i]);
        f1.update(idx, dp[i] - i);
        f2.update(idx, dp[i] + i);
    }

    cout << dp[n] << '\n';
}
/**
            this dp is much easier to optimize
            one can use segment tree to optimize this

            position l where a[l - 1] < a[i] -> dp[l - 1] - (l - 1) + i
            position l where a[l - 1] = a[i] -> dp[l - 1]
            position l where a[l - 1] > a[i] -> dp[l - 1] + (l - 1) + i

        */


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    long time no div.1
*/