#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename T>
inline void read(T &f) {
    f = 0; T fu = 1; char c = getchar();
    while (c < '0' || c > '9') { if (c == '-') { fu = -1; } c = getchar(); }
    while (c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if (x < 0) putchar('-'), x = -x;
    if (x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int md = 998244353;

inline int add(int x, int y) {
    if (x + y >= md) return x + y - md;
    return x + y;
}

inline void addx(int &x, int y) {
    x += y;
    if (x >= md) x -= md;
}

inline int sub(int x, int y) {
    if (x < y) return x - y + md;
    return x - y;
}

inline void subx(int &x, int y) {
    x -= y;
    if (x < 0) x += md;
}

inline int mul(int x, int y) { return 1ull * x * y % md; }

inline int fpow(int x, int y) {
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

const int N = 1e6 + 5;

vector <int> vec;
int a[N], cnt[N], phi[N], pri[N], isp[N], fac[N], inv[N];
int T, n, len, all;

inline int C(int n, int m) {
    if (n < m || m < 0) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}

int main() {
    phi[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (!isp[i]) {
            pri[++len] = i;
            phi[i] = i - 1;
        }
        for (int j = 1; j <= len && i * pri[j] <= 1000000; j++) {
            isp[i * pri[j]] = 1;
            if (i % pri[j] == 0) {
                phi[i * pri[j]] = phi[i] * pri[j];
                break;
            }
            phi[i * pri[j]] = phi[i] * (pri[j] - 1);
        }
    }
    fac[0] = 1;
    for (int i = 1; i <= 1000000; i++) fac[i] = mul(fac[i - 1], i);
    inv[1000000] = fpow(fac[1000000], md - 2);
    for (int i = 1000000; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) cnt[i] = 0;
        for (int i = 1; i <= n; i++) read(a[i]), ++cnt[a[i]];
        all = n;
        vec.clear();
        for (int i = 1; i <= n; i++) {
            all = __gcd(all, cnt[i]);
            if (cnt[i]) vec.push_back(cnt[i]);
        }
        int ans1 = 0, ans2 = 0;
        for (int i = 1; i <= all; i++) {
            if (all % i == 0) {
                //  i 
                int sum1 = 0, sum2 = 1;
                for (auto j : vec) sum2 = mul(sum2, inv[j / i]);
                for (auto j : vec) {
                    int m = n / i, c = j / i;
                    if (m == c) {
                        sum1 = add(sum1, 1);
                    } else {
                        sum1 = add(sum1, mul(m, mul(C(m - 2, c - 1), mul(mul(sum2, fac[c]), fac[m - c]))));
                    }
                }
                if (vec.size() != 1) sum1 = mul(sum1, i);
                sum2 = mul(sum2, fac[n / i]);
                ans1 = add(ans1, mul(sum1, phi[i]));
                ans2 = add(ans2, mul(sum2, phi[i]));
                // fprintf(stderr, "sum1 = %d, sum2 = %d, i = %d\n", sum1, sum2, i);
            }
        }
        print(mul(ans1, fpow(ans2, md - 2)), '\n');
    }
    return 0;
}