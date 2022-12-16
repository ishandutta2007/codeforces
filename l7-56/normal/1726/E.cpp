#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef vector <int> vi;
typedef pair <int, int> pii;
#define fir first
#define sec second
template <typename __Tp> void read(__Tp &x) {
    int f = 0; x = 0; char ch = getchar();
    for (; !isdigit(ch); ch = getchar()) if (ch == '-') f = 1;
    for (; isdigit(ch); ch = getchar()) x = (x << 1) + (x << 3) + (ch ^ 48);
    if (f) x = -x;
}
template <typename __Tp1, typename ...__Tp2> void read(__Tp1 &x, __Tp2 &...y) { read(x), read(y...); }
template <typename __Tp> void write(__Tp x) {
    if (x < 0) putchar('-'), x = -x;
    if (x > 9) write(x / 10);
    putchar(x % 10 + 48);
}
void write(char ch) { putchar(ch); }
void write(const char *s) { for (int i = 0; s[i]; ++i) putchar(s[i]); }
template <typename __Tp1, typename ...__Tp2> void write(__Tp1 x, __Tp2 ...y) { write(x), write(y...); }
template <int mod>
class mint {
public:
    int x;
    mint() : x(0) {}
    mint(int x) : x((x % mod + mod) % mod) {}
    mint(long long x) : x((x % mod + mod) % mod) {}
    mint(unsigned int x) : x((x % mod + mod) % mod) {}
    mint(unsigned long long x) : x((x % mod + mod) % mod) {}
    friend mint operator + (mint a, mint b) { return (a.x += b.x) >= mod ? a.x -= mod : 0, a; }
    friend mint operator - (mint a, mint b) { return (a.x -= b.x) < 0 ? a.x += mod : 0, a; }
    friend mint operator * (mint a, mint b) { return (ll) a.x * b.x % mod; }
    template <typename __Tp>
    friend mint operator ^ (mint a, __Tp b) {
        mint ans = 1;
        while (b) {
            if (b & 1) ans *= a;
            a *= a, b >>= 1;
        }
        return ans;
    }
    friend mint operator / (mint a, mint b) { return a * (b ^ (mod - 2)); }

    friend mint & operator += (mint &a, mint b) { return a = a + b; }
    friend mint & operator -= (mint &a, mint b) { return a = a - b; }
    friend mint & operator *= (mint &a, mint b) { return a = a * b; }
    friend mint & operator /= (mint &a, mint b) { return a = a / b; }
    template <typename __Tp>
    friend mint & operator ^= (mint &a, __Tp b) { return a = a ^ b; }
};

const int maxn = 1e6 + 10, N = 1e6, mod = 998244353;
typedef mint <mod> mi;
mi f[maxn], fac[maxn], ifac[maxn], pw2[maxn], ffac[maxn];
void init() {
    f[0] = 1, f[1] = 1;
    for (int i = 2; i <= N; ++i) f[i] = f[i - 1] + (i - 1) * f[i - 2];
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= N; ++i) fac[i] = fac[i - 1] * i, ifac[i] = 1 / fac[i];
    ffac[0] = ffac[1] = 1;
    for (int i = 2; i <= N; ++i) ffac[i] = ffac[i - 2] * i;
    pw2[0] = 1;
    for (int i = 1; i <= N; ++i) pw2[i] = pw2[i - 1] * 2;
}

mi C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] * ifac[n - m];
}

void work() {
    int n; read(n);
    mi ans = f[n];
    for (int i = 1; i * 4 <= n; ++i)
        ans += f[n - 4 * i] * C(n - 2 * i, 2 * i) * pw2[i] * ffac[2 * i - 1];
    write(ans.x, '\n');
}

int main() {
    init();
    int T; read(T);
    while (T--) work();
	return 0;
}