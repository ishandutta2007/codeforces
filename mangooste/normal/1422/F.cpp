#include <algorithm>
#include <array>
#include <cassert>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <vector>

using namespace std;
using ll = long long;

#ifdef LOCAL
#include "/home/lesha/codes/Templates/debug.h"
#else
#define dbg(...)
#endif

#define len(a) int((a).size())
#define all(a) (a).begin(), (a).end()
#define forn(i, l, r) for (int i = int(l); i < int(r); i++)

const int MOD = int(1e9) + 7;
const int MAXA = 2'000'00 + 1;
const int SQRT = int(sqrt(MAXA)) + 1;

inline int mul(int a, int b) {
    return 1ll * a * b % MOD;
}

int power(int a, int b) {
    if (!b) return 1;
    if (b % 2) return mul(a, power(a, b - 1));
    return power(mul(a, a), b / 2);
}

inline int rev(int x) {
    return power(x, MOD - 2);
}

struct segment_tree_primes {
    struct node {
        vector<pair<int, int>> primes = {};
        int prod = 1;

        node operator + (node nd) {
            node res;
            res.prod = prod;

            auto add_unique = [&](pair<int, int> p) {
                res.prod = mul(res.prod, power(p.first, p.second));
                res.primes.push_back(p);
            };

            int j = 0;
            forn (i, 0, len(primes)) {
                while (j < len(nd.primes) && nd.primes[j].first < primes[i].first) {
                    add_unique(nd.primes[j]);
                    j++;
                }

                int deg = primes[i].second;
                if (j != len(nd.primes) && nd.primes[j].first == primes[i].first) {
                    res.prod = mul(res.prod, power(primes[i].first, max(0, nd.primes[j].second - primes[i].second)));
                    deg = max(deg, nd.primes[j].second);
                    j++;
                }
                res.primes.emplace_back(primes[i].first, deg);
            }

            while (j < len(nd.primes)) {
                add_unique(nd.primes[j]);
                j++;
            }
            return res;
        }
    };

    int n;
    vector<node> tree;

    segment_tree_primes(const vector<vector<pair<int, int>>> &small_primes)
        : n(len(small_primes)), tree(4 * n)
    {
        init(1, 0, n, small_primes);
    }

    void init(int v, int vl, int vr, const vector<vector<pair<int, int>>> &small_primes) {
        if (vr - vl == 1) {
            tree[v].primes = small_primes[vl];
            for (auto [p, deg] : small_primes[vl]) {
                tree[v].prod = mul(tree[v].prod, power(p, deg));
            }
            return;
        }

        int vm = (vl + vr) / 2;
        init(2 * v, vl, vm, small_primes);
        init(2 * v + 1, vm, vr, small_primes);
        tree[v] = tree[2 * v] + tree[2 * v + 1];
    }

    inline node get(int l, int r) {
        return get(1, 0, n, l, r);
    }

    node get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) return node();
        if (l <= vl && vr <= r) return tree[v];

        int vm = (vl + vr) / 2;
        return get(2 * v, vl, vm, l, r) + get(2 * v + 1, vm, vr, l, r);
    }
};

struct persistent_segment_tree {
    struct node {
        int prod = 1;
        int left_son = -1;
        int right_son = -1;
    };

    int n;
    int root;
    vector<node> tree;

    persistent_segment_tree(int n) : n(n) {
        tree.reserve(1'000'000);
        root = new_node();
        init(root, 0, n);
    }

    inline int new_node() {
        tree.push_back(node());
        return len(tree) - 1;
    }

    void init(int v, int vl, int vr) {
        if (vr - vl == 1) return;
        int vm = (vl + vr) / 2;
        tree[v].left_son = new_node();
        tree[v].right_son = new_node();

        init(tree[v].left_son, vl, vm);
        init(tree[v].right_son, vm, vr);
    }

    inline void update(int pos, int p) {
        root = update(root, 0, n, pos, p);
    }

    int update(int v, int vl, int vr, int pos, int p) {
        if (pos < vl || vr <= pos) return v;
        int clone = new_node();
        tree[clone] = tree[v];

        if (vr - vl == 1) {
            tree[clone].prod = mul(tree[clone].prod, p);
            return clone;
        }

        int vm = (vl + vr) / 2;
        tree[clone].left_son = update(tree[clone].left_son, vl, vm, pos, p);
        tree[clone].right_son = update(tree[clone].right_son, vm, vr, pos, p);
        tree[clone].prod = mul(tree[tree[clone].left_son].prod, tree[tree[clone].right_son].prod);
        return clone;
    }

    inline int get(int st, int l, int r) {
        return get(st, 0, n, l, r);
    }

    int get(int v, int vl, int vr, int l, int r) {
        if (r <= vl || vr <= l) return 1;
        if (l <= vl && vr <= r) return tree[v].prod;

        int vm = (vl + vr) / 2;
        return mul(get(tree[v].left_son, vl, vm, l, r), get(tree[v].right_son, vm, vr, l, r));
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> small_primes(n);
    vector<int> big_prime(n, -1);

    forn (i, 0, n) {
        int x;
        cin >> x;
        for (int y = 2; y <= SQRT; y++) {
            int deg = 0;
            while (x % y == 0) {
                deg++;
                x /= y;
            }
            if (deg) small_primes[i].emplace_back(y, deg);
        }

        if (x != 1) {
            assert(x > SQRT);
            big_prime[i] = x;
        }
    }

    segment_tree_primes small_primes_tree(small_primes);
    persistent_segment_tree big_primes_tree(n);

    vector<int> positions(MAXA, -1);
    vector<int> versions(n);
    forn (i, 0, n) {
        int p = big_prime[i];
        if (p == -1) {
            versions[i] = big_primes_tree.root;
            continue;
        }

        int pos = positions[p];
        if (pos != -1) {
            big_primes_tree.update(pos, rev(p));
        }

        big_primes_tree.update(i, p);
        versions[i] = big_primes_tree.root;
        positions[p] = i;
    }

    int q;
    cin >> q;
    int last = 0;
    while (q--) {
        int l, r;
        cin >> l >> r;
        l = (l + last) % n;
        r = (r + last) % n;
        if (l > r) swap(l, r);

        last = mul(small_primes_tree.get(l, r + 1).prod, big_primes_tree.get(versions[r], l, r + 1));
        cout << last << '\n';
    }
}