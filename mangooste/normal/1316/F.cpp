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

    template<typename T>
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
        value = (long long) value * x.inv().value % mod;
        return *this;
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
        value++;
        if (value == mod)
            value = 0;

        return *this;
    }

    mint operator--(int) {
        value--;
        if (value == -1)
            value = mod - 1;

        return *this;
    }

    explicit operator int() {
        return value;
    }

    explicit operator long long() {
        return value;
    }

    friend istream& operator>>(istream &in, mint &x) {
        std::string s;
        cin >> s;

        x = 0;
        for (const auto c : s)
            x = x * 10 + (c - '0');

        return in;
    }

    friend ostream& operator<<(ostream &out, const mint &x) {
        return out << x.value;
    }
};

constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;
using mint = static_modular_int<MOD>;

vector<mint> p2;

void init(int n) {
    p2.resize(n + 1, 1);
    for (int i = 1;  i <= n; i++)
        p2[i] = p2[i - 1] * 2;
}

std::mt19937 __rng__(std::chrono::steady_clock::now().time_since_epoch().count());

template<typename T>
struct cartesian_tree {
    struct node {
        T x;
        int left, right, sz, y;
        mint sum_left, sum_right, total;

        node(T x) : x(x), left(-1), right(-1), sz(1), y(__rng__()), sum_left(x), sum_right(x), total(0) {}
    };

    int root;
    std::vector<node> tree;

    cartesian_tree() : root(-1) {}

    void relax(int v) {
        tree[v].sz = 1 + size(tree[v].left) + size(tree[v].right);

        tree[v].total = 0;
        tree[v].sum_left = tree[v].x * p2[size(tree[v].left)];
        tree[v].sum_right = tree[v].x * p2[size(tree[v].right)];

        if (tree[v].left != -1) {
            tree[v].total += tree[tree[v].left].total * p2[size(tree[v].right) + 1];
            tree[v].total += tree[tree[v].left].sum_left * tree[v].x * p2[size(tree[v].right)];
            tree[v].sum_left += tree[tree[v].left].sum_left;
            tree[v].sum_right += tree[tree[v].left].sum_right * p2[size(tree[v].right) + 1];

            if (tree[v].right != -1)
                tree[v].total += tree[tree[v].left].sum_left * tree[tree[v].right].sum_right;
        }

        if (tree[v].right != -1) {
            tree[v].total += tree[tree[v].right].total * p2[size(tree[v].left) + 1];
            tree[v].total += tree[tree[v].right].sum_right * tree[v].x * p2[size(tree[v].left)];
            tree[v].sum_right += tree[tree[v].right].sum_right;
            tree[v].sum_left += tree[tree[v].right].sum_left * p2[size(tree[v].left) + 1];
        }
    }

    int size(int v) const {
        return (v == -1 ? 0 : tree[v].sz);
    }

    int new_node(T x) {
        int id = int(tree.size());
        tree.push_back(node(x));
        return id;
    }

    std::pair<int, int> split_by_key(int v, T x) {
        if (v == -1)
            return {v, v};

        if (tree[v].x <= x) {
            auto cur = split_by_key(tree[v].right, x);
            tree[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            auto cur = split_by_key(tree[v].left, x);
            tree[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    std::pair<int, int> split_by_size(int v, int n) {
        if (v == -1)
            return {v, v};

        if (size(tree[v].left) + 1 <= n) {
            auto cur = split_by_size(tree[v].right, n - size(tree[v].left) - 1);
            tree[v].right = cur.first;
            relax(v);
            return {v, cur.second};
        } else {
            auto cur = split_by_size(tree[v].left, n);
            tree[v].left = cur.second;
            relax(v);
            return {cur.first, v};
        }
    }

    int merge(int left, int right) {
        if (left == -1)
            return right;

        if (right == -1)
            return left;

        if (tree[left].y > tree[right].y) {
            tree[left].right = merge(tree[left].right, right);
            relax(left);
            return left;
        } else {
            tree[right].left = merge(left, tree[right].left);
            relax(right);
            return right;
        }
    }

    int insert(int v, T x, int nv) {
        if (v == -1)
            return nv;

        if (tree[nv].y < tree[v].y) {
            if (x < tree[v].x)
                tree[v].left = insert(tree[v].left, x, nv);
            else
                tree[v].right = insert(tree[v].right, x, nv);

            relax(v);
            return v;
        } else {
            auto [left, right] = split_by_key(v, x);
            tree[nv].left = left;
            tree[nv].right = right;
            relax(nv);
            return nv;
        }
    }

    void insert(T x) {
        int v = new_node(x);
        root = insert(root, x, v);
    }

    int erase(int v, T x) {
        if (v == -1)
            return -1;

        if (tree[v].x == x)
            return merge(tree[v].left, tree[v].right);

        if (x < tree[v].x)
            tree[v].left = erase(tree[v].left, x);
        else
            tree[v].right = erase(tree[v].right, x);

        relax(v);
        return v;
    }

    void erase(T x) {
        root = erase(root, x);
    }

    int size() const {
        return size(root);
    }

    T at(int v, int pos) const {
        if (size(tree[v].left) > pos)
            return at(tree[v].left, pos);

        pos -= size(tree[v].left);
        if (!pos)
            return tree[v].x;

        return at(tree[v].right, pos - 1);
    }

    T at(int pos) const {
        return at(root, pos);
    }

    bool contains(int v, T x) const {
        if (v == -1)
            return false;

        if (tree[v].x == x)
            return true;

        if (tree[v].x < x)
            return contains(tree[v].right, x);

        return contains(tree[v].left, x);
    }

    bool contains(T x) const {
        return contains(root, x);
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    init(n);
    cartesian_tree<int> tree;
    tree.tree.reserve(6e5);
    for (int i = 0; i < n; i++)
        tree.insert(a[i]);

    auto solve = [&]() {
        cout << tree.tree[tree.root].total / p2[n] << '\n';
    };
    solve();

    int q;
    cin >> q;
    while (q--) {
        int position, value;
        cin >> position >> value;
        position--;

        tree.erase(a[position]);
        a[position] = value;
        tree.insert(a[position]);

        solve();
    }
}