#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second

using vint = vector<int>;
using pint = pair<int, int>;
using vpint = vector<pint>;

template <typename A, typename B>
inline void chmin(A& a, B b) {
    if (a > b) a = b;
}
template <typename A, typename B>
inline void chmax(A& a, B b) {
    if (a < b) a = b;
}

template <class A, class B>
ostream& operator<<(ostream& ost, const pair<A, B>& p) {
    ost << "{" << p.first << "," << p.second << "}";
    return ost;
}

template <class T>
ostream& operator<<(ostream& ost, const vector<T>& v) {
    ost << "{";
    for (int i = 0; i < v.size(); i++) {
        if (i) ost << ",";
        ost << v[i];
    }
    ost << "}";
    return ost;
}

inline int topbit(unsigned long long x) {
    return x ? 63 - __builtin_clzll(x) : -1;
}

inline int popcount(unsigned long long x) {
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x) {
    return __builtin_parity(x);
}

template <uint32_t mod>
struct ModInt {
    uint32_t a;
    ModInt& s(uint32_t vv) {
        a = vv < mod ? vv : vv - mod;
        return *this;
    }

    ModInt(int64_t x = 0) { s(x % mod + mod); }

    ModInt& operator+=(const ModInt& x) { return s(a + x.a); }
    ModInt& operator-=(const ModInt& x) { return s(a + mod - x.a); }
    ModInt& operator*=(const ModInt& x) {
        a = uint64_t(a) * x.a % mod;
        return *this;
    }
    ModInt& operator/=(const ModInt& x) {
        *this *= x.inv();
        return *this;
    }

    ModInt operator+(const ModInt& x) const { return ModInt(*this) += x; }
    ModInt operator-(const ModInt& x) const { return ModInt(*this) -= x; }
    ModInt operator*(const ModInt& x) const { return ModInt(*this) *= x; }
    ModInt operator/(const ModInt& x) const { return ModInt(*this) /= x; }
    bool operator==(const ModInt& x) const { return a == x.a; }
    bool operator!=(const ModInt& x) const { return a != x.a; }
    bool operator<(const ModInt& x) const { return a < x.a; }

    ModInt operator-() const { return ModInt() - *this; }
    ModInt pow(int64_t n) const {
        ModInt res(1), x(*this);
        while (n) {
            if (n & 1) res *= x;
            x *= x;
            n >>= 1;
        }
        return res;
    }

    ModInt inv() const { return pow(mod - 2); }
};

template <uint32_t mod>
istream& operator>>(istream& in, ModInt<mod>& a) {
    return (in >> a.a);
}
template <uint32_t mod>
ostream& operator<<(ostream& out, const ModInt<mod>& a) {
    return (out << a.a);
}
using mint = ModInt<10007>;

using mat = vector<vector<mint>>;

string S;
int N;
mint dp[210][210][210];

mat matmul(const mat& A, const mat& B) {
    mat C(A.size(), vector<mint>(A.size()));
    for (int i = 0; i < A.size(); i++) {
        for (int j = i; j < A.size(); j++) {
            for (int k = i; k <= j; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}

mat matpow(mat A, int k) {
    mat ret(A.size(), vector<mint>(A.size()));
    rep(i, A.size()) ret[i][i] = 1;
    while (k) {
        if (k & 1) ret = matmul(ret, A);
        A = matmul(A, A);
        k >>= 1;
    }
    return ret;
}

signed main() {
    cin >> S >> N;
    N += S.size();
    rep(i, S.size()) dp[0][i][i] = 1;
    rep(i, S.size()) dp[0][i][i + 1] = 1;

    for (int i = S.size() - 1; i >= 0; i--) {
        for (int j = i + 2; j <= S.size(); j++) {
            for (int k = 0; k < S.size(); k++) {
                if (S[i] == S[j - 1]) {
                    dp[k][i][j] += dp[k][i + 1][j - 1];
                } else {
                    if (k == 0) continue;
                    dp[k][i][j] += dp[k - 1][i + 1][j];
                    dp[k][i][j] += dp[k - 1][i][j - 1];
                }
            }
        }
    }

    const int X = S.size();
    const int Y = (S.size() + 1) / 2;
    const int Z = Y;

    vector<vector<mint>> A(X + Y + Z, vector<mint>(X + Y + Z));
    rep(i, X) {
        A[i][i] = 24;
        A[i][i + 1] = 1;
    }
    rep(i, Y) {
        A[X + i][X + i] = 25;
        if (i + 1 < Y) A[X + i][X + i + 1] = 1;
        A[X + i][X + Y + i] = 1;
    }
    rep(i, Z) {
        A[X + Y + i][X + Y + i] = 26;
    }

    mat C = matpow(A, (N + 1) / 2 - 1);
    A = matmul(C, A);

    mint ans = 0;
    for (int k = 0; k < S.size(); k++) {
        int l = (S.size() - k + 1) / 2;
        ans += dp[k][0][S.size()] * A[X - k][X + Y + l - 1];
        if ((S.size() - k) % 2 == 0 && N % 2) {
            ans -= dp[k][0][S.size()] * C[X - k][X + l - 1];
        }
    }
    cout << ans << endl;
    return 0;
}