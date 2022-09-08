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

int a[20][20], b[20][2005], maxn[2005], pos[2005], tmp[20][20];
int T, n, m, k, ans;

bool cmp(int x, int y) { return maxn[x] > maxn[y]; }

void dfs(int u) {
    // fprintf(stderr, "u = %d, %d, %d\n", u, tmp[u - 1][1], tmp[u - 1][2]);
    if(u > k) {
        int sum = 0;
        for(register int i = 1; i <= n; i++) sum += tmp[u - 1][i];
        ans = max(ans, sum);
        return;
    }
    for(register int i = 0; i < n; i++) {
        for(register int j = 1; j <= n; j++) {
            int go = (i + j - 1) % n + 1;
            tmp[u][go] = max(tmp[u - 1][go], a[j][u]);
        }
        dfs(u + 1);
    }
}

int main() {
    read(T);
    while(T--) {
        read(n); read(m);
        for(register int i = 1; i <= m; i++) maxn[i] = 0, pos[i] = i;
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= m; j++) {
                read(b[i][j]);
                maxn[j] = max(maxn[j], b[i][j]);
            }
        }
        sort(pos + 1, pos + m + 1, cmp); k = min(n, m);
        for(register int i = 1; i <= n; i++) {
            for(register int j = 1; j <= k; j++) {
                a[i][j] = b[i][pos[j]];
            }
        }
        ans = 0; dfs(1); print(ans, '\n');
    }
    return 0;
}