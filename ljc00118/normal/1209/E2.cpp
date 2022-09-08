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

int f[20][1 << 12], sum[20][1 << 12], pre[1 << 12], v[20][1 << 12];
int a[20][20], b[20][2005], maxn[2005], pos[2005];
int T, n, m, k, ans;

bool cmp(int x, int y) { return maxn[x] > maxn[y]; }

inline int lowbit(int x) { return x & -x; }

int main() {
    read(T);
    for(register int i = 1; i <= 12; i++) pre[1 << (i - 1)] = i;
    while(T--) {
        read(n); read(m);
        // n = 12; m = 12;
        for(register int i = 1; i <= m; i++) maxn[i] = 0, pos[i] = i;
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= m; j++) {
                read(b[i][j]);
                // b[i][j] = rand();
                maxn[j] = max(maxn[j], b[i][j]);
            }
        }
        sort(pos + 1, pos + m + 1, cmp); k = min(n, m);
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= k; j++) {
                a[i][j] = b[i][pos[j]];
            }
        }
        memset(f, 0, sizeof(f)); memset(v, 0, sizeof(v));
        for(register int i = 1; i <= k; i++) {
            for(register int z = 1; z <= n; z++) {
                int w = a[1][i];
                for(register int j = 1; j < n; j++) a[j][i] = a[j + 1][i];
                a[n][i] = w;
                for(register int j = 1; j < (1 << n); j++) {
                    sum[i][j] = sum[i][j ^ lowbit(j)] + a[pre[lowbit(j)]][i];
                    v[i][j] = max(v[i][j], sum[i][j]);
                }
            }
        }
        for(register int i = 1; i <= k; i++) {
            for(register int j = 0; j < (1 << n); j++) {
                for(register int t = j; 1; t = (j & (t - 1))) {
                    f[i][j] = max(f[i][j], f[i - 1][t] + v[i][j ^ t]);
                    if(t == 0) break;
                }
            }
        }
        print(f[k][(1 << n) - 1], '\n');
    }
    return 0;
}