#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <ctime>

using namespace std;

constexpr int N = 1e3, mod = 1e9 + 7;

namespace {
    constexpr int mod = 1e9 + 7, LIN = 1e7, SQ = 3e3;

    int64_t mpow(int64_t a, int64_t b) {
        int64_t res = 1;
        for (int64_t p = a, d = 1; d <= b && d; d <<= 1, (p *= p) %= mod)
            if (d & b)
                (res *= p) %= mod;
        return res;
    }

    inline int64_t rev(int64_t a) {
        return mpow(a, mod - 2);
    }

    template<class arg1, class arg2>
    inline typename common_type<arg1, arg2>::type prod(arg1 a, arg2 b) {
        return (typename common_type<arg1, arg2, int64_t>::type)a * b % mod;
    }

    template<class arg1, class arg2>
    inline arg1& mul(arg1 &a, arg2 b) {
        return a = prod(a, b);
    }

    template<class arg1, class arg2>
    inline typename common_type<arg1, arg2>::type quot(arg1 a, arg2 b) {
        return prod(a, rev(b));
    }

    template<class arg1, class arg2>
    inline arg1& divi(arg1 &a, arg2 b) {
        return a = quot(a, b);
    }

    template<class arg1, class arg2>
    inline typename common_type<arg1, arg2>::type sum(arg1 a, arg2 b) {
        return a + b >= mod? a + b - mod: a + b;
    }

    template<class arg1, class arg2>
    inline arg1& add(arg1 &a, arg2 b) {
        return a = sum(a, b);
    }

    template<class arg1, class arg2>
    inline typename common_type<arg1, arg2>::type dif(arg1 a, arg2 b) {
        return sum(a, mod - b);
    }

    template<class arg1, class arg2>
    inline arg1& sub(arg1 &a, arg2 b) {
        return add(a, mod - b);
    }

    #define EXTENDNM(fname) \
    template<class arg1t, class arg2t, class... argst> \
    inline typename common_type<arg1t, arg2t, argst...>::type fname(const arg1t& arg1, const arg2t& arg2, const argst&... args) { \
        return fname(fname(arg1, arg2), args...); \
    }

    #define EXTENDM(fname) \
    template<class arg1t, class arg2t, class... argst> \
    inline arg1t& fname(arg1t& arg1, const arg2t& arg2, const argst&... args) { \
        return fname(fname(arg1, arg2), args...); \
    }

    EXTENDNM(prod)
    EXTENDM(mul)
    EXTENDNM(quot)
    EXTENDM(divi)
    EXTENDNM(sum)
    EXTENDM(add)
    EXTENDNM(dif)
    EXTENDM(sub)

    #undef EXTENDNM
    #undef EXTENDM

    void srevinit(int *rv) {
        for (int i = 1; i < LIN; ++i)
            rv[i] = rev(i);
    }

    int srev(int n) {
        static int *rv = (int*)calloc(LIN, sizeof *rv), init = (srevinit(rv), 1); (void)init;
        return rv[n];
    }

    void facinit(int *f) {
        for (int i = f[0] = 1; i < LIN; ++i)
            f[i] = prod(f[i - 1], i);
    }

    int fac(int n) {
        static int *f = (int*)calloc(LIN, sizeof *f), init = (facinit(f), 1); (void)init;
        if (__builtin_expect(n < 0, 0))
            return 0;
        return f[n];
    }

    void rfacinit(int *rf) {
        for (int i = rf[0] = 1; i < LIN; ++i)
            rf[i] = prod(rf[i - 1], srev(i));
    }

    int rfac(int n) {
        static int *rf = (int*)calloc(LIN, sizeof *rf), init = (rfacinit(rf), 1); (void)init;
        if (__builtin_expect(n < 0, 0))
            return 0;
        return rf[n];
    }

    inline int Cbig(int n, int k) {
        return prod(fac(n), rfac(n - k), rfac(k));
    }

    void Cfastinit(int *c) {
        c[0] = 1;
        for (int i = 1; i < SQ; ++i)
            for (int j = c[i * SQ] = 1; j <= i; ++j)
                c[i * SQ + j] = sum(c[i * SQ + j - SQ], c[i * SQ + j - SQ - 1]);
    }

    int Cfast(int n, int k) {
        static int *c = (int*)calloc(SQ * SQ, sizeof *c), init = (Cfastinit(c), 1); (void)init;
        if (__builtin_expect(n < 0 || k < 0 || k > n, 0))
            return 0;
        return c[n * SQ + k];
    }
}

int le[N];

int cnt(int l, int s) {
    return Cfast(l, s);
}

int cnt(const char *n, int l, int s) {
    if (s == 0 || l == 1)
        return s <= *n - '0';
    if (*n == '0')
        return cnt(n + 1, l - 1, s);
    return sum(cnt(n + 1, l - 1, s - 1), cnt(l - 1, s));
}

int main()
{
    for (int i = 2; i < N; ++i)
        le[i] = le[__builtin_popcount(i)] + 1;
    string n;
    int k, res = 0;
    cin >> n >> k;
    for (int i = 1; i < N; ++i)
        if (le[i] == k - 1)
            add(res, cnt(n.c_str(), n.size(), i));
    cout << res + !k - !(k - 1);
    return 0;
}