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

const int N = 205;

char c[N][N];
int f[N][N], pre[N][N];
int T, n;

void gen_dp(int num) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == 1 && j == 1) continue;
            f[i][j] = 23333;
            if (i != 1) f[i][j] = f[i - 1][j], pre[i][j] = 1;
            if (j != 1 && f[i][j - 1] < f[i][j]) f[i][j] = f[i][j - 1], pre[i][j] = 2;
            f[i][j] += (c[i][j] - '0' != num);
        }
    }
}

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) scanf("%s", c[i] + 1);
        // gen_dp(0);
        // int val = f[n][n], opt = 0;
        // gen_dp(1);
        // if (f[n][n] < val) opt = 1;
        // if (val != 1) {
        //     print(0, '\n');
        //     continue;
        // }
        // gen_dp(opt);
        // int x = n, y = n;
        // vector <pii> path;
        // while (1) {
        //     if (pre[x][y] == 1) --x;
        //     else --y;
        //     if (x == 1 && y == 1) break;
        //     path.push_back(make_pair(x, y));
        // }
        // int ans = 0;
        // for (int i = 0; i < (int)path.size(); i++) {
        //     c[path[i].first][path[i].second] ^= 1;
        //     int cando = 1;
        //     gen_dp(0); cando &= (f[n][n] > 1);
        //     gen_dp(1); cando &= (f[n][n] > 1);
        //     if (cando) {
        //         ans = 1;
        //         printf("1\n%d %d\n", path[i].first, path[i].second);
        //         break;
        //     }
        //     c[path[i].first][path[i].second] ^= 1;
        // }
        // if (ans) continue;
        rep(i, 0, 1) rep(j, 0, 1) rep(x, 0, 1) rep(y, 0, 1) {
            if (i + j + x + y > 2) continue;
            if (i) c[1][2] ^= 1;
            if (j) c[2][1] ^= 1;
            if (x) c[n - 1][n] ^= 1;
            if (y) c[n][n - 1] ^= 1;
            int cando = 1;
            gen_dp(0); cando &= (f[n][n] > 1);
            gen_dp(1); cando &= (f[n][n] > 1);
            if (cando) {
                printf("%d\n", i + j + x + y);
                if (i) printf("%d %d\n", 1, 2);
                if (j) printf("%d %d\n", 2, 1);
                if (x) printf("%d %d\n", n - 1, n);
                if (y) printf("%d %d\n", n, n - 1);
                goto qwq;
            }
            if (i) c[1][2] ^= 1;
            if (j) c[2][1] ^= 1;
            if (x) c[n - 1][n] ^= 1;
            if (y) c[n][n - 1] ^= 1;
        }
        qwq:;
    }
    return 0;
}