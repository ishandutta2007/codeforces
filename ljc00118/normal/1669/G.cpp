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

char ans[55][55], c[55][55];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) ans[i][j] = '.';
        }
        for (int j = 1; j <= m; j++) {
            int las = n;
            for (int i = n; i >= 1; i--) {
                if (c[i][j] == 'o') {
                    ans[i][j] = 'o';
                    las = i - 1;
                }
                if (c[i][j] == '*') {
                    ans[las][j] = '*';
                    --las;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) putchar(ans[i][j]);
            putchar('\n');
        }
    }
    return 0;
}