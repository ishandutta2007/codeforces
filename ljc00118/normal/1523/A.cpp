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

const int N = 1005;

char c[N];
int a[N];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m); scanf("%s", c + 1);
        m = min(n, m);
        while (m--) {
            memset(a, 0, sizeof(a));
            for (int i = 1; i <= n; i++) {
                if ((c[i - 1] == '1') + (c[i] == '1') + (c[i + 1] == '1') == 1) a[i] = 1;
            }
            for (int i = 1; i <= n; i++) {
                if (a[i]) c[i] = '1';
            }
        }
        for (int i = 1; i <= n; i++) {
            putchar(c[i]);
        }
        putchar('\n');
    }
    return 0;
}