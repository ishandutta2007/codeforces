#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define vec vector
#define ar array

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

template<typename A, typename B>
ostream& operator<<(ostream &out, pair<A, B> p) { return out << '(' << p.first << ", " << p.second << ')'; }

template<typename A, typename B = typename enable_if<!is_same<A, string>::value, typename A::value_type>::type>
ostream& operator<<(ostream &out, A vec) { out << '{'; string sep; for (B x : vec) out << sep << x, sep = ", "; return out << '}'; }

void dbg_print() { cerr << endl; }
template<typename A, typename... B> void dbg_print(A a, B... b) { cerr << ' ' << a; dbg_print(b...); }

#ifdef LOCAL
    #define dbg(...) cerr << '#' << __LINE__ << " [" << #__VA_ARGS__ << "]:", dbg_print(__VA_ARGS__)
#else
    #define dbg(...)
#endif

#define data __data__

struct query {
    int left, index;

    query() {}

    query(int left, int index) : left(left), index(index) {}
};

struct data {
    int possible, value;

    data() : possible(0), value(0) {}

    data(int possible, int value) : possible(possible), value(value) {}
};

struct segtree {
    int n;
    vec<data> tree;

    segtree(int n) : n(n), tree(4 * n) {}

    void update(int l, int r, data d) {
        update(1, 0, n, l, r, d);
    }

    void update(int v, int vl, int vr, int l, int r, data d) {
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            if (d.possible > tree[v].possible)
                tree[v] = d;

            return;
        }

        int vm = (vl + vr) >> 1;
        update(v << 1, vl, vm, l, r, d);
        update(v << 1 | 1, vm, vr, l, r, d);
    }

    data query(int pos) {
        return query(1, 0, n, pos, data());
    }

    data query(int v, int vl, int vr, int pos, data best) {
        assert(vl <= pos && pos < vr);

        if (best.possible < tree[v].possible)
            best = tree[v];

        if (vr - vl == 1)
            return best;

        int vm = (vl + vr) >> 1;
        if (pos < vm)
            return query(v << 1, vl, vm, pos, best);

        return query(v << 1 | 1, vm, vr, pos, best);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, vec<int>> positions;
    vec<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        positions[a[i]].push_back(i);
    }

    vec<int> prev(n, -1), nxt(n, n);
    for (auto [value, where] : positions) {
        for (int i = 1; i < len(where); i++)
            prev[where[i]] = where[i - 1];

        for (int i = 0; i < len(where) - 1; i++)
            nxt[where[i]] = where[i + 1];
    }

    int q;
    cin >> q;

    vec<vec<query>> queries(n);
    vec<int> answer(q);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        queries[r - 1].push_back(query(l - 1, i));
    }

    segtree tree(n);
    for (int i = 0; i < n; i++) {
        tree.update(prev[i] + 1, i + 1, data(nxt[i], a[i]));

        for (auto [left, index] : queries[i]) {
            data result = tree.query(left);
            if (result.possible > i)
                answer[index] = result.value;
        }
    }

    for (auto x : answer)
        cout << x << '\n';
}