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
 
const int N = 1005;
 
bitset <N> s[N], adj[N], tmp, po, leaf, cat;
int nxt[N], popc[N], used[N], deg[N], ans[N][N];
int n;
 
int main() {
    read(n);
    for (int i = 1; i <= n; i++) {
        int m; read(m);
        for (int j = 1, x; j <= m; j++) read(x), s[i][x] = 1;
        popc[i] = m;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            tmp = (s[i] & s[j]);
            int cnt = tmp.count();
            if (cnt == 2) {
                int x = tmp._Find_first(), y = tmp._Find_next(x);
                adj[x][y] = adj[y][x] = ans[x][y] = ans[y][x] = 1;
                continue;
            }
            if (cnt == popc[i] && cnt == popc[j] && !nxt[i]) nxt[i] = j;
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!adj[i].count()) continue;
        po[i] = 1;
        cnt += adj[i].count();
        adj[i][i] = 1;
        deg[i] = adj[i].count();
    }
    if (cnt == 0) {
        for (int i = 2; i <= n; i++) {
            print(1, ' '); print(i, '\n');
        }
        return 0;
    }
    if (cnt == 2) {
        int x = 0, y = 0;
        for (int i = 1; i <= n; i++) {
            if (deg[i]) {
                if (!x) x = i;
                else y = i;
            }
        }
        print(x, ' '); print(y, '\n');
        for (int i = 1; i <= n; i++) {
            if (popc[i] != n) {
                for (int j = 1; j <= n; j++) {
                    if (j == x || j == y) continue;
                    if (s[i][j]) print(x, ' '), print(j, '\n');
                    else print(y, ' '), print(j, '\n');
                }
                break;
            }
        }
        return 0;
    }
    for (int i = 1; i <= n; i++) {
        if (used[i]) continue;
        int now = nxt[i];
        while (now) used[now] = 1, now = nxt[now];
        tmp = po & s[i]; leaf = s[i] ^ tmp;
        int subt = 0;
        for (int j = 1; j <= n; j++) {
            if (adj[j] == tmp) {
                subt = j;
                break;
            }
        }
        if (!subt) continue;
        bool ok = 1;
        for (int j = 1; j <= n; j++) {
        	cat = s[j] & leaf;
        	unsigned nowpop = cat.count();
        	if (!nowpop) continue;
            if (nowpop != leaf.count() || (s[j] & tmp) != tmp) {
            	// fprintf(stderr, "error %d\n", j);
                ok = 0;
                break;
            }
        }
        if (!ok) continue;
        for (int j = 1; j <= n; j++) {
            if (leaf[j]) {
                ans[subt][j] = ans[j][subt] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (ans[i][j]) {
                print(i, ' '); print(j, '\n');
            }
        }
    }
    return 0;
}