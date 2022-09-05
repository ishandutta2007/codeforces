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

const int N = 1e5 + 5;

int w[N], deg[N], tmp[N];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) deg[i] = 0;
        ll sum = 0;
        for (int i = 1; i <= n; i++) read(w[i]), sum += w[i];
        for (int i = 1; i < n; i++) {
            int u, v;
            read(u); read(v);
            ++deg[u]; ++deg[v];
        }
        m = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < deg[i]; j++) tmp[++m] = w[i];
        }
        sort(tmp + 1, tmp + m + 1);
        print(sum);
        for (int i = m; i >= 1; i--) {
            sum += tmp[i];
            putchar(' '); print(sum);
        }
        putchar('\n');
    }
    return 0;
}