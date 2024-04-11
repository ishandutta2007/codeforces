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

const int N = 5e5 + 5;

ll f[N];
int a[N], p[N], b[N], pos[N];
int n, m;

inline int lowbit(int x) { return x & -x; }

inline void add(int x, ll y) {
    ++x;
    while (x <= m + 1) {
        f[x] += y;
        x += lowbit(x);
    }
}

inline ll query(int x) {
    ++x;
    ll ans = 0;
    while (x) {
        ans += f[x];
        x ^= lowbit(x);
    }
    return ans;
}

inline void add(int l, int r, ll x) {
    add(l, x); add(r + 1, -x);
}

inline void setv(int x, ll y) {
    ll det = y - query(x);
    add(x, x, det);
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(p[i]);
    read(m);
    for (int i = 1; i <= m; i++) read(b[i]);
    b[m + 1] = 2e9;
    add(1, m, 1e17);
    for (int i = 1; i <= n; i++) {
        int pos = upper_bound(b + 1, b + m + 2, a[i]) - b - 1;
        // fprintf(stderr, "i = %d, pos = %d\n", i, pos);
        ll val;
        if (a[i] == b[pos]) val = query(pos - 1);
        if (p[i] <= 0) add(0, m, p[i]);
        else add(0, pos - (a[i] == b[pos]), p[i]);
        if (a[i] == b[pos]) {
            if (query(pos) > val) setv(pos, val);
        }
    }
    ll ans = query(m);
    if (ans < 1e15) printf("YES\n"), print(ans, '\n');
    else printf("NO\n");
    return 0;
}