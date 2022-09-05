#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 1e6 + 5;

int up[N], down[N];
char c[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        scanf("%s", c + 1); n = strlen(c + 1);
        for (int i = 0; i <= n * 2; i++) up[i] = down[i] = 0;
        int sum = n;
        for (int i = 1; i <= n; i++) {
            if (c[i] == '1') {
                ++up[sum];
                ++sum;
            } else {
                ++down[sum];
                --sum;
            }
        }
        int now = n;
        for (int i = 1; i <= n; i++) {
            if (down[now] && (up[now - 1] || !up[now])) {
                putchar('0');
                --down[now];
                --now;
            } else {
                putchar('1');
                --up[now];
                ++now;
            }
        }
        putchar('\n');
    }
    return 0;
}