#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

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

struct segtree {
    struct node {
        int mn, mod;

        node() : mn(0), mod(0) {}
    };

    node merge(const node &a, const node &b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        res.mod = 0;
        return res;
    }

    void push(int v, int vl, int vr) {
        if (tree[v].mod == 0)
            return;

        tree[v].mn += tree[v].mod;
        if (vr - vl > 1) {
            tree[v << 1].mod += tree[v].mod;
            tree[v << 1 | 1].mod += tree[v].mod;
        }
        tree[v].mod = 0;
    }

    int n;
    vector<node> tree;

    segtree(int n) : n(n), tree(4 * n) {}

    void add(int l, int r, int delta) {
        add(1, 0, n, l, r, delta);
    }

    void add(int v, int vl, int vr, int l, int r, int delta) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            tree[v].mod += delta;
            push(v, vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        add(v << 1, vl, vm, l, r, delta);
        add(v << 1 | 1, vm, vr, l, r, delta);
        tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
    }

    int get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l)
            return INT_MAX;

        push(v, vl, vr);
        if (l <= vl && vr <= r)
            return tree[v].mn;

        int vm = (vl + vr) >> 1;
        return min(get(v << 1, vl, vm, l, r), get(v << 1 | 1, vm, vr, l, r));
    }
};

struct segment {
    int l, r, w;

    friend istream& operator>>(istream &in, segment &seg) {
        in >> seg.l >> seg.r >> seg.w;
        seg.l--, seg.r--;
        return in;
    }

    bool operator<(const segment &seg) const {
        return w < seg.w;
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<segment> segs(n);
    for (auto &x : segs)
        cin >> x;

    sort(all(segs));
    int answer = INT_MAX;
    segtree tree(m);

    auto correct = [&]() {
        return tree.get(0, m - 1) > 0;
    };

    for (int i = 0, j = 0; i < n; i++) {
        tree.add(segs[i].l, segs[i].r, 1);
        while (correct()) {
            tree.add(segs[j].l, segs[j].r, -1);
            j++;
        }

        if (j != 0)
            answer = min(answer, segs[i].w - segs[j - 1].w);
    }

    assert(answer != INT_MAX);
    cout << answer << '\n';
}