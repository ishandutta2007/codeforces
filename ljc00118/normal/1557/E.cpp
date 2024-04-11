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

const int N = 15;

char c[20];
int a[N][N], b[N][N];
int T, x, y;

void gen_map() {
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            int tx = x, ty = y;
            while (tx >= 1 && ty >= 1 && tx <= 8 && ty <= 8) {
                a[tx][ty] = 0;
                tx += dx; ty += dy;
            }
        }
    }
}

int main() {
    read(T);
    while (T--) {
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                a[i][j] = 1;
            }
        }
        int flag = 0;
        while (1) {
            int pos = 0;
            if (!flag) {
                x = 1; y = 4;
                flag = 1;
                goto qwq;
            }
            for (int i = 1; i <= 8; i++) {
                if (a[x + 1][i]) {
                    pos = i;
                    break;
                }
            }
            if (!pos) {
                ++x;
            } else {
                y = pos;
            }
            qwq:;
            print(x, ' '); print(y, '\n');
            fflush(stdout);
            for (int i = 1; i <= 10; i++) c[i] = 0;
            scanf("%s", c + 1);
            int dx, dy;
            if (c[1] == 'L') {
                dx = 0; dy = -1;
            }
            if (c[1] == 'R') {
                dx = 0; dy = 1;
            }
            if (c[1] == 'U') {
                dx = -1;
                if (c[4] == 'L') dy = -1;
                else if (c[4] == 'R') dy = 1;
                else dy = 0;
            }
            if (c[1] == 'D') {
                if (c[3] == 'n') break;
                dx = 1;
                if (c[6] == 'L') dy = -1;
                else if (c[6] == 'R') dy = 1;
                else dy = 0;
            }
            memset(b, 0, sizeof(b));
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    b[i + dx][j + dy] = a[i][j];
                }
            }
            memcpy(a, b, sizeof(a));
            gen_map();
        }
    }
    return 0;
}