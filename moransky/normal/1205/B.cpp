#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
    if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5, M = 61, INF = 0x3f3f3f3f;

int n, ans = INF;

int d[M][M], w[M][M], cnt[M][M];

void inline check(int x, int y) {
    if (cnt[x][y] >= 2 && x == y) chkMin(ans, cnt[x][y] + 1);
    swap(x, y);
    if (cnt[x][y] >= 2 && x == y) chkMin(ans, cnt[x][y] + 1);
    if (x == y) return;
    if (d[y][x] + 1 <= 2) return;
    chkMin(ans, d[y][x] + 1);
    swap(x, y);
    if (d[y][x] + 1 <= 2) return;
    chkMin(ans, d[y][x] + 1);
}

void inline insert(int x, int y) {
    cnt[x][y]++;//, cnt[y][x]++;
    if (w[x][y]) return;
    if (x == y) return;
    w[x][y] = w[y][x] = 1;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            chkMin(d[i][j], d[i][x] + w[x][y] + d[y][j]);
            chkMin(d[i][j], d[i][y] + w[y][x] + d[x][j]);
        }
    }
}

int main() {
    memset(d, 0x3f, sizeof d);
    for (int i = 0; i < 60; i++) d[i][i] = 0;
    read(n);
    for (int i = 1; i <= n; i++) {
        LL x;
        read(x);
        for (int j = 0; j < 60; j++) {
            if (x >> j & 1) {
                for (int k = 0; k <= j; k++) {
                    if (x >> k & 1) {
                        check(j, k);
                    }
                }
            }
        }
        for (int j = 0; j < 60; j++) {
            if (x >> j & 1) {
                for (int k = 0; k <= j; k++) {
                    if (x >> k & 1) {
                        insert(j, k);
                    }
                }
            }
        }
    }
    printf("%d\n", ans == INF ? -1 : ans);
}