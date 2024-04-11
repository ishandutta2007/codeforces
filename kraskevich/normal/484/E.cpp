#include <bits/stdc++.h>

using namespace std;

struct Node {
    vector<int> data;
    vector<int> pref;
    vector<int> suf;
    vector<int> best;
};

struct Result {
    int pref;
    int suf;
    int best;
    bool all;

    Result(int pref = 0, int suf = 0, int best = 0, bool all = true):
        pref(pref), suf(suf), best(best), all(all) {}
};

Result unite(Result a, Result b) {
    Result res(a.pref, b.suf, max(a.best, b.best), a.all && b.all);
    if (a.all)
        res.pref = a.pref + b.pref;
    if (b.all)
        res.suf = a.suf + b.suf;
    res.best = max(res.best, a.suf + b.pref);
    return res;
}

vector<int> init;
vector<Node> tree;

Result get_value(const Node& node, int value) {
    int pos = upper_bound(node.data.begin(), node.data.end(), value) - node.data.begin();
    pos--;
    if (pos < 0)
        return Result(0, 0, 0, false);
    else
        return Result(node.pref[pos], node.suf[pos], node.best[pos], pos == node.data.size() - 1);
}

void build(int i, int l, int r) {
    if (l == r) {
        tree[i].data.push_back(init[l]);
        tree[i].pref.push_back(1);
        tree[i].suf.push_back(1);
        tree[i].best.push_back(1);
        return;
    }
    int m = (l + r) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i].data.resize(tree[2 * i + 1].data.size() + tree[2 * i + 2].data.size());
    merge(tree[2 * i + 1].data.begin(), tree[2 * i + 1].data.end(), tree[2 * i + 2].data.begin(),
          tree[2 * i + 2].data.end(), tree[i].data.begin());
    for (int j = 0; j < tree[i].data.size(); j++) {
        Result a = get_value(tree[2 * i + 1], tree[i].data[j]);
        Result b = get_value(tree[2 * i + 2], tree[i].data[j]);
        Result c = unite(a, b);
        tree[i].pref.push_back(c.pref);
        tree[i].suf.push_back(c.suf);
        tree[i].best.push_back(c.best);
    }
}

Result calc(int i, int l, int r, int tl, int tr, int w) {
    if (l == tl && r == tr)
        return get_value(tree[i], w);
    Result a;
    Result b;
    int m = (tl + tr) / 2;
    if (l <= m)
        a = calc(2 * i + 1, l, min(r, m), tl, m, w);
    if (r > m)
        b = calc(2 * i + 2, max(m + 1, l), r, m + 1, tr, w);
    return unite(a, b);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int n;
    cin >> n;
    init.resize(n);
    tree.resize(4 * n + 10);
    for (int i = 0; i < n; i++) {
        cin >> init[i];
        init[i] *= -1;
    }
    build(0, 0, n - 1);
    sort(init.begin(), init.end());
    int q;
    cin >> q;
    for (int t = 0; t < q; t++) {
        int l, r, w;
        cin >> l >> r >> w;
        l--;
        r--;
        int low = -1;
        int high = n - 1;
        while (high - low > 1) {
            int mid = (low + high) / 2;
            Result res = calc(0, l, r, 0, n - 1, init[mid]);
            if (res.best >= w)
                high = mid;
            else
                low = mid;
        }
        cout << -init[high] << "\n";
    }
    return 0;
}