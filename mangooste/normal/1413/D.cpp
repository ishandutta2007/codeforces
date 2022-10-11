#include <bits/stdc++.h>

using namespace std;

#define ts to_string
#define sts string ts
sts(string s) { return s; }
sts(bool b) { return b ? "true" : "false"; }
sts(char c) { return string(1, c); }
sts(const char* s) { return (string) s; }
template<class A, class B> sts(pair<A, B>);
template<class T> sts(T v) { string s = "{", sep = ""; for (auto x : v) { s += sep; sep = ", "; s += ts(x); } return s + "}"; }
template<class A, class B> sts(pair<A, B> p) { return "(" + ts(p.first) + ", " + ts(p.second) + ")"; }
void dbgPrint() { cerr << endl; }
template<class A, class... B> void dbgPrint(A a, B... b) { cerr << " " << ts(a); dbgPrint(b...); }
#ifdef LOCAL
#define dbg(...) cerr << "line #" << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbgPrint(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define sz(a) (int) (a).size()
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

const int INF = (int) 1e9;

struct SegmentTree {
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.resize(4 * n, -INF);
    }

    inline void update(int pos, int newValue) {
        update(1, 0, n, pos, newValue);
    }

    void update(int v, int vl, int vr, int pos, int newValue) {
        if (pos < vl || vr <= pos) {
            return;
        }
        if (vr - vl == 1) {
            tree[v] = newValue;
            return;
        }
        int vm = (vl + vr) / 2;
        update(2 * v, vl, vm, pos, newValue);
        update(2 * v + 1, vm, vr, pos, newValue);
        tree[v] = max(tree[2 * v], tree[2 * v + 1]);
    }

    inline int getMax(int l, int r) {
        return getMax(1, 0, n, l, r);
    }

    int getMax(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) {
            return -INF;
        }
        if (l <= vl && vr <= r) {
            return tree[v];
        }
        int vm = (vl + vr) / 2;
        return max(getMax(2 * v, vl, vm, l, r), getMax(2 * v + 1, vm, vr, l, r));
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<vector<int>> vals(n);
    int bal = 0;
    for (int i = 0; i < 2 * n; i++) {
        char type;
        cin >> type;
        if (type == '+') {
            bal++;
        } else {
            int a;
            cin >> a;
            if (bal == 0) {
                cout << "NO\n";
                return 0;
            }
            vals[bal - 1].push_back(a);
        }
    }

    int cur = 0;
    for (int i = 0; i < n; i++) {
        if (!is_sorted(all(vals[i]))) {
            cout << "NO\n";
            return 0;
        }
        cur += sz(vals[i]);
        if (cur > i + 1) {
            cout << "NO\n";
            return 0;
        }
    }

    SegmentTree tree(n);
    for (int i = 0; i < n; i++) {
        if (sz(vals[i])) {
            tree.update(i, vals[i].back());
        }
    }

    vector<vector<pair<int, int>>> able(n + 1);
    int curNum = -1;
    for (int i = 0; i < n; i++) {
        dbg(i);
        for (auto x : vals[i]) {
            curNum++;

            int l = -1;
            int r = i + 1;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (tree.getMax(mid, i) > x) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            dbg(x, r);

            if (r == i + 1) {
                cout << "NO\n";
                return 0;
            }
            able[r].emplace_back(x, curNum);
        }
    }

    vector<int> ans(n);
    set<pair<int, int>> open;
    for (int i = 0; i < n; i++) {
        for (auto [x, num] : able[i]) {
            open.insert({num, x});
        }
        if (open.empty()) {
            cout << "NO\n";
            return 0;
        }
        ans[i] = open.begin()->second;
        open.erase(open.begin());
    }

    set<int> chk;
    for (int i = 0; i < n; i++) {
        chk.insert(ans[i]);
        for (auto x : vals[i]) {
            if (chk.empty() || *chk.begin() != x) {
                cout << "NO\n";
                return 0;
            }
            chk.erase(chk.begin());
        }
    }

    cout << "YES\n";
    for (auto x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
}