// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 2005;

int n, f[10][10][10][10][10], g[10][10][10][10][10];

int ans = 2e9;
 
int main() {
    read(n);
    memset(f, 0x3f, sizeof f);
    f[1][0][0][0][0] = 0;
    for (int i = 1; i <= n; i++) {
        int x, y; read(x), read(y);
        memcpy(g, f, sizeof f);
        memset(f, 0x3f, sizeof f);
        for (int p = 1; p <= 9; p++) {
            for (int a = 0; a <= 9; a++) {
                for (int b = 0; b <= 9; b++) {
                    for (int c = 0; c <= 9; c++) {
                        for (int d = 0; d <= 9; d++) {
                            if (a == 0) {
                                chkMin(f[x][y][b][c][d], g[p][a][b][c][d] + abs(p - x));
                            }
                            if (b == 0) {
                                chkMin(f[x][a][y][c][d], g[p][a][b][c][d] + abs(p - x));
                            }
                            if (c == 0) {
                                chkMin(f[x][a][b][y][d], g[p][a][b][c][d] + abs(p - x));
                            }
                            if (d == 0) {
                                chkMin(f[x][a][b][c][y], g[p][a][b][c][d] + abs(p - x));
                            }
                        }
                    }
                }
            }
        }
        
        for (int a = 9; ~a; a--) {
            for (int b = 9; ~b; b--) {
                for (int c = 9; ~c; c--) {
                    for (int d = 9; ~d; d--) {
                        for (int p = 1; p <= 9; p++) {
                            if (a) 
                                chkMin(f[a][0][b][c][d], f[p][a][b][c][d] + abs(p - a));
                            if (b)
                                chkMin(f[b][a][0][c][d], f[p][a][b][c][d] + abs(p - b));
                            if (c)
                                chkMin(f[c][a][b][0][d], f[p][a][b][c][d] + abs(p - c));
                            if (d)
                                chkMin(f[d][a][b][c][0], f[p][a][b][c][d] + abs(p - d));
                        }
                    }   
                }
            }
        }
        
    }
    for (int i = 1; i <= 9; i++)
        chkMin(ans, f[i][0][0][0][0]);
    printf("%d\n", ans + 2 * n);
    return 0;
}