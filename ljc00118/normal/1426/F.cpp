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

const int N = 2e5 + 5, md = 1e9 + 7;

inline int add(int x, int y) {
    x += y;
    if (x >= md) x -= md;
    return x;
}

inline int sub(int x, int y) {
    x -= y;
    if (x < 0) x += md;
    return x;
}

inline int mul(int x, int y) { return 1ll * x * y % md; }

inline int fpow(int x, int y) {
    if (y < 0) return 0;
    int ans = 1;
    while (y) {
        if (y & 1) ans = mul(ans, x);
        y >>= 1; x = mul(x, x);
    }
    return ans;
}

char c[N];
int n, a, cc, cnt, all, ans;

int main() {
    read(n); scanf("%s", c + 1);
    for (int i = 1; i <= n; i++) cc += (c[i] == 'c'), all += (c[i] == '?');
    for (int i = 1; i <= n; i++) {
        if (c[i] == 'b' || c[i] == '?') {
            int la = a, rc = cc;
            int lcnt = cnt;
            int rcnt = all - cnt - (c[i] == '?');
            // fprintf(stderr, "la = %d, rc = %d, lcnt = %d, rcnt = %d\n", la, rc, lcnt, rcnt);
            ans = add(ans, mul(fpow(3, all - (c[i] == '?')), mul(la, rc)));
            ans = add(ans, mul(fpow(3, all - 1 - (c[i] == '?')), mul(lcnt, rc)));
            ans = add(ans, mul(fpow(3, all - 1 - (c[i] == '?')), mul(la, rcnt)));
            ans = add(ans, mul(fpow(3, all - 2 - (c[i] == '?')), mul(lcnt, rcnt)));
        }
        a += (c[i] == 'a'); cnt += (c[i] == '?'); cc -= (c[i] == 'c');
    }
    print(ans, '\n');
    return 0;
}