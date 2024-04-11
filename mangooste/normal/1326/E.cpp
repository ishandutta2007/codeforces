#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define vec vector
#define ar array

#define all(a) (a).begin(), (a).end()
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

const int N = 3e5 + 4;
const int INF = 2e8;

template<int N>
struct segtree {
    int tree[4 * N], mod[4 * N];

    segtree() { fill(tree, tree + 4 * N, 0), fill(mod, mod + 4 * N, 0); }

    inline void push(int v, int vl, int vr) {
        if (!mod[v]) return;
        if (vr - vl > 1) mod[v << 1] += mod[v], mod[v << 1 | 1] += mod[v];
        tree[v] += mod[v], mod[v] = 0;
    }

    inline void add(int l, int r, int d) { add(1, 0, N, l, r, d); }

    void add(int v, int vl, int vr, int l, int r, int d) {
        if (r <= vl || vr <= l) return;
        if (l <= vl && vr <= r) { mod[v] += d; return; }
        int vm = (vl + vr) >> 1;
        push(v, vl, vr);
        add(v << 1, vl, vm, l, r, d), add(v << 1 | 1, vm, vr, l, r, d);
        push(v << 1, vl, vm), push(v << 1 | 1, vm, vr);
        tree[v] = max(tree[v << 1], tree[v << 1 | 1]);
    }

    inline int get(int l, int r) { return get(1, 0, N, l, r); }

    int get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) return -INF;
        push(v, vl, vr);
        if (l <= vl && vr <= r) return tree[v];
        int vm = (vl + vr) >> 1;
        return max(get(v << 1, vl, vm, l, r), get(v << 1 | 1, vm, vr, l, r));
    }
};

int n, p[N], where[N], cur;
segtree<N> tree;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i], p[i]--;
        where[p[i]] = i;
    }
    cur = n - 1;
    for (int i = 0; i < n; i++) {
        while (1) {
            tree.add(0, where[cur] + 1, 1);
            if (tree.get(0, n) <= 0) {
                cur--;
            } else {
                tree.add(0, where[cur] + 1, -1);
                break;
            }
        }
        cout << cur + 1 << ' ';
        int q; cin >> q; q--;
        tree.add(0, q + 1, -1);
    }
    cout << '\n';
}