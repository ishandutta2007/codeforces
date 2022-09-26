#include <bits/stdc++.h>

using namespace std;

template <typename T> T mod_inv_in_range(T a, T m) {
  // assert(0 <= a && a < m);
  T x = a, y = m;
  T vx = 1, vy = 0;
  while (x) {
    T k = y / x;
    y %= x;
    vy -= k * vx;
    std::swap(x, y);
    std::swap(vx, vy);
  }
  assert(y == 1);
  return vy < 0 ? m + vy : vy;
}
 
template <typename T> T mod_inv(T a, T m) {
  a %= m;
  a = a < 0 ? a + m : a;
  return mod_inv_in_range(a, m);
}
 
template <int MOD_> struct modnum {
  static constexpr int MOD = MOD_;
  static_assert(MOD_ > 0, "MOD must be positive");
 
private:
  using ll = long long;
 
  int v;
 
public:
 
  modnum() : v(0) {}
  modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
  explicit operator int() const { return v; }
  friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
  friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
  friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
  friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
  modnum inv() const {
    modnum res;
    res.v = mod_inv_in_range(v, MOD);
    return res;
  }
  friend modnum inv(const modnum& m) { return m.inv(); }
  modnum neg() const {
    modnum res;
    res.v = v ? MOD-v : 0;
    return res;
  }
  friend modnum neg(const modnum& m) { return m.neg(); }
 
  modnum operator- () const {
    return neg();
  }
  modnum operator+ () const {
    return modnum(*this);
  }
 
  modnum& operator ++ () {
    v ++;
    if (v == MOD) v = 0;
    return *this;
  }
  modnum& operator -- () {
    if (v == 0) v = MOD;
    v --;
    return *this;
  }
  modnum& operator += (const modnum& o) {
    v -= MOD-o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator -= (const modnum& o) {
    v -= o.v;
    v = (v < 0) ? v + MOD : v;
    return *this;
  }
  modnum& operator *= (const modnum& o) {
    v = int(ll(v) * ll(o.v) % MOD);
    return *this;
  }
  modnum& operator /= (const modnum& o) {
    return *this *= o.inv();
  }
 
  friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
  friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
  friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
  friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
  friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
  friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);

    using num = modnum<998244353>;

    int N, M, K; cin >> N >> M >> K;
    
    vector<vector<num>> mat(3 * N, vector<num>(3 * N));

    for (int i = 0; i < M; ++i) {
        int v, u; cin >> v >> u; --v, --u;
        mat[v + N][u] += 1;
        mat[u + N][v] += 1;
        mat[v + 2 * N][v] -= 1;
        mat[u + 2 * N][u] -= 1;
        mat[v + N][u + N] += 1;
        mat[u + N][v + N] += 1;
        mat[v + 2 * N][v + N] -= 1;
        mat[u + 2 * N][u + N] -= 1;
    }

    for (int v = 0; v < N; ++v) {
        mat[v + 2 * N][v + N] += 1;
        mat[v + N][v + 2 * N] += 1;
    }

    auto matMul = [&](vector<vector<num>> A, vector<vector<num>> B) {
        int N = A.size(), M = B.size(), P = B[0].size();
        vector<vector<num>> C(N, vector<num>(P));
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                for (int k = 0; k < P; ++k) {
                    C[i][k] += A[i][j] * B[j][k];
                }
            }
        }
        return C;
    };

    auto matPow = [&](vector<vector<num>> A, int K) {
        int N = int(A.size());
        vector<vector<num>> ans(N, vector<num>(N));
        for (int i = 0; i < N; ++i) ans[i][i] = 1;
        while (K) {
            if (K & 1) ans = matMul(ans, A);
            A = matMul(A, A);
            K >>= 1;
        }
        return ans;
    };

    mat = matPow(mat, K);
    num ans = 0;

    for (int i = 0; i < N; ++i) ans += mat[i][i] + mat[i + N][i];
    cout << ans << '\n';
    return 0;
}