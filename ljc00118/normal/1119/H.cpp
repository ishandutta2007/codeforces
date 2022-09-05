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

const int N = 1e5 + 5;

int v1[1 << 17], v2[1 << 17], v3[1 << 17];
int a[N], b[N], c[N];
int n, k, x, y, z, all;

void fwt(int *a, int base) {
    int n = 1 << base;
    for (int mid = 1; mid < n; mid <<= 1) {
        for (int i = 0; i < n; i += (mid << 1)) {
            for (int j = 0; j < mid; j++) {
                int x = a[i + j], y = a[i + j + mid];
                a[i + j] = x + y; a[i + j + mid] = x - y;
            }
        }
    }
}

void ifwt(int *a, int base) {
    int n = 1 << base;
    for (int mid = 1; mid < n; mid <<= 1) {
        for (int i = 0; i < n; i += (mid << 1)) {
            for (int j = 0; j < mid; j++) {
                int x = a[i + j], y = a[i + j + mid];
                a[i + j] = add(x, y); a[i + j + mid] = sub(x, y);
            }
        }
    }
    int inv = fpow(n, md - 2);
    for (int i = 0; i < n; i++) a[i] = mul(a[i], inv);
}

int main() {
    read(n); read(k); read(x); read(y); read(z);
    x %= md; y %= md; z %= md;
    int lim = 1 << k;
    for (int i = 1; i <= n; i++) {
        read(a[i]); read(b[i]); read(c[i]);
        all ^= a[i]; b[i] ^= a[i]; c[i] ^= a[i];
        ++v1[b[i]]; ++v2[c[i]]; ++v3[b[i] ^ c[i]];
    }
    fwt(v1, k); fwt(v2, k); fwt(v3, k);
    for (int i = 0; i < lim; i++) {
        // fprintf(stderr, "i = %d, v1[i] = %d, v2[i] = %d, v3[i] = %d\n", i, v1[i], v2[i], v3[i]);
        int t1 = (n + v1[i]) / 2;
        int t2 = (n + v2[i]) / 2;
        int t3 = (n + v3[i]) / 2;
        int ans0 = (t1 + t2 + t3 - n) / 2;
        int ans1 = t1 - ans0;
        int ans2 = t2 - ans0;
        int ans3 = t3 - ans0;
        // fprintf(stderr, "i = %d, ans0 = %d, ans1 = %d, ans2 = %d, ans3 = %d\n", i, ans0, ans1, ans2, ans3);
        v1[i] = 1;
        v1[i] = mul(v1[i], fpow(add(x, add(y, z)), ans0));
        v1[i] = mul(v1[i], fpow(add(x, sub(y, z)), ans1));
        v1[i] = mul(v1[i], fpow(sub(x, sub(y, z)), ans2));
        v1[i] = mul(v1[i], fpow(sub(x, add(y, z)), ans3));
    }
    ifwt(v1, k);
    for (int i = 0; i < lim; i++) print(v1[i ^ all], i == lim - 1 ? '\n' : ' ');
    return 0;
}