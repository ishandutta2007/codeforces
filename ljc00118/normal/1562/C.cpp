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

const int N = 2e4 + 5;

char c[N];
int T, n;

int main() {
    read(T);
    while (T--) {
        read(n); scanf("%s", c + 1);
        int pos = 0;
        for (int i = 1; i <= n; i++) {
            if (c[i] == '0') pos = i;
        }
        if (!pos) {
            print(1, ' '); print(n - 1, ' '); print(2, ' '); print(n, '\n');
        } else {
            if (pos <= n / 2) print(pos + 1, ' '), print(n, ' '), print(pos, ' '), print(n, '\n');
            else print(1, ' '), print(pos, ' '), print(1, ' '), print(pos - 1, '\n');
        }
    }
    return 0;
}