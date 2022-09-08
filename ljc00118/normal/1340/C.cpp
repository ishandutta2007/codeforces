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
 
const int N = 10005;
 
vector <int> q[N][1005];
int d[N], f[N][1005];
int n, m, g, r, ans = 0x7fffffff;
 
int main() {
    memset(f, -1, sizeof(f));
    read(n); read(m);
    for (int i = 1; i <= m; i++) read(d[i]);
    sort(d + 1, d + m + 1);
    read(g); read(r);
    f[1][0] = 0; q[0][0].push_back(1);
    for (int dis = 0; dis < m - 1; dis++) {
        for (int now = 0; now < g; now++) {
            for (int i = 0; i < (int)q[dis][now].size(); i++) {
                int u = q[dis][now][i];
                // fprintf(stderr, "u = %d, now = %d, dis = %d\n", u, now, dis);
                if (u != 1 && d[u] - d[u - 1] + now <= g && f[u - 1][now + d[u] - d[u - 1]] == -1) {
                    f[u - 1][now + d[u] - d[u - 1]] = dis;
                    q[dis][now + d[u] - d[u - 1]].push_back(u - 1);
                }
                if (u != m && d[u + 1] - d[u] + now <= g && f[u + 1][now + d[u + 1] - d[u]] == -1) {
                    f[u + 1][now + d[u + 1] - d[u]] = dis;
                    q[dis][now + d[u + 1] - d[u]].push_back(u + 1);
                }
            }
        }
        for (int i = 0; i < (int)q[dis][g].size(); i++) {
            int u = q[dis][g][i];
            if (f[u][0] == -1) {
                f[u][0] = dis + 1;
                q[dis + 1][0].push_back(u);
            }
        }
    }
    for (int i = m; i >= 1; i--) {
        if (n - d[i] <= g && f[i][0] != -1) {
            ans = min(ans, n - d[i] + f[i][0] * (g + r));
        }
    }
    if (ans == 0x7fffffff) print(-1, '\n');
    else print(ans, '\n');
    return 0;
}