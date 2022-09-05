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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

int T, a, b, c, m;

int main() {
    read(T);
    while (T--) {
        read(a); read(b); read(c); read(m);
        int maxn = max(max(a, b), c);
        int l, r;
        if (maxn <= (a + b + c + 1) / 2) l = 0, r = a + b + c - 3;
        else l = a + b + c - (a + b + c - maxn) * 2 - 1, r = a + b + c - 3;
        if (l <= m && m <= r) puts("YES");
        else puts("NO");
    }
    return 0;
}