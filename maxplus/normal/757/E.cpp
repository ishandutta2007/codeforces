#include <iostream>
#include <vector>

using namespace std;

constexpr int m = 1e9l + 7, N = 2e6;

int64_t mpow(int64_t a, int64_t b) {
    int64_t res = 1;
    for (int64_t p = a, d = 1; d <= b; d <<= 1, (p *= p) %= m)
        if (d & b)
            (res *= p) %= m;
    return res;
}

int64_t pow2(int64_t a) {
    return mpow(2, a);
}

inline int64_t rev(int64_t a) {
    return mpow(a, m - 2);
}

inline int64_t mul(int64_t a, int64_t b) {
    return a * b % m;
}

inline int64_t divi(int64_t a, int64_t b) {
    return mul(a, rev(b));
}

inline int64_t sum(int64_t a, int64_t b) {
    return (a + b) % m;
}

inline int64_t dif(int64_t a, int64_t b) {
    return (a - b + m) % m;
}

int fac(int n) {
    static int f[N]{1};
    if (!f[n])
        for (int i = 1; i < N; ++i)
            f[i] = mul(f[i - 1], i);
    return f[n];
}

int rfac(int n) {
    static int rf[N]{1};
    if (!rf[n])
        for (int i = 1; i < N; ++i)
            rf[i] = mul(rf[i - 1], rev(i));
    return rf[n];
}

inline int C(int n, int k) {
    return mul(mul(fac(n), rfac(n - k)), rfac(k));
}

inline int S(int k, int n) {
    return C(n + k - 1, k);
}

    static int q[N][30];
inline int Q(int r, int n) {
    return q[r][n]? q[r][n]: q[r][n] = S(r, n + 1) + S(r, n);
}

int comp[N];
vector<int> primes;

int f(int r, int n) {
    int res = 1;
    for (auto i: primes) if (n % i == 0) {
        int a = 0;
        while (n % i == 0)
            n /= i, ++a;
        res = mul(res, Q(r, a));
    }
    if (n > 1)
        res = mul(res, Q(r, 1));
    return res;
}

int main()
{
    cin.tie(0), ios::sync_with_stdio(0);
    for (int i = 2; i * i < N; ++i) {
        if (!comp[i]) {
            primes.push_back(i);
            for (int j = i * i; j < N; j += i)
                comp[j] = 1;
        }
    }
    int q, r, n;
    cin >> q;
    while (q--) {
        cin >> r >> n;
        cout << f(r, n) << '\n';
    }
    return 0;
}