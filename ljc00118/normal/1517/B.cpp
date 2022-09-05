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

const int N = 10005;

struct atom {
    int x, y, val;
    atom (int a = 0, int b = 0, int c = 0) : x(a), y(b), val(c) {}
    bool operator < (const atom A) const { return val < A.val; }
} a[N];

int ans[105][105], now[105];
int T, n, m;

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        int len = 0;
        for (int i = 1; i <= n; i++) {
            now[i] = 0;
            for (int j = 1; j <= m; j++) {
                ++len;
                ans[i][j] = 0;
                read(a[len].val);
                a[len].x = i; a[len].y = j;
            }
        }
        sort(a + 1, a + n * m + 1);
        for (int i = 1; i <= m; i++) ans[a[i].x][i] = a[i].val;
        for (int i = m + 1; i <= n * m; i++) {
            ++now[a[i].x];
            while (ans[a[i].x][now[a[i].x]]) ++now[a[i].x];
            ans[a[i].x][now[a[i].x]] = a[i].val;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) print(ans[i][j], j == m ? '\n' : ' ');
        }
    }
    return 0;
}