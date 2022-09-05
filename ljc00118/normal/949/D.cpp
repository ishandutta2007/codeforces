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

const int N = 1e5 + 5;

int a[N], cnt[3], v[4][N];
int n, d, b, ansl, ansr;

int main() {
    read(n); read(d); read(b);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) {
        int disl = (i - 1) / (d + 1) + 1;
        int disr = (n - i) / (d + 1) + 1;
        if (disl <= disr) v[0][disl] += a[i], v[2][disr] += a[i];
        else v[1][disr] += a[i], v[3][disl] += a[i];
    }
    for (int i = 1; i <= n / 2; i++) {
        cnt[0] += v[0][i];
        cnt[1] += v[1][i];
        int t = min(cnt[0], v[2][i]);
        cnt[0] -= t; cnt[2] += t;
        t = min(cnt[1], v[3][i]);
        cnt[1] -= t; cnt[2] += t;
        if (cnt[0] + cnt[2] >= b) {
            if (cnt[0] >= b) cnt[0] -= b;
            else cnt[2] -= (b - cnt[0]), cnt[0] = 0;
        } else ++ansl;
        if (cnt[1] + cnt[2] >= b) {
            if (cnt[1] >= b) cnt[1] -= b;
            else cnt[2] -= (b - cnt[1]), cnt[1] = 0;
        } else ++ansr;
    }
    print(max(ansl, ansr), '\n');
    return 0;
}