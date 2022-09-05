#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 1505;

pii s1[N][N][12], s2[N][N][12], tmp[12];
int L1[N][N], L2[N][N];
int a[N][N], used[N * N], ans[N], mx[N][N];
int n, lim;

void merge(pii *a, pii *b, pii *ans, int al, int bl, int &cl) {
    for (int i = 0; i < al; i++) used[a[i].first] = 0;
    for (int i = 0; i < bl; i++) used[b[i].first] = 0;
    int i = 0, j = 0; cl = 0;
    while ((i < al || j < bl) && cl <= lim) {
        if (i < al && (j == bl || a[i].second < b[j].second)) {
            if (!used[a[i].first]) {
                used[a[i].first] = 1;
                ans[cl] = a[i]; ++cl;
            }
            ++i;
        } else {
            if (!used[b[j].first]) {
                used[b[j].first] = 1;
                ans[cl] = b[j]; ++cl;
            }
            ++j;
        }
    }
}

bool check(int x, int y, int len) {
    int _x = x + len - 1, _y = y + len - 1, cnt = 0;
    if (_x > n || _y > n) return 0;
    for (int i = 0; i < L1[x][y]; i++) used[s1[x][y][i].first] = 0;
    for (int i = 0; i < L2[_x][_y]; i++) used[s2[_x][_y][i].first] = 0;
    for (int i = 0; i < L1[x][y]; i++) {
        if (s1[x][y][i].second - x - y >= len) break;
        if (!used[s1[x][y][i].first]) {
            used[s1[x][y][i].first] = 1;
            ++cnt;
        }
    }
    for (int i = 0; i < L2[_x][_y]; i++) {
        if (_x + _y + s2[_x][_y][i].second >= len) break;
        if (!used[s2[_x][_y][i].first]) {
            used[s2[_x][_y][i].first] = 1;
            ++cnt;
        }
    }
    // fprintf(stderr, "x = %d, y = %d, len = %d, cnt = %d\n", x, y, len, cnt);
    return cnt <= lim;
}

int main() {
    read(n); read(lim);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            read(a[i][j]);
        }
    }
    for (int sum = n * 2; sum >= 2; sum--) {
        int _l = max(1, sum - n), _r = min(n, sum - 1);
        for (int i = _l; i <= _r; i++) {
            int j = sum - i;
            s1[i][j][0] = make_pair(a[i][j], i + j); L1[i][j] = 1;
            int len;
            merge(s1[i][j], s1[i + 1][j], tmp, L1[i][j], L1[i + 1][j], len);
            merge(tmp, s1[i][j + 1], s1[i][j], len, L1[i][j + 1], L1[i][j]);
        }
    }
    for (int sum = 2; sum <= n * 2; sum++) {
        int _l = max(1, sum - n), _r = min(n, sum - 1);
        for (int i = _l; i <= _r; i++) {
            int j = sum - i;
            s2[i][j][0] = make_pair(a[i][j], -i - j); L2[i][j] = 1;
            int len;
            merge(s2[i][j], s2[i - 1][j], tmp, L2[i][j], L2[i - 1][j], len);
            merge(tmp, s2[i][j - 1], s2[i][j], len, L2[i][j - 1], L2[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            mx[i][j] = max(1, mx[i - 1][j] - 1);
            while (check(i, j, mx[i][j] + 1)) ++mx[i][j];
            ++ans[mx[i][j]];
        }
    }
    for (int i = n; i >= 1; i--) ans[i] += ans[i + 1];
    for (int i = 1; i <= n; i++) print(ans[i], '\n');
    return 0;
}