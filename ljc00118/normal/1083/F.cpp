#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
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

const int N = 2e5 + 5, B = 500;

int a[N], b[N], s[N], st[N], ed[N], cnt[B][1 << 14], tag[B], w[N], l[N], r[N], bl[N];
int n, k, q, len, zeros;

void change(int L, int R, int x) {
    zeros -= ((w[R] ^ tag[bl[R]]) == 0);
    if (bl[L] == bl[R]) {
        for (int i = L; i <= R; i++) {
            --cnt[bl[L]][w[i]];
            w[i] ^= x;
            ++cnt[bl[L]][w[i]];
        }
    } else {
        for (int i = L; i <= r[bl[L]]; i++) {
            --cnt[bl[L]][w[i]];
            w[i] ^= x;
            ++cnt[bl[L]][w[i]];
        }
        for (int i = l[bl[R]]; i <= R; i++) {
            --cnt[bl[R]][w[i]];
            w[i] ^= x;
            ++cnt[bl[R]][w[i]];
        }
        for (int i = bl[L] + 1; i <= bl[R] - 1; i++) tag[i] ^= x;
    }
    zeros += ((w[R] ^ tag[bl[R]]) == 0);
}

int query() {
    if (zeros != k) return -1;
    int ans = 0;
    for (int i = 1; i <= bl[len]; i++) ans += cnt[i][tag[i]];
    return len - ans;
}

int main() {
    read(n); read(k); read(q);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]);
    for (int i = 1; i <= n; i++) s[i] = a[i] ^ b[i];
    for (int i = 0; i <= n; i++) s[i] ^= s[i + 1];
    for (int i = 0; i < k; i++) {
        int sum = 0;
        for (int j = i; j <= n; j += k) {
            sum ^= s[j];
            st[j] = ++len;
            w[len] = sum;
        }
        for (int j = i; j <= n; j += k) ed[j] = len;
        zeros += (sum == 0);
    }
    for (int i = 1; i <= len; i++) {
        bl[i] = (i - 1) / B + 1;
        if (!l[bl[i]]) l[bl[i]] = i;
        r[bl[i]] = i;
        ++cnt[bl[i]][w[i]];
    }
    print(query(), '\n');
    while (q--) {
        // if (q % 10000 == 0) fprintf(stderr, ">>> %d\n", q);
        char c = getchar();
        while (c != 'a' && c != 'b') c = getchar();
        int x, y, v; read(x); read(y);
        if (c == 'a') v = a[x] ^ y, a[x] = y;
        else v = b[x] ^ y, b[x] = y;
        change(st[x - 1], ed[x - 1], v);
        change(st[x], ed[x], v);
        print(query(), '\n');
    }
    return 0;
}