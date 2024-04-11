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

const int N = 2005;

char c[N][N];
int col[N][N], rev[N][N], res[N];
int n, tot;

int main() {
    read(n);
    if (n % 2 == 1) {
        puts("NONE");
        return 0;
    }
    for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
    for (int i = 1; i <= n; i += 2) {
        ++tot;
        int x = 1, y = i, now = 0;
        while (y > 1) {
            ++x; --y; now ^= 1;
            col[x][y] = tot; rev[x][y] = now;
        }
        ++x; col[x][y] = tot; rev[x][y] = now;
        while (x < n) {
            ++x; ++y; now ^= 1;
            col[x][y] = tot; rev[x][y] = now;
        }
        ++y; col[x][y] = tot; rev[x][y] = now;
        while (y < n) {
            --x; ++y; now ^= 1;
            col[x][y] = tot; rev[x][y] = now;
        }
        --x; col[x][y] = tot; rev[x][y] = now;
        while (x > 1) {
            --x; --y; now ^= 1;
            col[x][y] = tot; rev[x][y] = now;
        }
        --y; col[x][y] = tot; rev[x][y] = now;
    }
    for (int i = 1; i <= tot; i++) res[i] = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (c[i][j] != '.') {
                int val = (c[i][j] == 'G');
                if (res[col[i][j]] != -1 && res[col[i][j]] != (rev[i][j] ^ val)) {
                    puts("NONE");
                    return 0;
                }
                res[col[i][j]] = rev[i][j] ^ val;
            }
        }
    }
    for (int i = 1; i <= tot; i++) {
        if (res[i] == -1) {
            puts("MULTIPLE");
            return 0;
        }
    }
    puts("UNIQUE");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val = res[col[i][j]] ^ rev[i][j];
            if (val == 1) putchar('G');
            else putchar('S');
        }
        putchar('\n');
    }
    return 0;
}