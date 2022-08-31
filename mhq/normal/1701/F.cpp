#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int maxN = 4e5 + 10;
int fenw[maxN];
void upd(int v, int by) {
    while (v < maxN) {
        fenw[v] += by;
        v = (v | (v - 1)) + 1;
    }
}
int get(int r) {
    int ans = 0;
    while (r > 0) {
        ans += fenw[r];
        r &= (r - 1);
    }
    return ans;
}
int get(int l, int r) {
    if (l > r) return 0;
    return get(r) - get(l - 1);
}
int q, d;
int alive[maxN];
ll S = 0;
ll t_sq[4 * maxN];
ll t_s[4 * maxN];
ll t_0[4 * maxN];
ll lazy[4 * maxN];
void apply(int v, ll x) {
    lazy[v] += x;
    t_sq[v] += x * x * t_0[v];
    t_sq[v] += 2 * x * t_s[v];
    t_s[v] += t_0[v] * x;
}
void merge(int v) {
    t_sq[v] = t_sq[2 * v] + t_sq[2 * v + 1];
    t_s[v] = t_s[2 * v] + t_s[2 * v+ 1];
    t_0[v] = t_0[2 * v] + t_0[2 * v + 1];
}
void push(int v, int tl, int tr) {
    if (tl != tr && lazy[v]) {
        apply(2 * v, lazy[v]);
        apply(2 * v + 1, lazy[v]);
    }
    lazy[v] = 0;
}
#define set sfjslfjslfsf
void set(int v, int tl, int tr, int pos, ll x) {
    if (tl == tr) {
        if (x < 0) {
            assert(x == -1);
            t_s[v] = t_sq[v] = t_0[v] = 0;
            return;
        }
        else {
            t_sq[v] = x * x;
            t_s[v] = x;
            t_0[v] = 1;
        }
        return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    if (pos <= tm) set(2 * v, tl, tm, pos, x);
    else set(2 * v + 1, tm + 1, tr, pos, x);
    merge(v);
}
void upd(int v, int tl, int tr, int l, int r, ll x) {
    if (tr < l || tl > r) return;
    if (l <= tl && tr <= r) {
        apply(v, x);
        return;
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr);
    upd(2 * v, tl, tm, l, r, x);
    upd(2 * v + 1, tm + 1, tr, l, r, x);
    merge(v);
}
bool active[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> q >> d;
    int C = 200000;
    while (q--) {
        int pos;
        cin >> pos;
        if (!active[pos]) {
            upd(1, 1, C, max(pos - d, 1), pos - 1, +1);
            active[pos] = true;
            upd(pos, +1);
            int f = get(pos + 1, pos + d);
            set(1, 1, C, pos, f);
        }
        else {
            upd(1, 1, C, max(pos - d, 1), pos - 1, -1);
            active[pos] = false;
            upd(pos, -1);
            set(1, 1, C, pos, -1);
        }
        ll f = (t_sq[1] - t_s[1]) / 2;
        cout << f << '\n';
    }
    return 0;
}