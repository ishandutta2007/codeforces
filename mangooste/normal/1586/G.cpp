#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;

#define all(a) begin(a), end(a)
#define rall(a) rbegin(a), rend(a)
#define len(a) ((int)((a).size()))

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

struct segtree {
    int n;
    vector<mint> tree;
    vector<pair<int, mint>> updates;

    segtree(int n) : n(n), tree(4 * n) {}

    mint query(int pos) {
        return query(1, 0, n, pos, 0);
    }

    mint query(int v, int vl, int vr, int pos, mint tot) {
        assert(vl <= pos);
        tot += tree[v];
        if (vr - vl == 1)
            return tot;

        int vm = (vl + vr) >> 1;
        return pos < vm ? query(v << 1, vl, vm, pos, tot) : query(v << 1 | 1, vm, vr, pos, tot);
    }

    int add(int pref, mint value) {
        int prev_size = len(updates);
        add(1, 0, n, pref, value);
        return len(updates) - prev_size;
    }

    void add(int v, int vl, int vr, int pref, mint value) {
        if (pref <= vl)
            return;

        if (vr <= pref) {
            updates.emplace_back(v, tree[v]);
            tree[v] += value;
            return;
        }

        int vm = (vl + vr) >> 1;
        add(v << 1, vl, vm, pref, value);
        add(v << 1 | 1, vm, vr, pref, value);
    }

    void roll_back(int cnt) {
        while (cnt--) {
            tree[updates.back().first] = updates.back().second;
            updates.pop_back();
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    vector<int> who(2 * n, -1);

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        a[i]--, b[i]--;
        who[b[i]] = i;
    }

    auto cmp = [&](int i, int j) {
        return b[i] < b[j];
    };
    set<int, decltype(cmp)> st(cmp);

    int need;
    cin >> need;
    while (need--) {
        int x;
        cin >> x;
        x--;
        st.insert(x);
    }

    segtree tree(2 * n);
    mint answer = 0;
    vector<int> roll_back(2 * n);
    set<int> alive;

    auto query = [&](int pos) -> mint {
        auto it = alive.lower_bound(pos);
        if (it == alive.end())
            return 0;

        return tree.query(*it);
    };

    for (int i = 0; i < 2 * n; i++) {
        if (who[i] == -1)
            continue;

        int id = who[i];
        int pos = a[id];

        if (*st.rbegin() == id) {
            st.erase(prev(st.end()));
            answer++;

            while (!st.empty()) {
                int last = *st.rbegin();
                st.erase(prev(st.end()));
                if (a[last] < pos)
                    continue;

                while (i != b[last] - 1) {
                    tree.roll_back(roll_back[i]);
                    if (who[i] != -1)
                        alive.erase(a[who[i]]);

                    i--;
                }

                answer += query(pos + 1);
                answer++;
                pos = a[last];
            }

            break;
        }

        auto value = query(pos);
        answer += value + 1;

        mint cur_value = tree.query(pos);
        mint to_add = 2 * value + 1 - cur_value;
        roll_back[i] += tree.add(pos, 0 - to_add);
        roll_back[i] += tree.add(pos + 1, to_add);
        roll_back[i] += tree.add(pos, value + 1);

        alive.insert(pos);
    }

    cout << answer << '\n';
}