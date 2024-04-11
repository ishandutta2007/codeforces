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

const int N = 505;

int ans[N][N];
int n, m;

int main() {
    read(n); read(m);
    if (n == 1 && m == 1) {
        print(0, '\n');
        return 0;
    }
    if (n == 1) {
        for (int i = 1; i <= m; i++) print(i + 1, i == m ? '\n' : ' ');
        return 0;
    }
    if (m == 1) {
        for (int i = 1; i <= n; i++) print(i + 1, '\n');
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            print((m + i) * j, j == m ? '\n' : ' ');
        }
    }
    return 0;
}