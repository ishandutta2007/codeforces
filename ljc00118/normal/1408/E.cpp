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

const int N = 2e5 + 5;

struct ele {
    int val, col, u;
    ele (int a = 0, int b = 0, int c = 0) : val(a), col(b), u(c) {}
} t[N];

bool operator < (const ele a, const ele b) {
    return a.val > b.val;
}

int a[N], b[N], id[N], f[N];
int n, m, len; ll ans;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(m); read(n);
    for (int i = 1; i <= m; i++) read(a[i]);
    for (int i = 1; i <= n; i++) read(b[i]), f[i] = i;
    for (int i = 1; i <= m; i++) {
        int k; read(k);
        for (int j = 1; j <= k; j++) {
            int u; read(u);
            t[++len] = ele(a[i] + b[u], i, u);
            ans += t[len].val;
        }
    }
    sort(t + 1, t + len + 1);
    for (int i = 1; i <= len; i++) {
        if (!id[t[i].col]) {
            id[t[i].col] = find(t[i].u);
            ans -= t[i].val;
        } else if (find(id[t[i].col]) != find(t[i].u)) {
            f[find(t[i].u)] = find(id[t[i].col]);
            ans -= t[i].val;
        }
    }
    print(ans, '\n');
    return 0;
}