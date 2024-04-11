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

const int maxn = 1e6 + 10, mod = 998244353;
typedef mint <mod> mi;
int rk[maxn];
int calcrk(int n) {
	int lg = 0, N = 1; while (N <= n) ++lg, N <<= 1;
	for (int i = 0; i < N; ++i) rk[i] = (rk[i >> 1] >> 1) | ((i & 1) << (lg - 1));
	return N;
}
void NTT(mi *f, int n, int flg) {
	for (int i = 0; i < n; ++i) if (i < rk[i]) swap(f[i], f[rk[i]]);
	for (int len = 2; len <= n; len <<= 1) {
		mi w = mi(3) ^ ((mod - 1) / len); int hlf = len >> 1;
		for (int i = 0; i < n; i += len) {
			mi wk = 1;
			for (int k = i; k < i + hlf; ++k) {
				mi fk = f[k] + wk * f[k + hlf], fkk = f[k] - wk * f[k + hlf];
				f[k] = fk, f[k + hlf] = fkk, wk *= w;
			}
		}
	}
	if (flg == -1) {
		reverse(f + 1, f + n); mi invn = mi(1) / n;
		for (int i = 0; i < n; ++i) f[i] *= invn;
	}
}

int n, k, m;
mi f[maxn];

int main() {
    read(n, k, m);
    for (int i = 0; i <= k; ++i) f[i] = 1;
    int len = calcrk(k * 2 + 20);
    for (int _ = 1; _ < n; ++_) {
        NTT(f, len, 1);
        for (int i = 0; i < len; ++i) f[i] *= f[i];
        NTT(f, len, -1);
        mi suf = 0;
        for (int i = len - 1; i >= 0; --i) {
            suf += f[i];
            if (i > k) f[i] = 0;
            else f[i] = suf + f[i] * (k - i);
        }
    }
    NTT(f, len, 1);
    for (int i = 0; i < len; ++i) f[i] *= f[i];
    NTT(f, len, -1);
    write(f[m].x, '\n');
	return 0;
}