#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define len(a) int((a).size())

#ifdef LOCAL
    #include "debug.h"
#else
    #define dbg(...)
#endif // LOCAL

template<typename T>
int normalize(T value, int mod) {
    if (value < -mod || value >= 2 * mod)
        value %= mod;

    if (value < 0)
        value += mod;

    if (value >= mod)
        value -= mod;

    return value;
}

template<int mod>
struct static_modular_int {
    using mint = static_modular_int<mod>;

    int value;

    static_modular_int() : value(0) {}
    static_modular_int(const mint &x) : value(x.value) {}

    template<typename T, typename U = std::enable_if_t<std::is_integral<T>::value>>
    static_modular_int(T value) : value(normalize(value, mod)) {}

    template<typename T>
    mint power(T degree) const {
        degree = normalize(degree, mod - 1);
        mint prod = 1;
        mint a = *this;

        for (; degree > 0; degree >>= 1, a *= a)
            if (degree & 1)
                prod *= a;

        return prod;
    }

    mint inv() const {
        return power(-1);
    }

    mint& operator=(const mint &x) {
        value = x.value;
        return *this;
    }

    mint& operator+=(const mint &x) {
        value += x.value;
        if (value >= mod)
            value -= mod;

        return *this;
    }

    mint& operator-=(const mint &x) {
        value -= x.value;
        if (value < 0)
            value += mod;

        return *this;
    }

    mint& operator*=(const mint &x) {
        value = (long long) value * x.value % mod;
        return *this;
    }

    mint& operator/=(const mint &x) {
        return *this *= x.inv();
    }

    friend mint operator+(const mint &x, const mint &y) {
        return mint(x) += y;
    }

    friend mint operator-(const mint &x, const mint &y) {
        return mint(x) -= y;
    }

    friend mint operator*(const mint &x, const mint &y) {
        return mint(x) *= y;
    }

    friend mint operator/(const mint &x, const mint &y) {
        return mint(x) /= y;
    }

    mint& operator++() {
        ++value;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint& operator--() {
        --value;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    mint operator++(int) {
        mint prev = *this;
        value++;
        if (value == mod)
            value = 0;

        return prev;
    }

    mint operator--(int) {
        mint prev = *this;
        value--;
        if (value == -1)
            value = mod - 1;

        return prev;
    }

    mint operator-() const {
        return mint(0) - *this;
    }

    bool operator==(const mint &x) const {
        return value == x.value;
    }

    template<typename T>
    explicit operator T() {
        return value;
    }

    friend std::istream& operator>>(std::istream &in, mint &x) {
        std::string s;
        in >> s;
        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend std::ostream& operator<<(std::ostream &out, const mint &x) {
        return out << x.value;
    }

    static int primitive_root() {
        if constexpr (mod == 1'000'000'007)
            return 5;

        if constexpr (mod == 998'244'353)
            return 3;

        if constexpr (mod == 786433)
            return 10;

        std::vector<int> primes;
        int value = mod - 1;
        for (int i = 2; i * i <= value; i++)
            if (value % i == 0) {
                primes.push_back(i);
                while (value % i == 0)
                    value /= i;
            }

        if (value != 1)
            primes.push_back(value);

        for (int r = 2;; r++) {
            bool ok = true;
            for (auto p : primes)
                if ((mint(r).power((mod - 1) / p)).value == 1) {
                    ok = false;
                    break;
                }

            if (ok)
                return r;
        }
    }
};

// constexpr int MOD = 1'000'000'007;
constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

template<typename node>
struct segtree {
    int n;
    std::vector<node> tree;

    segtree(int n) : n(n), tree(4 * n, node()) {
        build(1, 0, n);
    }

    void build(int v, int vl, int vr) {
        if (vr - vl <= 1)
            return;

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm);
        build(v << 1 | 1, vm, vr);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    }

    template<typename T>
    segtree(const std::vector<T> &arr) : n(arr.size()), tree(4 * n) {
        build(1, 0, n, arr);
    }

    template<typename T>
    void build(int v, int vl, int vr, const std::vector<T> &arr) {
        if (vl == vr)
            return;

        if (vr - vl == 1) {
            tree[v] = node(arr[vl]);
            return;
        }

        int vm = (vl + vr) >> 1;
        build(v << 1, vl, vm, arr);
        build(v << 1 | 1, vm, vr, arr);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    }

    int size() const {
        return n;
    }

    template<typename... Args>
    void update(int l, int r, Args&&... args) {
        _update(1, 0, n, l, r, std::forward<Args>(args)...);
    }

    template<typename... Args>
    void _update(int v, int vl, int vr, int l, int r, Args&&... args) {
        if (r <= vl || vr <= l)
            return;

        if (l <= vl && vr <= r) {
            tree[v].apply(std::forward<Args>(args)..., vl, vr);
            return;
        }

        int vm = (vl + vr) >> 1;
        tree[v].push(tree[v << 1], vl, vr, vl, vm);
        tree[v].push(tree[v << 1 | 1], vl, vr, vm, vr);
        tree[v].clear_after_push();

        _update(v << 1, vl, vm, l, r, std::forward<Args>(args)...);
        _update(v << 1 | 1, vm, vr, l, r, std::forward<Args>(args)...);
        tree[v] = node::merge(tree[v << 1], tree[v << 1 | 1]);
    }

    node query(int l, int r) {
        assert(std::max(0, l) < std::min(n, r)); // or return node() in this case
        return _query(1, 0, n, l, r);
    }

    node _query(int v, int vl, int vr, int l, int r) {
        if (l <= vl && vr <= r)
            return tree[v];

        int vm = (vl + vr) >> 1;
        tree[v].push(tree[v << 1], vl, vr, vl, vm);
        tree[v].push(tree[v << 1 | 1], vl, vr, vm, vr);
        tree[v].clear_after_push();

        if (r <= vm)
            return _query(v << 1, vl, vm, l, r);

        if (vm <= l)
            return _query(v << 1 | 1, vm, vr, l, r);

        return node::merge(_query(v << 1, vl, vm, l, r), _query(v << 1 | 1, vm, vr, l, r));
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    struct node {
        mint sum, to_mult, to_add;
        
        node() {
            sum = 0;
            to_mult = 1;
            to_add = 0;
        }

        void apply(mint up_to_mult, mint up_to_add, int l, int r) {
            sum = sum * up_to_mult + up_to_add * (r - l);
            to_mult *= up_to_mult;
            to_add = to_add * up_to_mult + up_to_add;
        }

        void push(node &child, int vl, int vr, int cl, int cr) {
            child.apply(to_mult, to_add, cl, cr);
        }

        void clear_after_push() {
            to_mult = 1;
            to_add = 0;
        }

        static node merge(const node &left, const node &right) {
            node res;
            res.sum = left.sum + right.sum;
            return res;
        }
    };

    segtree<node> tree(n);
    vector<set<pair<int, int>>> segs(n);

    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;
        l--;

        if (type == 1) {
            int x;
            cin >> x;
            x--;

            auto pass = [&]() {
                tree.update(l, r, 1, 1);
                segs[x].emplace(l, r);
            };

            if (segs[x].empty()) {
                pass();
                continue;
            }

            auto check = [&](const auto &it) {
                return max(it->first, l) < min(it->second, r);
            };

            auto from = segs[x].lower_bound({l, -1});
            if (from != segs[x].begin() && check(prev(from))) {
                from--;
            }
            if (from == segs[x].end() || !check(from)) {
                pass();
                continue;
            }

            auto to = segs[x].lower_bound({r, -1});
            assert(check(prev(to)));

            vector<pair<int, int>> removed;
            removed.reserve(distance(from, to));
            while (from != to) {
                removed.push_back(*from);
                from++;
                segs[x].erase(prev(from));
            }

            if (removed[0].first > l) {
                tree.update(l, removed[0].first, 1, 1);
            }
            if (removed.back().second < r) {
                tree.update(removed.back().second, r, 1, 1);
            }
            for (int i = 0; i < len(removed) - 1; i++) {
                tree.update(removed[i].second, removed[i + 1].first, 1, 1);
            }
            for (auto &[l2, r2] : removed) {
                tree.update(max(l2, l), min(r2, r), 2, 0);
            }

            segs[x].emplace(min(l, removed[0].first), max(r, removed.back().second));
        } else {
            cout << tree.query(l, r).sum << '\n';
        }
    }
}