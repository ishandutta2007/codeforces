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

ll sum;
map <int, int> f[N];
int a[N], cnt[N];
int n, q;

void del(int u) {
    if (cnt[u] <= a[u]) ++sum;
    --cnt[u];
}

void add(int u) {
    ++cnt[u];
    if (cnt[u] <= a[u]) --sum;
}

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
    read(q);
    for (int i = 1; i <= q; i++) {
        int u, v, w;
        read(u); read(v); read(w);
        if (f[u][v] != 0) del(f[u][v]);
        f[u][v] = w;
        if (w != 0) add(w);
        print(sum, '\n');
    }
    return 0;
}