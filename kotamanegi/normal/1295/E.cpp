#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
ll seg_tree[seg_size * 4];
ll lazy_seg[seg_size * 4];
void seg_reflect(int now) {
    seg_tree[now] += lazy_seg[now];
    lazy_seg[now * 2 + 1] += lazy_seg[now];
    lazy_seg[now * 2] += lazy_seg[now];
    lazy_seg[now] = 0;
    return;
}
void seg_set(int now) {
    seg_reflect(now * 2);
    seg_reflect(now * 2 + 1);
    seg_tree[now] = min(seg_tree[now * 2], seg_tree[now * 2 + 1]);
    if (now != 1) seg_set(now / 2);
    return;
}
int seg_find(int now, int n_l, int n_r, int w_l, int w_r, int settings) {
    if (w_l <= n_l && n_r <= w_r) {
        lazy_seg[now] += settings;
    }
    if (lazy_seg[now] != 0) {
        seg_reflect(now);
        if (now != 1) {
            seg_set(now / 2);
        }
    }
    if (w_l <= n_l && n_r <= w_r) {
        return seg_tree[now];
    }
    if (w_r <= n_l || n_r <= w_l) {
        return 1e18;
    }
    return min(seg_find(now * 2, n_l, (n_l + n_r) / 2, w_l, w_r, settings), seg_find(now * 2 + 1, (n_l + n_r) / 2, n_r, w_l, w_r, settings));
}
vector<int> costs;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> inputs;
    REP(i, n) {
        int a;
        cin >> a;
        inputs.push_back(mp(a, i));
    }
    sort(ALL(inputs));
    REP(i, n) {
        int a;
        cin >> a;
        costs.push_back(a);
    }
    int ans = 1e18;
    REP(t, 1) {
        REP(q, seg_size * 4) {
            seg_tree[q] = 1e18;
            lazy_seg[q] = 0;
        }
        ll now = 0;
        REP(q, n) {
            now += costs[q];
            seg_tree[(q + seg_size)] = now;
            seg_set((q + seg_size) / 2);
        }
        ans = min(ans, seg_find(1, 0, seg_size, 0, n - 1, 0));
        REP(i, inputs.size()) {
            int now_cost = costs[inputs[i].second];
            seg_find(1, 0, seg_size, inputs[i].second, n, -now_cost);
            seg_find(1, 0, seg_size, 0, inputs[i].second, now_cost);
            int hoge = seg_find(1, 0, seg_size, 0, n - 1, 0);
            ans = min(ans, hoge);
        }
    }
    cout << ans << endl;
    return;
}
#undef int
int main() {
    init();
    solve();
}