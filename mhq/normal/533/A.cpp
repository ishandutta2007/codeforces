#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 5 * (int)1e5 + 100;
int h[maxN];
int k;
int s[maxN];
vector < int > g[maxN];
int seg(int x) {
    if (x >= s[k]) return k;
    if (x < s[1]) return 0;
    int ind = upper_bound(s + 1, s + k + 1, x) - s;
    return ind - 1;
}
pair < int, int > lim[maxN];
int seg_h[maxN];
void dfs(int v, int p) {
    pair < int, int > cur;
    if (p == -1) {
        lim[1] = make_pair(1, 1);
        cur = lim[1];
    }
    else if (p == 1) {
        cur = lim[p];
        if (h[v] < h[1]) cur = make_pair(v, 1);
        else cur = make_pair(1, v);
    }
    else {
        cur = lim[p];
    }
    if (p != 1 && p != -1) {
        if (h[v] < h[cur.first]) {
            cur.second = cur.first;
            cur.first = v;
        } else if (h[v] < h[cur.second]) {
            cur.second = v;
        }
    }
    lim[v] = cur;
    for (int to : g[v]) {
        if (to == p) continue;
        dfs(to, v);
    }
}
vector < int > all[maxN];
int t[4 * maxN];
int lazy[4 * maxN];
void push(int v, int tl, int tr) {
    if (lazy[v] == 0) return ;
    t[v] += lazy[v];
    if (tl != tr) {
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
    }
    lazy[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int val) {
    if (r == 0) return ;
    if (tl == l && tr == r) {
        lazy[v] += val;
        push(v, tl, tr);
        return ;
    }
    push(v, tl, tr);
    if (l > r) return ;
    int tm = (tl + tr) / 2;
    upd(v + v, tl, tm, l, min(r, tm), val);
    upd(v + v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    t[v] = min(t[v + v], t[v + v + 1]);
}
void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = tl;
        return ;
    }
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
    t[v] = min(t[v + v], t[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r) {
    push(v, tl, tr);
    if (l > r) return INT_MAX;
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    return min(get(v + v, tl, tm, l, min(r, tm)), get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int low[maxN];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> h[i];
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    cin >> k;
    for (int i = 1; i <= k; i++) cin >> s[i];
    sort(s + 1, s + k + 1);
    dfs(1, -1);
    for (int i = 1; i <= n; i++) {
        all[lim[i].first].push_back(i);
        seg_h[i] = seg(h[i]);
    }
    build(1, 1, k);
    for (int i = 1; i <= n; i++) {
        int x = seg_h[lim[i].first];
        if (x != 0) {
            upd(1, 1, k, 1, x, 1);
        }
    }
    for (int i = 1; i <= n; i++) {
        low[i] = s[seg_h[i]];
    }
    if (t[1] >= k + 1) {
        cout << 0;
        return 0;
    }
    if (h[1] < s[k]) {
        for (int i = 1; i <= n; i++) {
            if (lim[i].first == 1) {
                upd(1, 1, k, 1, seg_h[1], -1);
                if (i != 1) upd(1, 1, k, 1, seg_h[lim[i].second], 1);
                else upd(1, 1, k, 1, k, 1);
            }
        }
        if (t[1] >= k + 1) {
            cout << s[k] - h[1] << '\n';
        }
        else {
            cout << -1;
        }
        return 0;
    }
    int best = (int)1e9 + 100;
    for (int i = 2; i <= n; i++) {
        if (all[i].empty()) continue;
        sort(all[i].begin(), all[i].end(), [](int a, int b) {
            return h[lim[a].second] < h[lim[b].second];
        });
        int l = seg_h[i];
        int r = k;
        upd(1, 1, k, 1, seg_h[i], -all[i].size());
        for (int t : all[i]) {
            upd(1, 1, k, 1, seg_h[lim[t].second], 1);
        }
        if (t[1] < (k + 1)) {
            upd(1, 1, k, 1, seg_h[i], all[i].size());
            for (int t : all[i]) {
                upd(1, 1, k, 1, seg_h[lim[t].second], -1);
            }
            continue;
        }
        for (int t : all[i]) {
            upd(1, 1, k, 1, seg_h[lim[t].second], -1);
        }
        while (r - l > 1) {
            int mid = (l + r) / 2;
            for (int t = 0; t < all[i].size(); t++) {
                upd(1, 1, k, 1, min(mid, seg_h[lim[all[i][t]].second]), 1);
            }
            if (t[1] >= (k + 1)) r = mid;
            else l = mid;
            for (int t = 0; t < all[i].size(); t++) {
                upd(1, 1, k, 1, min(mid, seg_h[lim[all[i][t]].second]), -1);
            }
        }
        best = min(best, s[r] - h[i]);
        upd(1, 1, k, 1, seg_h[i], all[i].size());
    }
    if (best > (int)1e9) {
        cout << -1;
    }
    else {
        cout << best;
    }
}