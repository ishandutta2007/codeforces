/*
    23.03.2019 21:54:07
*/

#include <bits/stdc++.h>

using namespace std;

#ifdef HOME
#define TAG_LENGTH 45
#define LR_LEFT left
#define LR_RIGHT right
#define LR_VALUE value
#define LR_SECOND_VALUE mn
#include "C:/C++ libs/print.cpp"
#define showl cout << endl;
#define shows cout << string(5, ' ') + string(TAG_LENGTH, '-') << endl;
#else
#define show(...) 42;
#define showt(...) 42;
#define showl 42;
#define shows 42;
#define print(...) 42;
#define printTree(...) 42;
#define printLRTree(...) 42;
#define printMatrix(...) 42;
#endif

// map<pair<int, int>, int> ind;
// map<int, int> mpx, mpy;
// vector<pair<int, int>> pts;
vector<int> par;
vector<int> rnk;
vector<long long> answer;
vector<long long> xs, ys;
long long ans = 0;
int dsu_ind = 0;
int ch = 0;

struct change {
    int i = -1;
    int p;
    int rank_delta;
    int was_x;
    int was_y;
};
vector<change> changes;

int parent(int v) {
    while (v != par[v])
        v = par[v];
    return v;
}

change unite(int u, int v) {
    int pu = parent(u), pv = parent(v);
    change c;
    // show(pu, pv);
    if (pu == pv) return c;
    if (rnk[pu] < rnk[pv] || (rnk[pu] == rnk[pv] && rand() % 2 == 1)) {
        c.i = pu;
        c.p = pv;
        c.rank_delta = rnk[pu];
        c.was_x = xs[pv];
        c.was_y = ys[pv];
        ans -= xs[pu] * ys[pu] + xs[pv] * ys[pv];
        par[pu] = pv;
        xs[pv] += xs[pu];
        ys[pv] += ys[pu];
        ans += xs[pv] * ys[pv];
    } else {
        c.i = pv;
        c.p = pu;
        c.rank_delta = rnk[pv];
        c.was_x = xs[pu];
        c.was_y = ys[pu];
        ans -= xs[pu] * ys[pu] + xs[pv] * ys[pv];
        par[pv] = pu;
        xs[pu] += xs[pv];
        ys[pu] += ys[pv];
        ans += xs[pu] * ys[pu];
    }
    show(xs, ys);
    return c;
}

struct segtree {
    int n;
    vector<vector<pair<int, int>>> tree;

    segtree(int n) : n(n), tree(n * 4) {};

    void add(int l, int r, pair<int, int>& p, int i, int vl, int vr) {
        if (l == vl && r == vr) {
            tree[i].push_back(p);
            ++ch;
            return;
        }
        int m = (vl + vr) / 2;
        if (r <= m) add(l, r, p, 2 * i + 1, vl, m);
        else if (l > m) add(l, r, p, 2 * i + 2, m + 1, vr);
        else {
            add(l, m, p, 2 * i + 1, vl, m);
            add(m + 1, r, p, 2 * i + 2, m + 1, vr);
        }
    }

    void add(int l, int r, pair<int, int> p) {
        add(l, r, p, 0, 0, n - 1);
    }

    void dfs(int i, int l, int r) {
        // do something
        int sz = changes.size();
        for (auto p : tree[i]) {
            auto c = unite(p.first, p.second);
            if (c.i != -1)
                changes.push_back(c);
        }
        if (l == r) {
            answer[l] = ans;
        } else {
            int m = (l + r) / 2;
            dfs(2 * i + 1, l, m);
            dfs(2 * i + 2, m + 1, r);
        }
        // cancel something
        while (changes.size() > sz) {
            if (changes.back().i != -1) {
                par[changes.back().i] = changes.back().i;
                rnk[changes.back().p] -= changes.back().rank_delta;
                ans -= xs[changes.back().p] * ys[changes.back().p];
                xs[changes.back().p] = changes.back().was_x;
                ys[changes.back().p] = changes.back().was_y;
                ans += xs[changes.back().i] * ys[changes.back().i];
                ans += xs[changes.back().p] * ys[changes.back().p];
            }
            changes.pop_back();
        }
    }

    void dfs() {
        dfs(0, 0, n - 1);
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    segtree t(n);
    map<pair<int, int>, int> mp;
    xs.assign(n * 2 + 3, 0);
    ys.assign(n * 2 + 3, 0);
    vector<int> compx, compy;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i) {
        cin >> points[i].first >> points[i].second;
        compx.push_back(points[i].first);
        compy.push_back(points[i].second);
    }
    sort(compx.begin(), compx.end());
    compx.erase(unique(compx.begin(), compx.end()), compx.end());
    sort(compy.begin(), compy.end());
    compy.erase(unique(compy.begin(), compy.end()), compy.end());
    for (int i = 0; i < n; ++i) {
        points[i].first = lower_bound(compx.begin(), compx.end(), points[i].first) - compx.begin();
        points[i].second = lower_bound(compy.begin(), compy.end(), points[i].second) - compy.begin();
        points[i].second += compx.size();
        xs[points[i].first] = 1;
        ys[points[i].second] = 1;
    }
    for (int i = 0; i < n; ++i) {
        auto p = points[i];
        auto it = mp.find(p);
        if (it == mp.end()) {
            mp[p] = i;
        } else if (it->second == -1) {
            it->second = i;
        } else {
            t.add(it->second, i - 1, p);
            it->second = -1;
        }
        // if (ind.find(p) == ind.end()) {
        //     int sz = ind.size();
        //     ind[p] = sz;
        //     // pts.push_back(p);
        //     if (mpx.find(p.first) == mpx.end()) {
        //         xs[dsu_ind] = 1;
        //         mpx[p.first] = dsu_ind++;
        //     }
        //     if (mpy.find(p.second) == mpy.end()) {
        //         ys[dsu_ind] = 1;
        //         mpy[p.second] = dsu_ind++;
        //     }
        // }
    }
    for (auto p : mp) {
        if (p.second != -1)
            t.add(p.second, n - 1, p.first);
    }
    changes.reserve(ch + 10);
    // show(xs, ysx);
    par.resize(n * 2 + 3);
    answer.resize(n);
    rnk.assign(n * 2 + 3, 1);
    for (int i = 0; i < n * 2 + 3; ++i) {
        par[i] = i;
    }
    t.dfs();
    for (int i = 0; i < n; ++i) {
        cout << answer[i] << ' ';
    }
    cout << '\n';
    return 0;
}