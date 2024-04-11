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

const int N = 2e5 + 5;

int a[N], b[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) read(a[i]);
        for (int i = 1; i <= n; i++) read(b[i]);
        ll v0 = 1e9, v1 = 1e9, v2 = 1e9, v3 = 1e9;
        for (int i = 1; i <= n; i++) {
            v0 = min((int)v0, abs(a[1] - b[i]));
            v1 = min((int)v1, abs(a[n] - b[i]));
            v2 = min((int)v2, abs(b[1] - a[i]));
            v3 = min((int)v3, abs(b[n] - a[i]));
        }
        ll ans = v0 + v1 + v2 + v3;
        ans = min(ans, abs(a[1] - b[1]) + v1 + v3);
        ans = min(ans, abs(a[n] - b[n]) + v0 + v2);
        ans = min(ans, abs(a[1] - b[n]) + v1 + v2);
        ans = min(ans, abs(a[n] - b[1]) + v0 + v3);
        ans = min(ans, (ll)abs(a[1] - b[1]) + abs(a[n] - b[n]));
        ans = min(ans, (ll)abs(a[1] - b[n]) + abs(a[n] - b[1]));
        print(ans, '\n');
    }
    return 0;
}