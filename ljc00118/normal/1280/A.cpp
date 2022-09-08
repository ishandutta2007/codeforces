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

const int N = 1e6 + 5, md = 1e9 + 7;

char c[N];
int T, n, x, ok;

int main() {
    read(T);
    while (T--) {
        read(x); scanf("%s", c + 1); n = strlen(c + 1);
        ok = 1;
        for (int i = 1; i <= x; i++) {
            if (ok) {
                for (int j = n + 1; j <= min(n + 1ll * (n - i) * (c[i] - '0' - 1), (ll)x); j++) {
                    int id = (j - n - 1) % (n - i) + 1;
                    c[j] = c[i + id];
                }
            }
            if (ok) ok &= ((1ll * (n - i) * (c[i] - '0' - 1) + n) < md);
            n = (1ll * (n - i + md) * (c[i] - '0' - 1) + n) % md;
        }
        print(n, '\n');
    }
    return 0;
}