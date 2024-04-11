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

const int base = 9;

vector <pii> now;
ll ans[512][512], a[512][512], tmp[512][512];
int n, m, k;

int main() {
    read(k); n = 1 << k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            read(ans[i][j]);
        }
    }
    read(m);
    for (int i = 1; i <= m; i++) {
        int x, y;
        read(x); read(y); --x; --y;
        now.emplace_back(x, y);
    }
    for (int i = 0; i < k; i++) {
        memset(tmp, 0, sizeof(tmp));
        for (auto j : now) {
            for (int x = 0; x < n; x++) {
                for (int y = 0; y < n; y++) {
                    tmp[(x + j.first) & (n - 1)][(y + j.second) & (n - 1)] ^= ans[x][y];
                }
            }
        }
        memcpy(ans, tmp, sizeof(ans));
        memset(a, 0, sizeof(a));
        for (auto j : now) a[(j.first * 2) & (n - 1)][(j.second * 2) & (n - 1)] ^= 1;
        now.clear();
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                if (a[x][y]) now.emplace_back(x, y);
            }
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (ans[i][j]) ++cnt;
        }
    }
    print(cnt, '\n');
    return 0;
}