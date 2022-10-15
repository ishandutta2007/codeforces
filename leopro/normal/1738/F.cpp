#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

#define answer(out) { cout << (out) << '\n'; return; }
#define answerExit(out) { cout << (out) << '\n'; exit(0); }

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

struct ModInt {
    static const int MOD = 998244353;
    int value;

    ModInt(long long x) : value(x % MOD) {}

    ModInt(int x = 0) : value(x < 0 ? x + MOD : x) {}

    ModInt(int x, int) : value(x) {} // unchecked constructor

    ModInt operator+() const { return *this; }

    ModInt operator+(ModInt m) const {
        int res = value + m.value;
        if (res >= MOD) res -= MOD;
        return {res, 0};
    }

    ModInt operator+=(ModInt m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return *this;
    }

    ModInt operator-() const { return {value ? MOD - value : 0, 0}; }

    ModInt operator-(ModInt m) const {
        return value - m.value;
    }

    ModInt operator-=(ModInt m) {
        value -= m.value;
        if (value < 0) value += MOD;
        return *this;
    }

    ModInt operator*(ModInt m) const { return value * 1LL * m.value; }

    ModInt operator*=(ModInt m) {
        value = (value * 1LL * m.value) % MOD;
        return *this;
    }

    ModInt power(int exp) const {
        if (exp == 0) return 1;
        if (exp & 1) return *this * power(exp - 1);
        return (*this * *this).power(exp / 2);
    }

    ModInt operator/(ModInt m) const { return *this * m.power(MOD - 2); }

    ModInt operator/=(ModInt m) { return *this *= m.power(MOD - 2); }

    friend std::istream &operator>>(std::istream &is, ModInt &m) {
        is >> m.value;
        return is;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &m) {
        os << m.value;
        return os;
    }

    explicit operator int() const { return value; }
};

int query(int x) {
    cout << "? " << x + 1 << endl;
    cin >> x;
    return x - 1;
}

void solve() {
    int n;
    cin >> n;
    vector<int> d(n);
    for (int &x: d) cin >> x;
    vector<int> ind(n);
    iota(ind.begin(), ind.end(), 0);
    sort(ind.begin(), ind.end(), [&](int u, int v) { return d[u] > d[v]; });
    vector<vector<int>> partition;
    vector<int> seen(n, -1);
    for (int u: ind) {
        if (seen[u] != -1) continue;
        partition.push_back({u});
        seen[u] = partition.size() - 1;
        for (int t = 0; t < d[u]; ++t) {
            int nxt = query(u);
            if (seen[nxt] != -1) {
                for (int x: partition.back()) seen[x] = seen[nxt];
                for (int y : partition.back()) partition[seen[nxt]].push_back(y);
                partition.pop_back();
                break;
            } else {
                seen[nxt] = partition.size() - 1;
                partition.back().push_back(nxt);
            }
        }
    }
    cout << "!";
    vector<int> color(n);
    int c = 1;
    for (auto &row: partition) {
        for (int x: row) color[x] = c;
        c++;
    }
    for (int i = 0; i < n; ++i) cout << " " << color[i];
    cout << endl;
}