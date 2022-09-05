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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 5005;

char c[N];
int lcp[N][N], f[N];
int T, n;

int getlcp(int i, int j) {
    int len = 0;
    while (max(i, j) + len <= n && c[i + len] == c[j + len]) ++len;
    return len;
}

int main() {
    read(T);
    while (T--) {
        int ans = 0;
        read(n); scanf("%s", c + 1);
        for (int i = n; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                if (c[i] == c[j]) lcp[i][j] = lcp[i + 1][j + 1] + 1;
            }
        }
        for (int i = 1; i <= n; i++) f[i] = 0;
        for (int i = 1; i <= n; i++) {
            f[i] += n - i + 1;
            for (int j = i + 1; j <= n; j++) {
                if (lcp[i][j] < n - j + 1 && c[i + lcp[i][j]] < c[j + lcp[i][j]]) f[j] = max(f[j], f[i] - lcp[i][j]);
            }
            ans = max(ans, f[i]);
        }
        print(ans, '\n');
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                lcp[i][j] = 0;
            }
        }
    }
    return 0;
}