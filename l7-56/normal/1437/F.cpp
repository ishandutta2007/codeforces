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

    friend bool operator != (mint a, mint b) { return a.x != b.x; }
    friend bool operator == (mint a, mint b) { return a.x == b.x; }
};

const int maxn = 5010, mod = 998244353;
typedef mint <mod> mi;
int n, a[maxn], b[maxn];
mi fac[maxn], ifac[maxn], f[maxn];
mi A(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[n - m];
}

int main() {
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= 5000; ++i) fac[i] = fac[i - 1] * i, ifac[i] = 1 / fac[i];
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    sort(a + 1, a + n + 1);
    if (a[n] < 2 * a[n - 1]) return write("0\n"), 0;
    for (int i = 1, j = 1; i <= n; ++i) {
        while (j <= n && a[i] >= 2 * a[j]) ++j;
        b[i] = j - 1;
    }
    f[0] = 1, b[0] = -1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j <= b[i]; ++j)
            f[i] += f[j] * A(n - b[j] - 2, b[i] - b[j] - 1);
    write(f[n].x, '\n');
	return 0;
}