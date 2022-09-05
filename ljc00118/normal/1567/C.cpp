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

int a[20];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n);
        int len = 0;
        while (n) {
            a[++len] = n % 10;
            n /= 10;
        }
        int x = 0, y = 0;
        for (int i = len, j = 0; i >= 1; i--, j ^= 1) {
            if (j) x = x * 10 + a[i];
            else y = y * 10 + a[i];
        }
        print((x + 1) * (y + 1) - 2, '\n');
    }
    return 0;
}