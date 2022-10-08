
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int N = 1e6 + 5;
int n, k, t, a[N], p[N], le[N], ri[N], inva[N], depth[N], tree[4 * N], lazy[4 * N], ord[N];
char ch;
vector<pair<char, int>> child[N];

void prop(int i, int l, int r) {
    tree[i] = min(tree[i], lazy[i]);
    if(l < r) {
        lazy[2 * i + 1] = min(lazy[2 * i + 1], lazy[i]);
        lazy[2 * i + 2] = min(lazy[2 * i + 2], lazy[i]);
    }
    lazy[i] = 0;
}
int query(int i, int l, int r, int L, int R) {
    if(r < L || R < l) return INT_MAX;
    prop(i, l, r);
    if(L <= l && r <= R) return tree[i];
    int m = (l + r) / 2;
    return min(query(2 * i + 1, l, m, L, R), query(2 * i + 2, m + 1, r, L, R));
}
void upd(int i, int l, int r, int L, int R, int x) {
    prop(i, l, r);
    if(r < L || R < l) return;
    if(L <= l && r <= R) {
        lazy[i] = min(lazy[i], x);
        prop(i, l, r);
        return;
    }
    int m = (l + r) / 2;
    upd(2 * i + 1, l, m, L, R, x);
    upd(2 * i + 2, m + 1, r, L, R, x);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

void dfs(int x) {
    le[x] = n + 1;
    ri[x] = -1;
    if(inva[ord[x]] > 0) {
        le[x] = ri[x] = inva[ord[x]];
    }
    for(auto pa : child[x]) {
        int i = pa.second;
        dfs(i);
        le[x] = min(le[i], le[x]);
        ri[x] = max(ri[i], ri[x]);
    }
}
void dfs2(int x) {
    if(inva[ord[x]] > 0) {
        depth[x] = min(1 + depth[p[x]], inva[ord[x]] + query(0, 1, k, inva[ord[x]], inva[ord[x]]));
    }else if(x != 0) {
        depth[x] = 1 + depth[p[x]];
    }
    if(le[x] <= ri[x]) {
        upd(0, 1, k, le[x], ri[x], depth[x] - le[x] + 1);
    }
    for(auto pa : child[x]) {
        dfs2(pa.second);
    }
}
void preorder(int x) {
    ord[x] = ++t;
    for(auto pa : child[x]) {
        preorder(pa.second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> p[i] >> ch;
        child[p[i]].emplace_back(ch, i);
    }
    for(int i = 0; i <= n; i++) {
        sort(child[i].begin(), child[i].end());
    }
    preorder(0);
    cin >> k;
    vector<pair<int, int>> ve;
    for(int i = 1; i <= k; i++) {
        cin >> a[i];
        ve.emplace_back(ord[a[i]], i);
    }
    sort(ve.begin(), ve.end());
    for(int i = 1; i <= k; i++) {
        inva[ve[i - 1].first] = i;
    }
    dfs(0);
    dfs2(0);
    for(int i = 1; i <= k; i++) {
        cout << depth[a[i]] << " ";
    }
    cout << endl;
}