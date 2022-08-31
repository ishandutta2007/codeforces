#include <bits/stdc++.h>

using namespace std;
int n;
const int maxN = (int)1e5 + 10;
int a[maxN];
pair < int, int > t[4 * maxN];
set < pair < int, int > > s;

void build(int v, int tl, int tr) {
    t[v] = make_pair(-1, -1);
    if (tl == tr) return;
    int tm = (tl + tr) / 2;
    build(v + v, tl, tm);
    build(v + v + 1, tm + 1, tr);
}
void upd(int v, int tl, int tr, int val, int pos) {
    if (tl == tr) {
        t[v] = make_pair(val, -1);
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) upd(v + v, tl, tm, val, pos);
    else upd(v + v + 1, tm + 1, tr, val, pos);
    pair < int, int > t1 = t[v + v];
    pair < int, int > t2 = t[v + v + 1];
    t[v] = make_pair(max(t1.first, t2.first), max(max(t1.second, t2.second), min(t1.first, t2.first)));
}
pair < int, int > get_max(int v, int tl, int tr, int l, int r) {
    if (tl == l && tr == r) return t[v];
    int tm = (tl + tr) / 2;
    if (r <= tm) return get_max(v + v, tl, tm, l, r);
    else if (l > tm) return get_max(v + v + 1, tm + 1, tr, l, r);
    else {
        pair < int, int > t1 = get_max(v + v, tl, tm, l, tm);
        pair < int, int > t2 = get_max(v + v + 1, tm + 1, tr, tm + 1, r);
        return make_pair(max(t1.first, t2.first), max(max(t1.second, t2.second), min(t1.first, t2.first)));
    }
}
void go(int a, int b) {
    auto it = s.lower_bound(make_pair(a, -1));
    if (it != s.end() && ((it -> first) == a)) s.erase(it);
    s.insert(make_pair(a, b));
}
bool ok(int num, int bit) {
    s.clear();
    build(1, 1, n);
    for (int i = 1; i <= n; i++) {
        int mx1 = (a[i] >> bit);
        int mx2 = num ^ (mx1);
        //if (bit == 3) cout << mx1 << " " << i << endl;
        upd(1, 1, n, mx1, i);
        int ind = 0;
        auto it = s.lower_bound(make_pair(mx2, -1));
        if (it == s.end() || ((it -> first) != mx2)) {
            go(mx1, i);
            continue;
        }
        else {
            ind = it -> second;
            assert(ind > 0);
            go(mx1, i);
            if (mx1 < mx2) swap(mx1, mx2);
            pair < int, int > tt = get_max(1, 1, n, ind, i);
            pair < int, int > qq = make_pair(mx1, mx2);
            if (tt == qq) return true;
        }
    }
    return false;
}
int main(){
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for (int bit = 29; bit >= 0; bit--) {
        if (ok((ans >> bit) + 1, bit)) ans |= (1 << bit);
    }
    cout << ans;
	return 0;
}