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

const int N = 505;

int ans[N][N];
int n, m;

int main() {
    read(n);
    for (int i = 1; i <= n; i++) read(ans[i][i]);
    for (int i = 1; i <= n; i++) {
        int x = i, y = i;
        for (int j = 1; j < ans[i][i]; j++) {
            if (y > 1 && !ans[x][y - 1]) --y;
            else ++x;
            ans[x][y] = ans[i][i];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            print(ans[i][j], j == i ? '\n' : ' ');
        }
    }
    return 0;
}