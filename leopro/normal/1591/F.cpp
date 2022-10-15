#include <bits/stdc++.h>

using namespace std;
using ll = long long;

void solve();

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int t = 1;
//    cin >> t;
    do { solve(); } while (--t);
    return 0;
}

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

struct vertex {
    vertex *left = nullptr, *right = nullptr;
    ModInt sum;
    ModInt add;
    int size;

    void push() {
        if (left) {
            left->apply(add);
            right->apply(add);
            add = 0;
        } else {
            getLeft();
            getRight();
            add = 0;
        }
    }

    void update() {
        sum = left->sum + right->sum;
    }

    explicit vertex(ModInt x, int size) : sum(x * size), size(size), add(x) {}

    vertex *getLeft() {
        return left ? left : left = new vertex(add, size / 2);
    }

    vertex *getRight() {
        return right ? right : right = new vertex(add, (size + 1) / 2);
    }

    void apply(ModInt x) {
        sum += x * size;
        add += x;
    }
    ~vertex(){
        delete left;
        delete right;
    }
};

vertex *build(int size, ModInt w) {
    return new vertex(w, size);
}

void add(vertex *cur, int curL, int curR, int l, int r, ModInt x) {
    if (r <= curL || curR <= l) return;
    if (l <= curL && curR <= r) return cur->apply(x);
    cur->push();
    int curM = (curL + curR) / 2;
    add(cur->left, curL, curM, l, r, x);
    add(cur->right, curM, curR, l, r, x);
    return cur->update();
}

void zero(vertex *&cur, int curL, int curR, int l, int r) {
    if (r <= curL || curR <= l) return;
    if (l <= curL && curR <= r) {
        delete cur;
        cur = new vertex(0, cur->size);
        return;
    }
    cur->push();
    int curM = (curL + curR) / 2;
    zero(cur->left, curL, curM, l, r);
    zero(cur->right, curM, curR, l, r);
    return cur->update();
}

ModInt get(vertex *cur, int curL, int curR, int l, int r) {
    if (r <= curL || curR <= l) return 0;
    if (l <= curL && curR <= r) return cur->sum;
    cur->push();
    int curM = (curL + curR) / 2;
    ModInt lf = get(cur->left, curL, curM, l, r);
    ModInt rg = get(cur->right, curM, curR, l, r);
    return lf + rg;
}

#define LR 0, 1e9 + 1

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x: a) cin >> x;
    auto *dp = build(1e9 + 1, 0), *dpn = build(1e9 + 1, 0);
    for (int i = 0; i < n; ++i) {
        ModInt s = i ? get(dp, LR, 1, a[i - 1] + 1) : ModInt(1);
        swap(dp, dpn);
        if ((int) s) {
            add(dp, LR, 1, a[i] + 1, s);
            add(dpn, LR, 1, a[i] + 1, ModInt::MOD - (int) s);
        }
        zero(dp, LR, a[i] + 1, 1e9 + 1);
        zero(dpn, LR, a[i] + 1, 1e9 + 1);
    }
    cout << get(dp, LR, 1, a.back() + 1) << '\n';
}