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

const int N = 55;

int n, f[N * N * 2], a[N][N];

int inline get(int o, int x, int y) {
    return o * n * n + (x - 1) * n + y;
}

int find(int x) {
    return x == f[x] ? x : f[x] = find(f[x]);
}

void inline merge(int x, int y) {
    f[find(x)] = find(y);
}

int inline ask(int x1, int y1, int x2, int y2) {
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int x; read(x);
    return x;
}

void inline Merge0(int x1, int y1, int x2, int y2) {
    merge(get(0, x1, y1), get(0, x2, y2));
    merge(get(1, x1, y1), get(1, x2, y2));
}

void inline Merge1(int x1, int y1, int x2, int y2) {
    merge(get(0, x1, y1), get(1, x2, y2));
    merge(get(1, x1, y1), get(0, x2, y2));
}

void inline work(int x1, int y1, int x2, int y2) {
    int t = ask(x1, y1, x2, y2);
    if (t) {
        Merge0(x1, y1, x2, y2);
    } else {
        Merge1(x1, y1, x2, y2);
    }
}

void inline solve() {
    for (int i = 3; i <= n; i += 2) {
        if (a[i - 2][i - 2] == 1 && a[i][i] == 0) {
            int x = i - 2, y = i - 2;
            int A = ask(x, y, i, i - 1);
            int B = ask(x + 1, y, i, i);
            if (A) {
                Merge0(x, y, i, i - 1);
            } else if (B) {
                Merge0(x + 1, y, i, i);
            } else {
                if (a[x + 1][y + 1] == 0 && a[x + 2][y] == 0 && find(get(1, x + 1, y)) == find(get(1, x + 2, y + 1))) Merge0(x, y, i, i - 1);
                else if (a[x + 1][y + 1] == 1 && a[x + 2][y] == 1 && find(get(1, x + 1, y)) == find(get(1, x + 2, y + 1))) Merge0(x + 1, y, i, i);
                else Merge1(x, y, i, i - 1);
            }
            return;
        }
    }
}
 

int main() {
    read(n);
    for (int i = 1; i <= n * n * 2; i++) f[i] = i;
    for (int i = 3; i <= n; i++) {
        work(i - 2, 1, i, 1);
        work(1, i - 2, 1, i);
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            work(i - 1, j - 1, i, j);
        }
    }
    work(1, 2, 3, 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == 0) {
                if (find(get(1, 1, 1)) == find(get(1, i, j)))
                    a[i][j] = 1;
                else a[i][j] = 0;
            }
        }
    }
    solve();
    puts("!");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int t;
            if (find(get(1, 1, 1)) == find(get(1, i, j))) t = 1;
            else t = 0;
            printf("%d", t);

        }
        puts("");
    }
}