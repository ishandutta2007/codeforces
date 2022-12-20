// LUOGU_RID: 90748471
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
ll n, a[maxn], cl[maxn], cr[maxn];
mi pw2[maxn], fac[maxn], ifac[maxn], f[maxn];
mi C(int n, int m) {
    if (n < 0 || m < 0 || n < m) return 0;
    return fac[n] * ifac[m] * ifac[n - m];
}

void work() {
    read(n);
    for (int i = 1; i <= n; ++i) read(a[i]);
    int m = 0, flg = 0;
    for (int i = 1; i <= n; ++i) if (a[i]) flg = 1;
    if (!flg) return write(pw2[n - 1].x, '\n');
    flg = 0;
    {
        int i = 1, j = n;
        while (i <= n && !a[i]) ++i, ++cl[0];
        while (j >= 1 && !a[j]) --j, ++cr[0];
        while (i <= j) {
            ll sl = 0, sr = 0, k = i, l = j;
            while (k <= l) {
                if (sl < sr) sl += a[k++];
                else sr += a[l--];
                if (sl == sr) break;
            }
            ++m;
            if (sl == sr) {
                while (k <= l && !a[k]) ++k, ++cl[m];
                while (k <= l && !a[l]) --l, ++cr[m];
                if (k > l) flg = 1;
            }
            i = k, j = l;
        }
    }
    // printf("@%d %d\n", m, flg);
    // for (int i = 0; i <= m; ++i) printf("%lld%c", cl[i], " \n"[i == m]);
    // for (int i = 0; i <= m; ++i) printf("%lld%c", cr[i], " \n"[i == m]);

    mi mul = 1, sum = 1;
    for (int i = 1; i <= min(cl[0], cr[0]); ++i)
        mul += C(cl[0], i) * C(cr[0], i);
    auto calc = [&] (int a, int b) -> mi {
        mi res = 0;
        for (int i = 0; i <= min(a, b); ++i)
            res += C(a + 1, i + 1) * C(b + 1, i + 1);
        return res;
    };
    for (int i = 1; i < m; ++i)
        f[i] = sum, sum += f[i] * calc(cl[i], cr[i]);
    f[m] = sum;
    // for (int i = 1; i <= m; ++i) write(f[i].x, " \n"[i == m]);
    mi ans = f[m];
    if (flg == 1) {
        ans += (cl[m] + 1) * f[m];
        for (int i = 1; i <= cl[m]; ++i)
            ans += C(cl[m] + 1, i - 1) * f[m];
    }
    ans *= mul;
    write(ans.x, '\n');
    for (int i = 0; i <= m; ++i) cl[i] = cr[i] = 0;
}

int main() {
    pw2[0] = fac[0] = 1;
    for (int i = 1; i <= N; ++i)
        pw2[i] = pw2[i - 1] * 2,
        fac[i] = fac[i - 1] * i;
    ifac[N] = 1 / fac[N];
    for (int i = N - 1; i >= 0; --i)
        ifac[i] = ifac[i + 1] * (i + 1);
    int T; read(T);
    while (T--) work();
	return 0;
}