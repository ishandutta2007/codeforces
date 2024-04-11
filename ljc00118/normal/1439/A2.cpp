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

const int N = 105;

char c[N][N];
int a[N][N], ans[N * N][6];
int T, n, m, len;

void push(int a, int b, int c, int d, int e, int f) {
    ++len;
    ::a[a][b] ^= 1; ::a[c][d] ^= 1; ::a[e][f] ^= 1;
    ans[len][0] = a;
    ans[len][1] = b;
    ans[len][2] = c;
    ans[len][3] = d;
    ans[len][4] = e;
    ans[len][5] = f;
}

int main() {
    read(T);
    while (T--) {
        len = 0;
        read(n); read(m);
        for (int i = 1; i <= n; i++) {
            scanf("%s", c[i] + 1);
            for (int j = 1; j <= m; j++) {
                a[i][j] = c[i][j] - '0';
            }
        }
        for (int i = 1; i <= n - 2; i++) {
            for (int j = 1; j <= m; j++) {
                if (i >= n - 1 && j >= m - 1) continue;
                if (a[i][j]) {
                    if (i < n - 1) {
                        if (j == 1) push(i, j, i + 1, j, i + 1, j + 1);
                        else push(i, j, i + 1, j - 1, i + 1, j);
                    }
                }
            }
        }
        for (int j = 1; j <= m - 2; j++) {
            for (int i = n - 1; i <= n; i++) {
                if (a[i][j]) {
                    if (i == n - 1) push(i, j, i, j + 1, i + 1, j + 1);
                    else push(i, j, i, j + 1, i - 1, j + 1);
                }
            }
        }
        for (int s = 0; s < 16; s++) {
            int cando = 1, cnt = 0;
            for (int i = n - 1; i <= n; i++) {
                for (int j = m - 1; j <= m; j++) {
                    if ((s >> cnt) & 1) {
                        a[i][j] ^= 1;
                        a[n - 1][m] ^= 1; a[n - 1][m - 1] ^= 1;
                        a[n][m] ^= 1; a[n][m - 1] ^= 1;
                    }
                    ++cnt;
                }
            }
            for (int i = n - 1; i <= n; i++) {
                for (int j = m - 1; j <= m; j++) {
                    if (a[i][j]) cando = 0;
                }
            }
            if (cando) {
                cnt = 0;
                for (int i = n - 1; i <= n; i++) {
                    for (int j = m - 1; j <= m; j++) {
                        if ((s >> cnt) & 1) {
                            a[i][j] ^= 1;
                            int now = 0;
                            ++len;
                            for (int x = n - 1; x <= n; x++) {
                                for (int y = m - 1; y <= m; y++) {
                                    if (x == i && y == j) continue;
                                    ans[len][now] = x;
                                    ans[len][now + 1] = y;
                                    now += 2;
                                }
                            }
                        }
                        ++cnt;
                    }
                }
                break;
            }
            cnt = 0;
            for (int i = n - 1; i <= n; i++) {
                for (int j = m - 1; j <= m; j++) {
                    if ((s >> cnt) & 1) {
                        a[i][j] ^= 1;
                        a[n - 1][m] ^= 1; a[n - 1][m - 1] ^= 1;
                        a[n][m] ^= 1; a[n][m - 1] ^= 1;
                    }
                    ++cnt;
                }
            }
        }
        print(len, '\n');
        for (int i = 1; i <= len; i++) {
            for (int j = 0; j <= 5; j++) print(ans[i][j], j == 5 ? '\n' : ' ');
        }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) {
        //         a[i][j] = c[i][j] - '0';
        //     }
        // }
        // for (int i = 1; i <= len; i++) {
        //     for (int j = 0; j <= 5; j += 2) {
        //         a[ans[i][j]][ans[i][j + 1]] ^= 1;
        //     }
        // }
        // for (int i = 1; i <= n; i++) {
        //     for (int j = 1; j <= m; j++) print(a[i][j]);
        //     putchar('\n');
        // }
    }
    return 0;
}