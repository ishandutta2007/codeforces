#include <bits/stdc++.h>

using ll = long long;
using namespace std;

void solve();

struct ModInt {
    static const int MOD = 998244353;
    int value;

    ModInt(int i = 0) : value(i) {}

    ModInt operator+(ModInt m) const {
        ModInt lhs = *this;
        lhs += m;
        return lhs;
    }

    ModInt operator+=(ModInt m) {
        value += m.value;
        if (value >= MOD) value -= MOD;
        return value;
    }

    ModInt operator-(ModInt m) const {
        ModInt lhs = *this;
        lhs -= m;
        return lhs;
    }

    ModInt operator-=(ModInt m) {
        value -= (m.value - MOD);
        if (value >= MOD) value -= MOD;
        return value;
    }

    ModInt operator*(ModInt m) const { return (value * 1LL * m.value) % MOD; }

    ModInt operator*=(ModInt m) {
        value = (value * 1LL * m.value) % MOD;
        return value;
    }

    ModInt power(int exp) {
        if (exp == 0) return 1;
        ModInt res = (exp & 1 ? value : 1);
        ModInt half = power(exp >> 1);
        return res * half * half;
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

vector<ModInt> fact;
vector<ModInt> inv;

void calculateFactorials(int MAX) {
    fact.assign(MAX, 1);
    inv.assign(MAX, 1);
    for (int i = 2; i < MAX; ++i) fact[i] = fact[i - 1] * i;
    inv[MAX - 1] = ModInt(1) / fact[MAX - 1];
    for (int i = MAX - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1);
}

ModInt C(int n, int k) {
    return fact[n] * inv[k] * inv[n - k];
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    calculateFactorials(4e5 + 3);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        solve();
    }
    return 0;
}

struct vertex {
    vertex *left = nullptr, *right = nullptr;
    int sum;

    explicit vertex(int sum) : sum(sum) {}

    vertex *getLeft() {
        return left ? left : left = new vertex(0);
    }

    vertex *getRight() {
        return right ? right : right = new vertex(0);
    }
};

vertex *build(int size) {
    return new vertex(0);
}

void setOne(vertex *cur, int l, int r, int k) {
    cur->sum++;
    if (l + 1 == r) return;
    int m = (l + r) / 2;
    if (k < m) {
        setOne(cur->getLeft(), l, m, k);
    } else {
        setOne(cur->getRight(), m, r, k);
    }
}

int kthZero(vertex *cur, int l, int r, int k) {
    if (l + 1 == r) return l;
    int m = (l + r) / 2;
    int leftZeros = (m - l) - (cur->left ? cur->left->sum : 0);
    if (k < leftZeros) return kthZero(cur->getLeft(), l, m, k);
    return kthZero(cur->getRight(), m, r, k - leftZeros);
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> swaps(m);
    for (auto &[x, y] : swaps) {
        cin >> x >> y;
    }
    reverse(swaps.begin(), swaps.end());
    vertex *root = build(n);
    vector<int> b;
    for (auto[x, y] : swaps) {
        --y;
        int newY = kthZero(root, 0, n, y);
        setOne(root, 0, n, newY);
        b.push_back(kthZero(root, 0, n, y));
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    int ups = n - 1 - b.size();
    int rights = n;
    cout << C(ups + rights, ups) << "\n";
}