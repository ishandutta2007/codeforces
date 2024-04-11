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

const int N = 2005;

int f[N][N], pre[N][N];
int st[10][8], now[N][8];
char c[N];
int n, k;

int main() {
    memset(f, -1, sizeof(f));
    st[0][1] = st[0][2] = st[0][3] = st[0][5] = st[0][6] = st[0][7] = 1;
    st[1][3] = st[1][6] = 1;
    st[2][1] = st[2][3] = st[2][4] = st[2][5] = st[2][7] = 1;
    st[3][1] = st[3][3] = st[3][4] = st[3][6] = st[3][7] = 1;
    st[4][2] = st[4][3] = st[4][4] = st[4][6] = 1;
    st[5][1] = st[5][2] = st[5][4] = st[5][6] = st[5][7] = 1;
    st[6][1] = st[6][2] = st[6][4] = st[6][5] = st[6][6] = st[6][7] = 1;
    st[7][1] = st[7][3] = st[7][6] = 1;
    st[8][1] = st[8][2] = st[8][3] = st[8][4] = st[8][5] = st[8][6] = st[8][7] = 1;
    st[9][1] = st[9][2] = st[9][3] = st[9][4] = st[9][6] = st[9][7] = 1;
    read(n); read(k);
    for (int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        for (int j = 1; j <= 7; j++) now[i][j] = c[j] - '0';
    }
    f[n + 1][0] = 0;
    for (int i = n + 1; i >= 2; i--) {
        for (int j = 0; j <= k; j++) {
            if (f[i][j] == -1) continue;
            for (int t = 0; t <= 9; t++) {
                bool ok = 1; int cnt = 0;
                for (int _ = 1; _ <= 7; _++) {
                    if (!st[t][_] && now[i - 1][_]) { ok = 0; break; }
                    cnt += (st[t][_] - now[i - 1][_]);
                }
                if (!ok) continue;
                if (j + cnt <= k && t > f[i - 1][j + cnt]) f[i - 1][j + cnt] = t, pre[i - 1][j + cnt] = j;
            }
        }
    }
    if (f[1][k] == -1) {
        print(-1, '\n');
        return 0;
    }
    int now = k;
    for (int i = 1; i <= n; i++) {
        print(f[i][now]);
        now = pre[i][now];
    }
    putchar('\n');
    return 0;
}