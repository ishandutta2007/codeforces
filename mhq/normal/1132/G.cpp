#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;

struct SegmentTree {
    int n;
    vector<int> t;
    vector<int> lazy;

    void apply(int v, int x) {
        t[v] += x;
        lazy[v] += x;
    }

    void push(int v, int tl, int tr) {
        if (tl != tr && lazy[v] != 0) {
            apply(2 * v, lazy[v]);
            apply(2 * v + 1, lazy[v]);
        }
        lazy[v] = 0;
    }

    void merge(int v) {
        t[v] = max(t[2 * v], t[2 * v + 1]);
    }


    explicit SegmentTree(int _n) {
        n = _n;
        t.resize(4 * n);
        lazy.resize(4 * n);
    }

    void upd(int v, int tl, int tr, int l, int r, int x) {
        if (tr < l || tl > r) return;
        if (l <= tl && tr <= r) {
            apply(v, x);
            return;
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        upd(2 * v, tl, tm, l, r, x);
        upd(2 * v + 1, tm + 1, tr, l, r, x);
        merge(v);
    }

    int get(int v, int tl, int tr, int l, int r) {
        if (tr < l || tl > r) return -1e9;
        if (l <= tl && tr <= r) {
            return t[v];
        }
        push(v, tl, tr);
        int tm = (tl + tr) / 2;
        return max(get(2 * v, tl, tm, l, r), get(2 * v + 1, tm + 1, tr, l, r));
    }
};
int n, k;
const int maxN = 1e6 + 10;
int a[maxN];
vector<int> g[maxN];
int tin[maxN];
int tout[maxN];
int timer = 0;
void dfs(int v) {
    tin[v] = timer++;
    for (int to : g[v]) {
        dfs(to);
    }
    tout[v] = timer;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    a[n + 1] = n + 1;
    vector<int> st;
    st.emplace_back(n + 1);
    for (int i = n; i >= 1; i--) {
        while (a[st.back()] <= a[i]) st.pop_back();
        g[st.back()].emplace_back(i);
        st.emplace_back(i);
    }
    dfs(n + 1);
    assert(timer == n + 1);
    SegmentTree sg(n + 1);
    const int INF = 1e6;
    sg.upd(1, 0, n, 0, n, -INF);
    auto activate = [&](int id) {
        sg.upd(1, 0, n, tin[id], tin[id], INF);
        sg.upd(1, 0, n, tin[id], tout[id] - 1, +1);
    };
    auto deactivate = [&](int id) {
        sg.upd(1, 0, n, tin[id], tin[id], -INF);
        sg.upd(1, 0, n, tin[id], tout[id] - 1, -1);
    };
    for (int i = 1; i <= k; i++) {
        activate(i);
    }
    for (int i = 1; i <= n - k + 1; i++) {
        cout << sg.get(1, 0, n, 0, n) << " ";
        deactivate(i);
        activate(i + k);
    }

    return 0;
}