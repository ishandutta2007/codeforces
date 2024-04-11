#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

const int N = 200005, md = 998244353;

struct ele {
    int x; ll y;
    ele (int a = 0, ll b = 0) : x(a), y(b) {}
};

bool operator < (const ele a, const ele b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
    // if (a.x >= 60 || b.x >= 60) return a.x < b.x;
    // return ((1ll << a.x) + a.y) < ((1ll << b.x) + b.y);
}

ele operator + (const ele a, const ele b) {
    return ele(a.x + b.x, a.y + b.y);
}

inline ele getrev(ele x) { return ele(-x.x, -x.y); }

struct atom {
    int x, y, z;
    atom (int a = 0, int b = 0, int c = 0) : x(a), y(b), z(c) {}
};

bool operator < (const atom a, const atom b) {
    return 0;
}

priority_queue < pair <ele, pii> > Q;
priority_queue < pair <ll, atom> > q;
vector <int> adj[2][N];
ele dis[N][2];
ll d[N][21][2];
int n, m;

bool check(const ele a, const ele b) {
    if (a.x == b.x) return a.y < b.y;
    if (a.x >= 60 || b.x >= 60) return a.x < b.x;
    return ((1ll << a.x) + a.y) < ((1ll << b.x) + b.y);
}

ele getmin(ele a, ele b) {
    if (check(a, b)) return a;
    return b;
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) dis[i][0].x = dis[i][1].x = 2333333;
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[0][u].push_back(v);
        adj[1][v].push_back(u);
    }
    dis[1][0] = ele(0, 0); Q.push(make_pair(dis[1][0], make_pair(1, 0)));
    while (!Q.empty()) {
        pair <ele, pii> t = Q.top(); Q.pop();
        t.first = getrev(t.first);
        int u = t.second.first, o = t.second.second;
        if (dis[u][o] < t.first) continue;
        if (t.first + ele(1, 0) < dis[u][o ^ 1]) {
            dis[u][o ^ 1] = t.first + ele(1, 0);
            Q.push(make_pair(getrev(dis[u][o ^ 1]), make_pair(u, o ^ 1)));
        }
        for (int i = 0; i < (int)adj[o][u].size(); i++) {
            int v = adj[o][u][i];
            if (t.first + ele(0, 1) < dis[v][o]) {
                dis[v][o] = t.first + ele(0, 1);
                Q.push(make_pair(getrev(dis[v][o]), make_pair(v, o)));
            }
        }
    }
    memset(d, 0x7f, sizeof(d));
    d[1][0][0] = 0; q.push(make_pair(0, atom(1, 0, 0)));
    while (!q.empty()) {
        pair <ll, atom> t = q.top(); q.pop();
        int u = t.second.x, x = t.second.y, o = t.second.z;
        if (-t.first > d[u][x][o]) continue;
        if (x + 1 <= 20 && d[u][x + 1][o ^ 1] > d[u][x][o]) {
            d[u][x + 1][o ^ 1] = d[u][x][o];
            q.push(make_pair(-d[u][x][o], atom(u, x + 1, o ^ 1)));
        }
        for (int i = 0; i < (int)adj[o][u].size(); i++) {
            int v = adj[o][u][i];
            if (d[u][x][o] + 1 < d[v][x][o]) {
                d[v][x][o] = d[u][x][o] + 1;
                q.push(make_pair(-d[v][x][o], atom(v, x, o)));
            }
        }
        // cout << d[n][0][0] << endl;
    }
    ele res = min(dis[n][0], dis[n][1]);
    for (int i = 0; i <= 20; i++) {
        ll minn = min(d[n][i][0], d[n][i][1]);
        if (minn != 0x7f7f7f7f7f7f7f7f) res = getmin(res, ele(i, minn));
    }
    int ans = 1;
    for (int i = 1; i <= res.x; i++) {
        ans <<= 1;
        if (ans >= md) ans -= md;
    }
    ans = (ans + res.y) % md;
    print((ans + md - 1) % md, '\n');
    return 0;
}