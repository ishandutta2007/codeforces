#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 1000000 + 1;
int mx[maxn << 2], addv[maxn << 2];
#define ls (v << 1)
#define rs (ls | 1)
#define tm midpoint(tl, tr)
void build(int v, int tl, int tr) {
    mx[v] = -maxn;
    if (tl == tr) return;
    build(ls, tl, tm);
    build(rs, tm + 1, tr);
}
void add(int v, int x) {
    addv[v] += x;
    mx[v] += x;
}
void push_down(int v) {
    add(ls, addv[v]);
    add(rs, addv[v]);
    addv[v] = 0;
}
void add(int v, int tl, int tr, int L, int R) {
    if (tl >= L and tr <= R) add(v, 1);
    else {
        push_down(v);
        if (L <= tm) add(ls, tl, tm, L, R);
        if (R > tm) add(rs, tm + 1, tr, L, R);
        mx[v] = max(mx[ls], mx[rs]);
    }
}
void update(int v, int tl, int tr, int p, int x) {
    if (tl == tr) mx[v] = x;
    else {
        push_down(v);
        if (p <= tm) update(ls, tl, tm, p, x);
        else update(rs, tm + 1, tr, p, x);
        mx[v] = max(mx[ls], mx[rs]);
    }
}
int query(int v, int tl, int tr, int L, int R) {
    if (tl >= L and tr <= R) return mx[v];
    int res = -maxn;
    push_down(v);
    if (L <= tm) res = max(res, query(ls, tl, tm, L, R));
    if (R > tm) res = max(res, query(rs, tm + 1, tr, L, R));
    return res;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> s(n), a(n), v = {d}, p(n);
    for (int i = 0; i < n; i += 1) {
        cin >> s[i] >> a[i];
        v.push_back(s[i]);
        v.push_back(a[i]);
        p[i] = i;
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    sort(p.begin(), p.end(), [&](int x, int y) {
        int mx = max(s[x], a[x]), my = max(s[y], a[y]);
        if (mx != my) return mx < my;
        return s[x] < s[y];
    });
    auto fv = [&](int x) {
        return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
    };
    int m = v.size();
    build(1, 1, m);
    update(1, 1, m, fv(d), 0);
    for (int i : p) {
        if (s[i] <= a[i]) {
            int x = query(1, 1, m, 1, fv(s[i]));
            //cout << i << " " << x << "\n";
            update(1, 1, m, fv(a[i]), x + 1);
        }
        else {
            int x = query(1, 1, m, 1, fv(a[i]));
            update(1, 1, m, fv(a[i]), x + 1);
            //cout << i << " " << x << "\n";
            add(1, 1, m, fv(a[i]) + 1, fv(s[i]));
        }
    }
    cout << mx[1];
    return 0;
}