#pragma GCC optimize(2)
#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define Fast_cin ios::sync_with_stdio(false), cin.tie(0);
#define rep(i, a, b) for(register int i = a; i <= b; i++)
#define per(i, a, b) for(register int i = a; i >= b; i--)
using namespace std;

typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef long long ll;

template <typename _T>
inline void read(_T &f) {
    f = 0; _T fu = 1; char c = getchar();
    while(c < '0' || c > '9') { if(c == '-') fu = -1; c = getchar(); }
    while(c >= '0' && c <= '9') { f = (f << 3) + (f << 1) + (c & 15); c = getchar(); }
    f *= fu;
}

template <typename T>
void print(T x) {
    if(x < 0) putchar('-'), x = -x;
    if(x < 10) putchar(x + 48);
    else print(x / 10), putchar(x % 10 + 48);
}

template <typename T>
void print(T x, char t) {
    print(x); putchar(t);
}

const int N = 45;

ll f[N][N][N], ans;
char c[N];
int nxt[N];
int n, m;

int findNext(int x, int v) {
    if(x == m) x = nxt[x];
    while(x && c[x + 1] - '0' != v) x = nxt[x];
    if(c[x + 1] - '0' == v) ++x;
    return x;
}

int main() {
    read(n); scanf("%s", c + 1); m = strlen(c + 1);
    for(register int i = 2; i <= m; i++) {
        int k = nxt[i - 1];
        while(k && c[k + 1] != c[i]) k = nxt[k];
        if(c[k + 1] == c[i]) ++k;
        nxt[i] = k;
    }
    ans = 1ll << n;
    for(register int i = 0; i < m; i++) {
        memset(f, 0, sizeof(f));
        f[0][0][i] = 1;
        for(register int j = 0; j < n; j++) {
            for(register int k = 0; k < m; k++) {
                for(register int t = 0; t < m; t++) {
                    for(register int v = 0; v <= 1; v++) {
                        int x = findNext(k, v);
                        int y = findNext(t, v);
                        if(x == m || y == m) continue;
                        // cout << "debug : " << j << " " << k << " " << t << " " << x << " " << y << endl;
                        f[j + 1][x][y] += f[j][k][t];
                    }
                }
            }
        }
        for(register int j = 0; j < m; j++) ans -= f[n][i][j];
    }
    print(ans, '\n');
    return 0;
}