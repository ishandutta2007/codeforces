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

char c[N];
int s[N];
int T, n, p, k, x, y, ans;

int main() {
    read(T);
    while (T--) {
        read(n); read(p); read(k); scanf("%s", c + 1);
        for (int i = n; i >= 1; i--) {
            s[i] = (c[i] == '0');
            if (i + k <= n) s[i] += s[i + k];
        }
        read(x); read(y);
        ans = 2e9;
        for (int i = p; i <= n; i++) ans = min(ans, s[i] * x + (i - p) * y);
        print(ans, '\n');
    }
    return 0;
}