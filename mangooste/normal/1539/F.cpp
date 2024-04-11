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
    int n;
    vector<int> tree;
    vector<int> mod;

    segtree() {}
    segtree(int n) : n(n), tree(4 * n), mod(4 * n) {
        build(1, 0, n);
    }

    inline void reset() {
        build(1, 0, n);
    }

    void build(int v, int vl, int vr) {
        tree[v] = mod[v] = 0;
        if (vr - vl == 1)
            return;

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
    }

    inline void push(int v, int vl, int vr) {
        if (vr - vl > 1) {
            mod[v << 1] += mod[v];
            mod[v << 1 | 1] += mod[v];
        }
        tree[v] += mod[v];
        mod[v] = 0;
    }

    inline void add(int l, int r, int delta) {
        add(1, 0, n, l, r, delta);
    }

    void add(int v, int vl, int vr, int l, int r, int delta) {
        push(v, vl, vr);
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            mod[v] += delta;
            push(v, vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        add(v << 1, vl, vm, l, r, delta);
        add(v << 1 | 1, vm, vr, l, r, delta);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }

    inline int get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    int get(int v, int vl, int vr, int l, int r) {
        push(v, vl, vr);
        if (l <= vl && vr <= r)
            return tree[v];

        int vm = (vl + vr) >> 1;
        if (r <= vm)
            return get(v << 1, vl, vm, l, r);

        if (vm <= l)
            return get(v << 1 | 1, vm, vr, l, r);

        return max(get(v << 1, vl, vm, l, r), get(v << 1 | 1, vm, vr, l, r));
    }

    friend ostream& operator<<(ostream &out, segtree tree) {
        out << '{';
        string sep;
        for (int i = 0; i < tree.n; i++)
            out << sep << tree.get(i, i + 1), sep = ", ";

        return out << '}';
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i], a[i]--;

    vector<int> answer(n);
    for (int rot = 0; rot < 2; rot++) {
        segtree tree_left(n);
        for (int i = 0; i < n; i++)
            tree_left.add(i, i + 1, -i);

        segtree tree_right(n);
        for (int i = 0; i < n; i++)
            tree_right.add(i, i + 1, i);

        vector<vector<int>> events(n);
        for (int i = 0; i < n; i++)
            events[a[i]].push_back(i);

        for (int i = 0; i < n; i++) {
            for (auto pos : events[i]) {
                int actual = (rot ? n - 1 - pos : pos);
                answer[actual] = max(answer[actual], (tree_left.get(0, pos + 1) + tree_right.get(pos, n) + (rot ? 0 : 1)) / 2);
            }

            for (auto pos : events[i]) {
                tree_right.add(pos, n, -2);
                tree_left.add(pos + 1, n, 2);
            }
        }

        reverse(all(a));
        for (int i = 0; i < n; i++)
            a[i] = n - 1 - a[i];
    }

    for (auto x : answer)
        cout << x << ' ';

    cout << '\n';
}