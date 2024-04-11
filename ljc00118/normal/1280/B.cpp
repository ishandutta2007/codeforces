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

const int N = 65;

char c[N][N];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        bool ok0 = 1, noA = 1;
        for (int i = 1; i <= n; i++) {
            scanf("%s", c[i] + 1);
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == 'P') {
                    ok0 = 0;
                }
                if (c[i][j] == 'A') {
                    noA = 0;
                }
            }
        }
        if (ok0) {
            print(0, '\n');
            continue;
        }
        if (noA) {
            printf("MORTAL\n");
            continue;
        }
        bool ok1 = 0, ok = 1;
        for (int i = 1; i <= m; i++) {
            if (c[1][i] == 'P') {
                ok = 0;
                break;
            }
        }
        ok1 |= ok;
        ok = 1;
        for (int i = 1; i <= m; i++) {
            if (c[n][i] == 'P') {
                ok = 0;
                break;
            }
        }
        ok1 |= ok;
        ok = 1;
        for (int i = 1; i <= n; i++) {
            if (c[i][1] == 'P') {
                ok = 0;
                break;
            }
        }
        ok1 |= ok;
        ok = 1;
        for (int i = 1; i <= n; i++) {
            if (c[i][m] == 'P') {
                ok = 0;
                break;
            }
        }
        ok1 |= ok;
        if (ok1) {
            print(1, '\n');
            continue;
        }
        bool ok2 = 0;
        for (int i = 1; i <= n; i++) {
            bool ok = 1;
            for (int j = 1; j <= m; j++) {
                if (c[i][j] == 'P') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ok2 = 1;
                break;
            }
        }
        for (int j = 1; j <= m; j++) {
            bool ok = 1;
            for (int i = 1; i <= n; i++) {
                if (c[i][j] == 'P') {
                    ok = 0;
                    break;
                }
            }
            if (ok) {
                ok2 = 1;
                break;
            }
        }
        if (c[1][1] == 'A' || c[1][m] == 'A' || c[n][1] == 'A' || c[n][m] == 'A') ok2 = 1;
        if (ok2) {
            print(2, '\n');
            continue;
        }
        bool ok3 = 0;
        for (int i = 1; i <= m; i++) {
            if (c[1][i] == 'A' || c[n][i] == 'A') {
                ok3 = 1;
                break;
            }
        }
        for (int i = 1; i <= n; i++) {
            if (c[i][1] == 'A' || c[i][m] == 'A') {
                ok3 = 1;
                break;
            }
        }
        if (ok3) {
            print(3, '\n');
        } else {
            print(4, '\n');
        }
    }
    return 0;
}