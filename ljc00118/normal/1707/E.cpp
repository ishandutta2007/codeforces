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

const int N = 1e5 + 5;

int a[N], mx[34][17][N], mn[34][17][N], nxt[34][N], lg[N];
int n, q;

int qmx(int id, int l, int r) {
    int k = lg[r - l + 1];
    return max(mx[id][k][l], mx[id][k][r - (1 << k) + 1]);
}

int qmn(int id, int l, int r) {
    int k = lg[r - l + 1];
    return min(mn[id][k][l], mn[id][k][r - (1 << k) + 1]);
}

void build(int id) {
    for (int j = 1; j <= 16; j++) {
        for (int i = 1; i <= n - (1 << j); i++) {
            mx[id][j][i] = max(mx[id][j - 1][i], mx[id][j - 1][i + (1 << (j - 1))]);
            mn[id][j][i] = min(mn[id][j - 1][i], mn[id][j - 1][i + (1 << (j - 1))]);
        }
    }
}

int main() {
    read(n); read(q);
    for (int i = 1; i <= n; i++) read(a[i]), nxt[0][i] = a[i];
    for (int i = 1; i < n; i++) {
        mx[0][0][i] = max(a[i], a[i + 1]);
        mn[0][0][i] = min(a[i], a[i + 1]);
    }
    build(0);
    lg[0] = -1;
    for (int i = 1; i < n; i++) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i <= 33; i++) {
        for (int j = 1; j <= n; j++) nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
        for (int j = 1; j < n; j++) {
            int l = mn[i - 1][0][j], r = mx[i - 1][0][j];
            if (l == r) mn[i][0][j] = mx[i][0][j] = nxt[i - 1][l];
            else {
                mn[i][0][j] = qmn(i - 1, l, r - 1);
                mx[i][0][j] = qmx(i - 1, l, r - 1);
            }
        }
        build(i);
    }
    while (q--) {
        int l, r;
        read(l); read(r);
        if (l == 1 && r == n) {
            print(0, '\n');
            continue;
        }
        ll ans = 0;
        for (int i = 33; i >= 0; i--) {
            if (l == r) {
                ans = 1e18;
                break;
            }
            int _l = qmn(i, l, r - 1), _r = qmx(i, l, r - 1);
            if (_l != 1 || _r != n) {
                ans += (1ll << i);
                l = _l; r = _r;
            }
        }
        ++ans;
        if (ans > 1ll * n * n) ans = -1;
        print(ans, '\n');
    }
    return 0;
}