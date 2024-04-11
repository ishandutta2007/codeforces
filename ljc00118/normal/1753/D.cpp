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

const ll INF = 0x3f3f3f3f3f3f3f3f;
const int N = 3e5 + 5;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

priority_queue < pair <ll, int> > Q;
vector <pii> adj[N];
ll dis[N];
char a[N], c[N];
int n, m, p, q; ll ans = INF;

inline int s(int x, int y) { return (x - 1) * m + y; }
inline int getd(char c) {
    if (c == 'L') return 3;
    if (c == 'R') return 2;
    if (c == 'U') return 1;
    if (c == 'D') return 0;
    assert(0);
}

int main() {
    memset(dis, 0x3f, sizeof(dis));
    read(n); read(m); read(p); read(q);
    for (int i = 1; i <= n; i++) {
        scanf("%s", c + 1);
        for (int j = 1; j <= m; j++) a[s(i, j)] = c[j];
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[s(i, j)] == '#' || a[s(i, j)] == '.') continue;
            int nowd = getd(a[s(i, j)]), x = i + dx[nowd ^ 1], y = j + dy[nowd ^ 1];
            for (int d = 0; d < 4; d++) {
                if (d == nowd) continue;
                int _x = x + dx[d], _y = y + dy[d];
                if (_x >= 1 && _y >= 1 && _x <= n && _y <= m && a[s(_x, _y)] != '#') {
                    int cost = (d == (nowd ^ 1)) ? q : p;
                    adj[s(_x, _y)].emplace_back(s(i, j), cost);
                }
            }
        }
    }
    for (int i = 1; i <= n * m; i++) {
        if (a[i] == '.') {
            dis[i] = 0; Q.push(make_pair(0, i));
        }
    }
    while (!Q.empty()) {
        pair <ll, int> t = Q.top(); Q.pop();
        if (dis[t.second] != -t.first) continue;
        int u = t.second;
        for (auto v : adj[u]) {
            if (dis[v.first] > dis[u] + v.second) {
                dis[v.first] = dis[u] + v.second;
                Q.push(make_pair(-dis[v.first], v.first));
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[s(i, j)] == '#') continue;
            for (int d = 0; d < 4; d++) {
                int x = i + dx[d], y = j + dy[d];
                if (x >= 1 && y >= 1 && x <= n && y <= m && a[s(x, y)] != '#') {
                    ans = min(ans, dis[s(i, j)] + dis[s(x, y)]);
                }
            }
        }
    }
    if (ans == INF) print(-1, '\n');
    else print(ans, '\n');
    return 0;
}