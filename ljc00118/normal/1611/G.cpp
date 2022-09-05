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

int T, n, m, ans[2];

int main() {
    read(T);
    while (T--) {
        read(n); read(m); ans[0] = ans[1] = 0;
        vector < vector <int> > mx(n + 1, vector <int> (m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                char c = getchar();
                if (c != '0' && c != '1') c = getchar();
                mx[i][j] = c - '0';
            }
        }
        for (int j = 2; j <= m; j++) {
            for (int i = 1; i <= n; i++) {
                mx[i][j] += mx[i][j - 2];
                mx[i][j] = max(mx[i][j], mx[i - 1][j - 1]);
                if (i != n) mx[i][j] = max(mx[i][j], mx[i + 1][j - 1]);
            }
        }
        for (int i = 1; i <= n; i++) {
            ans[(i + m) & 1] = max(ans[(i + m) & 1], mx[i][m]);
            ans[(i + m - 1) & 1] = max(ans[(i + m - 1) & 1], mx[i][m - 1]);
        }
        print(ans[0] + ans[1], '\n');
    }
    return 0;
}