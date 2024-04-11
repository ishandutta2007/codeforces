#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second
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

const int maxn = 2e5 + 10, mod = 998244353;
typedef mint <mod> mi;
char a[maxn];
int n;
mi f[maxn][8][8];

int main() {
    scanf("%s", a + 1), n = strlen(a + 1);
    f[1][7][0] = 1;
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < 8; ++j)
            for (int k = 0; k < 8; ++k) if (f[i][j][k].x)
                for (int s = 0; s < 8; ++s) {
                    int nj = 0, nk = k, flg = 0;
                    #define in(x, y) (((x) >> (y)) & 1)
                    for (int p = 0; p < 3; ++p) {
                        if (in(j, p) && in(s, p) && a[i] == '0') flg = 1;
                        if (in(j, p) && in(s, p) == a[i] - '0') nj |= (1 << p);
                        if (s == (1 << p) || s == 7 - (1 << p)) nk |= (1 << p);
                    }
                    if (flg) continue;
                    f[i + 1][nj][nk] += f[i][j][k];
                }
    mi ans = 0;
    for (int i = 0; i < 8; ++i) ans += f[n + 1][i][7];
    printf("%d\n", ans.x);
	return 0;
}