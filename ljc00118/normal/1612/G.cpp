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

const int md = 1e9 + 7;

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

int fac[N];
int a[N], b[2][N], len[2], now[2];
int n, ans = 1, sum;

int s(int n) { return mul(mul(n, n + 1), (md + 1) / 2); }
int s(int l, int r) { return sub(s(r), s(sub(l, 1))); }

int main() {
    fac[0] = 1;
    for (int i = 1; i < N; i++) fac[i] = mul(fac[i - 1], i);
    read(n);
    ll all = 0;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        all += a[i];
        ++len[a[i] & 1];
        b[a[i] & 1][len[a[i] & 1]] = a[i];
    }
    sort(b[0] + 1, b[0] + len[0] + 1); reverse(b[0] + 1, b[0] + len[0] + 1);
    sort(b[1] + 1, b[1] + len[1] + 1); reverse(b[1] + 1, b[1] + len[1] + 1);
    now[0] = now[1] = 1;
    ll cnt = 0;
    for (int i = 1000000; i >= 0; i--) {
        int cur = (i & 1) ^ 1;
        while (now[cur] <= len[cur] && b[cur][now[cur]] > i) ++now[cur];
        if (i == 0) {
            ans = mul(ans, fac[now[cur] - 1]);
            continue;
        }
        sum = add(sum, mul((sub(s((all - cnt - now[cur] + 2) % md, (all - cnt) % md),  s((cnt + 1) % md, (cnt + now[cur] - 1) % md))), i));
        ans = mul(ans, fac[now[cur] - 1]); ans = mul(ans, fac[now[cur] - 1]);
        cnt += now[cur] - 1;
    }
    print(sum, ' '); print(ans, '\n');
    return 0;
}