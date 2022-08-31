#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef double ld;
const int maxN = (int)1e5 + 10;
vector < int > le[maxN], ri[maxN];
int n;
void imp() {
    cout << "IMPOSSIBLE";
    exit(0);
}
int t[maxN][2];
int mx[maxN];
int val[maxN], val_left[maxN];
void solve(int v, int lim) {
    if (v == lim) {
        if ((!le[v].empty()) || (!ri[v].empty())) {
            imp();
        }
        return ;
    }
    int lim2 = val_left[v];
    if (le[v].empty()) {
        t[v][1] = v + 1;
        solve(v + 1, lim);
        return ;
    }
    if (ri[v].empty()) {
        t[v][0] = v + 1;
        solve(v + 1, lim);
        return ;
    }
    if (ri[v][0] <= lim2) imp();
    t[v][0] = v + 1;
    t[v][1] = lim2 + 1;
    solve(v + 1, lim2);
    solve(lim2 + 1, lim);
}
void dfs(int v) {
    if (t[v][0] != 0) {
        dfs(t[v][0]);
    }
    cout << v << " ";
    if (t[v][1] != 0) {
        dfs(t[v][1]);
    }
}
int tree[4 * maxN];
void upd(int v, int tl, int tr, int pos, int val) {
    if (tl == tr) {
        tree[v] = val;
        return ;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        upd(v + v, tl, tm, pos, val);
    }
    else {
        upd(v + v + 1, tm + 1, tr, pos, val);
    }
    tree[v] = max(tree[v + v], tree[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    if (r <= tm) return get(v + v, tl, tm, l, r);
    else if (l > tm) return get(v + v + 1, tm + 1, tr, l, r);
    else {
        return max(get(v + v, tl, tm, l, tm), get(v + v + 1, tm + 1, tr, tm + 1, r));
    }
}
int main() {
    //freopen("input.txt", "r", stdin);
    srand(239);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    int q;
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        if (a >= b) imp();
        if (s == "LEFT") {
            le[a].push_back(b);
        }
        else {
            ri[a].push_back(b);
        }
    }
    for (int i = 1; i <= n; i++) {
        sort(le[i].begin(), le[i].end());
        sort(ri[i].begin(), ri[i].end());
        if (!le[i].empty()) mx[i] = max(mx[i], le[i].back());
        if (!ri[i].empty()) mx[i] = max(mx[i], ri[i].back());
    }
    for (int i = n; i >= 1; i--) {
        val[i] = i;
        if (mx[i] != 0) {
            val[i] = max(val[i], get(1, 1, n, i + 1, mx[i]));
            //for (int j = i + 1; j <= mx[i]; j++) val[i] = max(val[i], val[j]);
        }
        upd(1, 1, n, i, val[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (!le[i].empty()) {
            val_left[i] = i + 1;
            val_left[i] = max(val_left[i], get(1, 1, n, i + 1, le[i].back()));
        }
    }
    solve(1, n);
    dfs(1);
    return 0;
}