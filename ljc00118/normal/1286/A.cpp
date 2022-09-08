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

const int N = 105, INF = 0x7f7f7f7f;

inline void upd(int &x, int y) { x = min(x, y); }

int f[N][N][2], a[N];
int n, cnt0, cnt1; 

int main() {
    memset(f, 0x7f, sizeof(f));
    read(n); cnt0 = n / 2; cnt1 = n - cnt0;
    for (int i = 1; i <= n; i++) {
        read(a[i]);
        if (a[i]) {
            if (a[i] & 1) --cnt1;
            else --cnt0;
        }
    }
    f[0][0][0] = f[0][0][1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= 1; k++) {
                if (f[i - 1][j][k] == INF) continue;
                for (int t = 0; t <= 1; t++) {
                    if (a[i] && (a[i] & 1) != t) continue;
                    upd(f[i][j + (!a[i] && t == 0)][t], f[i - 1][j][k] + (k != t));
                }
            }
        }
    }
    print(min(f[n][cnt0][0], f[n][cnt0][1]), '\n');
    return 0;
}