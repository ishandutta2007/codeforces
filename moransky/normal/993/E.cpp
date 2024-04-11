// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 8e5 + 5;

int n, x, a[N], F[N], G[N], t, R[N], L[N];
LL ret[N], a0;

const double PI = acos(-1.0);
struct CP{
    double x, y;
    CP operator + (const CP &b) const { return (CP) { x + b.x, y + b.y }; }
    CP operator - (const CP &b) const { return (CP) { x - b.x, y - b.y }; }
    CP operator * (const CP &b) const { return (CP) { x * b.x - y * b.y, x * b.y + y * b.x }; }
} f[N << 1], g[N << 1];
int lim = 1, len, rev[N << 1];

void FFT(CP a[], int opt) {
    for (int i = 0; i < lim; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int m = 1; m <= lim; m <<= 1) {
        CP wn = (CP) { cos(2.0 * PI / m), opt * sin(2.0 * PI / m) };
        for (int i = 0; i < lim; i += m) {
            CP w = (CP) { 1, 0 };
            for (int j = 0; j < (m >> 1); j++, w = w * wn) {
                CP u = a[i + j], t = w * a[i + j + (m >> 1)];
                a[i + j] = u + t, a[i + j + (m >> 1)] = u - t;
            }
        }
    }
}


void inline init(int n) {
    while (lim <= n) lim <<= 1, ++len;
    for (int i = 0; i < lim; i++) rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
}
 
int main() {
    read(n), read(x);
    for (int i = 1; i <= n; i++) {
        int t; read(t);
        a[i] = t < x ? 1 : 0;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            L[i] = L[i - 1] + 1;
            if (i == n || a[i + 1] == 1) a0 += L[i] + L[i] * (L[i] - 1ll) / 2;
        }
    }
    for (int i = n; i; i--) {
        if (a[i] == 0) R[i] = R[i + 1] + 1;
    }
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            F[++t] = L[i - 1] + 1;
            G[t] = R[i + 1] + 1;
        }
    }
    reverse(F, F + 1 + t);
    init(2 * t);
    for (int i = 0; i <= t; i++) f[i].x = F[i], g[i].x = G[i];
    FFT(f, 1); FFT(g, 1);
    for (int i = 0; i < lim; i++) f[i] = f[i] * g[i];
    FFT(f, -1);
    for (int i = 0; i < lim; i++) ret[i] = (LL)(f[i].x / lim + 0.5);   
    printf("%lld ", a0);
    for (int k = 0; k < n; k++) {
        printf("%lld ", ret[k + t]);
    }
    return 0;
}