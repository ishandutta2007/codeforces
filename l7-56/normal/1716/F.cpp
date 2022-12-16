#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
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

const int maxk = 2010, K = 2000, mod = 998244353;
typedef mint <mod> mi;
int n, m, k;
mi fac[maxk], ifac[maxk], f[maxk][maxk];
void init() {
    fac[0] = 1, ifac[0] = 1;
    for (int i = 1; i <= K; ++i) fac[i] = fac[i - 1] * i, ifac[i] = 1 / fac[i];
    f[0][0] = 1;
    for (int i = 1; i <= K; ++i)
        for (int j = 1; j <= i; ++j)
            f[i][j] = f[i - 1][j] * j + f[i - 1][j - 1];
}

void work() {
    read(n, m, k);
    mi pwm2 = 1, pwm = mi(m) ^ n, invm = 1 / mi(m), dwn = 1, ans = 0;
    for (int j = 1; j <= k; ++j) {
        pwm2 *= (m + 1) / 2, dwn *= (n - j + 1), pwm *= invm;
        ans += f[k][j] * dwn * pwm * pwm2;
    }
    write(ans.x, '\n');
}

int main() {
    init();
    int T; read(T);
    while (T--) work();
	return 0;
}