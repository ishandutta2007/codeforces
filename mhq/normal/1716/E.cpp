#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = (1 << 18) + 20;
int a[maxN];
struct node{
    ll max_suf, max_pref, s, max_s;
    node() {
        max_suf = max_pref = s = max_s = 0;
    }
    node(ll x) {
        max_suf = max(0LL, x);
        max_pref = max(0LL, x);
        s = x;
        max_s = max(0LL, x);
    }
};
vector<node> p[2 * maxN];


node merge(const node& a, const node& b) {
    node c;
    c.s = a.s + b.s;
    c.max_suf = max(b.max_suf, a.max_suf + b.s);
    c.max_pref = max(a.max_pref, a.s + b.max_pref);
    c.max_s = max({a.max_suf + b.max_pref, a.max_s, b.max_s});
    return c;
}

void go(int v, int l, int r) {
    p[v].resize(r - l);
    if (l + 1 == r) {
        p[v][0] = node(a[l]);
        return;
    }
    int len = r - l;
    go(2 * v + 1, l, (l + r) / 2);
    go(2 * v + 2, (l + r) / 2, r);
    for (int t = 0; t < len; t++) {
        if (t < (len / 2)) {
            p[v][t] = merge(p[2 * v + 1][t], p[2 * v + 2][t]);
        }
        else {
            p[v][t] = merge(p[2 * v + 2][t - len / 2], p[2 * v + 1][t - len / 2]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    cin >> n;
    for (int i = 0; i < (1 << n); i++) {
        cin >> a[i];
    }
    go(0, 0, (1 << n));
    int q;
    cin >> q;
    int mask = 0;
    while (q--) {
        int k;
        cin >> k;
        mask ^= (1 << k);
//        cout << " RR " << mask << endl;
        cout << p[0][mask].max_s << '\n';
    }

    return 0;
}