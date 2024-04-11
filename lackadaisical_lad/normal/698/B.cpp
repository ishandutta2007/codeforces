#include <bits/stdc++.h>

using namespace std;

template <unsigned M_> struct ModInt {
  static constexpr unsigned M = M_;
  unsigned x;
  constexpr ModInt() : x(0) {}
  constexpr ModInt(unsigned x_) : x(x_ % M) {}
  constexpr ModInt(unsigned long long x_) : x(x_ % M) {}
  constexpr ModInt(int x_) : x(((x_ %= static_cast<int>(M)) < 0) ? (x_ + static_cast<int>(M)) : x_) {}
  constexpr ModInt(long long x_) : x(((x_ %= static_cast<long long>(M)) < 0) ? (x_ + static_cast<long long>(M)) : x_) {}
  ModInt &operator+=(const ModInt &a) { x = ((x += a.x) >= M) ? (x - M) : x; return *this; }
  ModInt &operator-=(const ModInt &a) { x = ((x -= a.x) >= M) ? (x + M) : x; return *this; }
  ModInt &operator*=(const ModInt &a) { x = (static_cast<unsigned long long>(x) * a.x) % M; return *this; }
  ModInt &operator/=(const ModInt &a) { return (*this *= a.inv()); }
  ModInt pow(long long e) const {
    if (e < 0) return inv().pow(-e);
    ModInt a = *this, b = 1; for (; e; e >>= 1) { if (e & 1) b *= a; a *= a; } return b;
  }
  ModInt inv() const {
    unsigned a = M, b = x; int y = 0, z = 1;
    for (; b; ) { const unsigned q = a / b; const unsigned c = a - q * b; a = b; b = c; const int w = y - static_cast<int>(q) * z; y = z; z = w; }
    assert(a == 1); return ModInt(y);
  }
  ModInt operator+() const { return *this; }
  ModInt operator-() const { ModInt a; a.x = x ? (M - x) : 0; return a; }
  ModInt operator+(const ModInt &a) const { return (ModInt(*this) += a); }
  ModInt operator-(const ModInt &a) const { return (ModInt(*this) -= a); }
  ModInt operator*(const ModInt &a) const { return (ModInt(*this) *= a); }
  ModInt operator/(const ModInt &a) const { return (ModInt(*this) /= a); }
  template <class T> friend ModInt operator+(T a, const ModInt &b) { return (ModInt(a) += b); }
  template <class T> friend ModInt operator-(T a, const ModInt &b) { return (ModInt(a) -= b); }
  template <class T> friend ModInt operator*(T a, const ModInt &b) { return (ModInt(a) *= b); }
  template <class T> friend ModInt operator/(T a, const ModInt &b) { return (ModInt(a) /= b); }
  explicit operator bool() const { return x; }
  bool operator==(const ModInt &a) const { return (x == a.x); }
  bool operator!=(const ModInt &a) const { return (x != a.x); }
  friend std::ostream &operator<<(std::ostream &os, const ModInt &a) { return os << a.x; }
};

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
using mint = ModInt<1000000007U>;
// using mint = ModInt<998244353U>;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> deg(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        deg[a[i]]++;
    }
    queue<int> leaves;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 0)
            leaves.push(i);
    }
    vector<int> used(n + 1);
    while (!leaves.empty()) {
        int v = leaves.front();
        leaves.pop();
        used[v] = 1;
        if (--deg[a[v]] == 0)
            leaves.push(a[v]);
    }
    int root = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if (a[i] == i)
            root = i;
    for (int i = 1; i <= n; i++) {
        if (used[i])
            continue;
        used[i] = 1;
        for (int j = a[i]; j != i; j = a[j]) {
            used[j] = 1;
        }
        if (root == 0)
            root = i;
        ans += a[i] != root;
        a[i] = root;
    }
    cout << ans << '\n';
    for (int i = 1; i <= n; i++)
        cout << a[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--) {
        solve();
    }
}