/*input
7
3 1
1 2 3
3 1
1 -1 100
3 1
2 4
3 1

*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x, y) ((x >> y) & 1)
#define loop(i, l, r) for (int i = l; i <= r; i++)
#define rloop(i, l, r) for (int i = l; i >= r; i--)
#ifdef UncleGrandpa
#include <prettyprint.hpp>
void print() {cout << endl;} template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value << ' ', print(values...);}
void debug() {cerr << endl;} template<typename T, typename... Ts> void debug(const T& value, const Ts&... values) {cerr << value << ' ', debug(values...);}
#endif
const int N = 3e5 + 5;

using ll = long long;
struct Line {
    mutable ll A, B, p, sta, en;
    bool operator<(const Line& o) const { return A < o.A; }
    bool operator<(ll x) const { return p < x; }
};

const ll INF = LLONG_MAX;

struct LineContainer : multiset<Line, less<>> {
    ll div(ll a, ll b) {
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) { x->p = INF; return false; }
        if (x->A == y->A) x->p = x->B > y->B ? INF : -INF;
        else x->p = div(y->B - x->B, x->A - y->A);
        return x->p >= y->p;
    }
    void add(ll A, ll m) {
        auto z = insert({A, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }
    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.A * x + l.B;
    }
};

LineContainer f[4 * N];
void init(int k, int l, int r) {
    if (l == r) return;
    int mid = (l + r) / 2;
    init(k * 2, l, mid); init(k * 2 + 1, mid + 1, r);
}

void update(int k, int l, int r, const int L, const int R, const Line X) {
    if (r < L || R < l) return;
    if (L <= l && r <= R) {
        f[k].add(X.A, X.B);
        return;
    }
    int mid = (l + r) / 2;
    update(k * 2, l, mid, L, R, X); update(k * 2 + 1, mid + 1, r, L, R, X);
}

int get(int k, int l, int r, int pos, int X) {
    if (r < pos || pos < l) return -INF;
    int ret = -INF;
    if (!f[k].empty()) ret = f[k].query(X);
    if (l == r) return ret;
    int mid = (l + r) / 2;
    ret = max(ret, get(k * 2, l, mid, pos, X));
    ret = max(ret, get(k * 2 + 1, mid + 1, r, pos, X));
    return ret;
}

signed main() {
#ifndef UncleGrandpa
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#endif
    vector<Line> line; vector<int> where(N);
    vector<pair<int, int> > query;// pair Time, X
    int q;
    cin >> q;
    loop(Q, 1, q) {
        int type; cin >> type;
        if (type == 1) {
            Line X;
            cin >> X.A >> X.B; X.sta = Q; X.en = q;
            line.push_back(X); where[Q] = line.size() - 1;
        }
        else if (type == 2) {
            int t; cin >> t;
            line[where[t]].en = Q;
        }
        else if (type == 3) {
            int x; cin >> x;
            query.push_back({Q, x});
        }
    }
    sort(line.begin(), line.end(), [&](Line X, Line Y) {
        return X.A < Y.A;
    });
    init(1, 1, q);
    for (auto it : line) {
        update(1, 1, q, it.sta, it.en, it);
    }
    for (auto it : query) {
        int rec = get(1, 1, q, it.fi, it.se);
        if (rec == -INF) cout << "EMPTY SET" << endl;
        else cout << rec << endl;
    }
}