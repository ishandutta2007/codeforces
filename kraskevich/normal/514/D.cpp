#include <bits/stdc++.h>

using namespace std;

struct SegmTree {
    vector<int> tree;
    
    SegmTree(int sz = 0) {
    tree.assign(4 * sz + 100, 0);
    }
    
    void put(int i, int l, int r, int pos, int val) {
    if (l == r) {
        tree[i] = val;
        return;
    }
    int m = (l + r) / 2;
    if (pos <= m)
        put(2 * i + 1, l, m, pos, val);
    else
        put(2 * i + 2, m + 1, r, pos, val);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
    }
    
    int get_max(int i, int tl, int tr, int l, int r) const {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return tree[i];
    int m = (tl + tr) / 2;
    int ml = 0;
    int mr = 0;
    if (l <= m)
        ml = get_max(2 * i + 1, tl, m, l, min(r, m));
    if (r > m)
        mr = get_max(2 * i + 2, m + 1, tr, max(m + 1, l), r);
    return max(ml, mr);
    }
};

int n, m, k;

int getSum(const vector<SegmTree>& st, int l, int r) {
    int res = 0;
    for (int i = 0; i < m; i++)
    res += st[i].get_max(0, 0, n - 1, l, r);
    return res;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    vector<SegmTree> st(m, SegmTree(n));
    for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
        int a;
        cin >> a;
        st[j].put(0, 0, n - 1, i, a);
    }
    int best_len = 0;
    vector<int> best(m);
    for (int l = 0, r = 0; l < n; l++) {
    while (r < n && getSum(st, l, r) <= k)
        r++;
    int cur_len = r - l;
    if (cur_len > best_len) {
        best_len = cur_len;
        for (int j = 0; j < m; j++)
        best[j] = st[j].get_max(0, 0, n - 1, l, r - 1);
    }
    }
    for (int i = 0; i < m; i++)
    cout << best[i] << " ";
    cout << endl;
    return 0;
}