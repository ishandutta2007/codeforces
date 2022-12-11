// =================================
//   author: memset0
//   date: 2019.01.26 09:45:46
//   website: https://memset0.cn/
// =================================
#include <bits/stdc++.h>
#define ll long long
namespace ringo {
template <class T> inline void read(T &x) {
	x = 0; register char c = getchar(); register bool f = 0;
	while (!isdigit(c)) f ^= c == '-', c = getchar();
	while (isdigit(c)) x = x * 10 + c - '0', c = getchar();
	if (f) x = -x;
}
template <class T> inline void print(T x) {
	if (x < 0) putchar('-'), x = -x;
	if (x > 9) print(x / 10);
	putchar('0' + x % 10);
}
template <class T> inline void print(T x, char c) { print(x), putchar(c); }

const int N = 1010, M = 10, mov[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, p, a[M], ans[M], x[M], y[M];
bool flag, map[N][N], vis[N][N];
std::vector <std::pair <int, int> > q[M], q_t[M];

struct info { int x, y, w; } u, v;
std::queue <info> now;

void main() {
    read(n), read(m), read(p);
    for (int i = 1; i <= p; i++) read(a[i]);
    for (int i = 1, c; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            while (c = getchar(), c != '.' && c != '#' && !isdigit(c));
            if (isdigit(c)) vis[i][j] = 1, q[c - '0'].push_back(std::make_pair(i, j)), ++ans[c - '0'];
            else map[i][j] = c == '#' ? 1 : 0;
        }
    flag = 1;
    while (flag) {
        flag = 0;
        for (int i = 1; i <= p; i++) {
            std::swap(q[i], q_t[i]), q[i].clear();
            for (auto it : q_t[i]) now.push({it.first, it.second, a[i]});
            while (now.size()) {
                u = now.front(), now.pop();
                if (u.w == 0) {
                    q[i].push_back(std::make_pair(u.x, u.y));
                    continue;
                }
                for (int t = 0; t < 4; t++) {
                    v.x = u.x + mov[t][0], v.y = u.y + mov[t][1], v.w = u.w - 1;
                    if (v.x < 1 || v.y < 1 || v.x > n || v.y > m) continue;
                    // printf("[%d] %d %d -> %d %d : %d %d\n", i, u.x, u.y, v.x, v.y, map[v.x][v.y], vis[v.x][v.y]);
                    if (map[v.x][v.y] || vis[v.x][v.y]) continue;
                    vis[v.x][v.y] = 1, ++ans[i], flag = 1;
                    now.push(v);
                }
            }
        }
    }
    for (int i = 1; i <= p; i++) print(ans[i], " \n"[i == p]);
}

} signed main() { return ringo::main(), 0; }