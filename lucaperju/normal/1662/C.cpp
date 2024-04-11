/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("tune=native,bmi")

using namespace std;

template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;

  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
#ifdef _WIN32
    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;
#else
    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
#endif
    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }

  friend const Type& abs(const Modular& x) { return x.value; }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }

template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }

template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }

template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }

template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }

template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }

template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}

template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}

// U == std::ostream? but done this way because of fastoutput
template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}

// U == std::istream? but done this way because of fastinput
template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
constexpr int md = 998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;


/// tourist^^^


typedef long long ll;

template <typename T>
struct Matrix {
    int n, m;
    vector <vector <T>> mat;
    Matrix () {}
    Matrix (const int &_n, const int &_m, const T &val) {
        n = _n; m = _m;
        mat = vector <vector <T>> (n, vector <T> (m, val));
    }
    Matrix (const int &_n, const int &_m) {
        n = _n; m = _m;
        mat = vector <vector <T>> (n, vector <T> (m));
    }
};
template <typename T>
Matrix <T> operator + (const Matrix <T> &A, const Matrix <T> &B) {
    assert(A.n == B.n && A.m == B.m);
    Matrix <T> C(A.n, A.m);
    for (int i = 0; i < C.n; i++) {
        for (int j = 0; j < C.m; j++) {
            C.mat[i][j] = A.mat[i][j] + B.mat[i][j];
        }
    }
    return C;
}
template <typename T>
Matrix <T> operator - (const Matrix <T> &A, const Matrix <T> &B) {
    assert(A.n == B.n && A.m == B.m);
    Matrix <T> C(A.n, A.m);
    for (int i = 0; i < C.n; i++) {
        for (int j = 0; j < C.m; j++) {
            C.mat[i][j] = A.mat[i][j] - B.mat[i][j];
        }
    }
    return C;
}
template <typename T>
Matrix <T> operator * (const Matrix <T> &A, const Matrix <T> &B) {
    assert(A.m == B.n);
    Matrix <T> C(A.n, B.m);
    for (int i = 0; i < C.n; i++) {
        for (int j = 0; j < C.m; j++) {
            C.mat[i][j] = A.mat[i][0] * B.mat[0][j];
            for (int k = 1; k < A.m; k++) {
                C.mat[i][j] = C.mat[i][j] + A.mat[i][k] * B.mat[k][j];
            }
        }
    }
    return C;
}

const ll MOD = (ll) 998244353 * 998244353;

Matrix <Mint> operator * (const Matrix <Mint> &A, const Matrix <Mint> &B) {
    assert(A.m == B.n);
    Matrix <Mint> C(A.n, B.m);
    for (int i = 0; i < C.n; i++) {
        for (int j = 0; j < C.m; j++) {
            ll sum = ll(A.mat[i][0]) * ll(B.mat[0][j]);
            for (int k = 1; k < A.m; k++) {
                sum += ll(A.mat[i][k]) * ll(B.mat[k][j]);
                if (sum >= MOD) {
                    sum -= MOD;
                }
            }
            C.mat[i][j] = sum;
        }
    }
    return C;
}

template <typename T>
T pwr (const T &A, const int &e) {
    if (e == 1) {
        return A;
    } else if (e & 1) {
        return A * pwr(A, (e ^ 1));
    } else {
        T aux = pwr(A, (e >> 1));
        return aux * aux;
    }
}

void print (const Matrix <Mint> &A) {
    for (int i = 0; i < A.n; i++) {
        cout << "(";
        for (int j = 0; j < A.m; j++) {
            cout << A.mat[i][j];
            if (j + 1 < A.m) {
                cout << " ";
            }
        }
        cout << ")\n";
    }
    cout << "\n";
}

Mint getAnswer (const Matrix <Mint> &A, const Matrix <Mint> &B) {
    Mint answer = 0;
    for (int u = 0; u < A.n; u++) {
        answer += A.mat[u][u] - B.mat[u][u];
    }
    return answer;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    Matrix <Mint> adj(n, n, 0), card(n, n, 0), one(n, n, 0), zero(n, n, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; u--; v--;
        adj.mat[u][v] = adj.mat[v][u] = 1;
        card.mat[u][u]++;
        card.mat[v][v]++;
    }
    for (int u = 0; u < n; u++) {
        one.mat[u][u] = 1;
    }

    vector <vector <Matrix <Mint>>> dp (2, vector <Matrix <Mint>> (3, Matrix <Mint> (n, n, 0)));
    for (int u = 0; u < n; u++) {
        dp[0][0].mat[u][u] = 1;
    }
    for (int i = 1; i <= 2; i++) {
        for (int x : {0, 1}) {
            dp[x][i] = dp[x][i] + dp[x][i - 1] * adj;
            if (i - 2 >= 0) {
                dp[x][i] = dp[x][i] + dp[!x][i - 2] * card;
            }
        }
    }

    if (k <= 2) {
        cout << getAnswer(dp[0][k], dp[1][k]) << "\n";
        return 0;
    }

    Matrix <Matrix <Mint>> rec (4, 4, Matrix <Mint> (n, n));
    rec.mat[0][0] =  adj; rec.mat[0][1] =  one; rec.mat[0][2] = zero; rec.mat[0][3] = zero;
    rec.mat[1][0] =  one; rec.mat[1][1] = zero; rec.mat[1][2] = card; rec.mat[1][3] = zero;
    rec.mat[2][0] = zero; rec.mat[2][1] = zero; rec.mat[2][2] =  adj; rec.mat[2][3] =  one;
    rec.mat[3][0] = card; rec.mat[3][1] = zero; rec.mat[3][2] =  one; rec.mat[3][3] = zero;
    rec = pwr(rec, k - 2);

    Matrix <Matrix <Mint>> mk (1, 4, Matrix <Mint> (n, n));
    mk.mat[0][0] = dp[0][2]; mk.mat[0][1] = dp[0][1]; mk.mat[0][2] = dp[1][2]; mk.mat[0][3] = dp[1][1];
    mk = mk * rec;

    cout << getAnswer(mk.mat[0][0], mk.mat[0][2]) << "\n";

    return 0;
}