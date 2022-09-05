#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 1005;

char c[100005];
int a[N][N], ans[N][N], id[3], det[3];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        id[0] = 0; id[1] = 1; id[2] = 2;
        det[0] = det[1] = det[2] = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                read(a[i][j]);
                --a[i][j];
            }
        }
        scanf("%s", c + 1);
        for (int i = 1; i <= m; i++) {
            if (c[i] == 'R') {
                ++det[id[1]];
            }
            if (c[i] == 'L') {
                --det[id[1]];
            }
            if (c[i] == 'D') {
                ++det[id[0]];
            }
            if (c[i] == 'U') {
                --det[id[0]];
            }
            if (c[i] == 'I') {
                swap(id[1], id[2]);
            }
            if (c[i] == 'C') {
                swap(id[0], id[2]);
            }
        }
        det[0] = (det[0] % n + n) % n;
        det[1] = (det[1] % n + n) % n;
        det[2] = (det[2] % n + n) % n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int x = (id[0] == 0 ? (i + det[0]) % n : (id[0] == 1 ? (j + det[1]) % n : (a[i][j] + det[2]) % n));
                int y = (id[1] == 0 ? (i + det[0]) % n : (id[1] == 1 ? (j + det[1]) % n : (a[i][j] + det[2]) % n));
                int z = (id[2] == 0 ? (i + det[0]) % n : (id[2] == 1 ? (j + det[1]) % n : (a[i][j] + det[2]) % n));
                ans[x][y] = z;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%d%c", ans[i][j] + 1, j == n - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}