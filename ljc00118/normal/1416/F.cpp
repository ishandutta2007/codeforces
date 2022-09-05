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

const int N = 1e5 + 5, INF = 0x7fffffff;
const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};
const char ch[4] = {'D', 'U', 'R', 'L'};

struct edge_t { int v, nxt, flow; } G[2333333];

struct atom {
    int x, y, v;
    atom (int a = 0, int b = 0, int c = 0) : x(a), y(b), v(c) {}
    bool operator < (const atom A) const { return v < A.v; }
} p[N];

int a[N], id[N], head[N], ans1[N]; char ans2[N];
int T, n, m, s, t, tot;

inline int c(int x, int y) { return (x - 1) * m + y; }

inline void addedge(int u, int v, int flow) {
    G[++tot] = (edge_t) {v, head[u], flow}, head[u] = tot;
    G[++tot] = (edge_t) {u, head[v], 0}, head[v] = tot;
}

queue <int> q;
int nowhead[N], d[N];
int bfs() {
    for (int i = s; i <= t; i++) d[i] = 0;
    d[s] = 1; q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int i = head[u]; i; i = G[i].nxt) {
            int v = G[i].v;
            if (G[i].flow && !d[v]) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
    return d[t];
}

int dfs(int u, int Flow) {
    if (u == t || !Flow) return Flow;
    int flow = 0, f;
    for (int &i = nowhead[u]; i; i = G[i].nxt) {
        int v = G[i].v;
        if (d[v] == d[u] + 1 && (f = dfs(v, min(Flow, G[i].flow))) > 0) {
            G[i].flow -= f; G[i ^ 1].flow += f;
            flow += f; Flow -= f;
            if (!Flow) break;
        }
    }
    return flow;
}

int dinic() {
    int ans = 0;
    while (bfs()) {
        for (int i = s; i <= t; i++) nowhead[i] = head[i];
        ans += dfs(s, INF);
    }
    return ans;
}

int main() {
    read(T);
    while (T--) {
        read(n); read(m);
        int len = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                read(a[c(i, j)]);
                p[++len] = atom(i, j, a[c(i, j)]);
            }
        }
        sort(p + 1, p + len + 1);
        for (int i = 1; i <= len; i++) id[c(p[i].x, p[i].y)] = i;
        int ok = 1;
        for (int l = 1, r; l <= len; l = r + 1) {
            r = l;
            while (r < len && p[l].v == p[r + 1].v) ++r;
            s = 0; t = r - l + 4; tot = 1;
            for (int i = s; i <= t; i++) head[i] = 0;
            int cnt[2] = {0, 0};
            for (int i = l; i <= r; i++) ++cnt[(p[i].x + p[i].y) & 1];
            int more = cnt[1] > cnt[0];
            addedge(t - 1, t, cnt[more] - cnt[more ^ 1]);
            for (int i = l; i <= r; i++) {
                int cando = 0;
                if ((p[i].x + p[i].y) % 2 == more) addedge(s, i - l + 1, 1);
                else addedge(i - l + 1, t, 1);
                for (int j = 0; j < 4; j++) {
                    int x = p[i].x + dx[j], y = p[i].y + dy[j];
                    if (x <= 0 || y <= 0 || x > n || y > m) continue;
                    if (a[c(x, y)] < p[i].v) cando = 1;
                    if (a[c(x, y)] == p[i].v) {
                        if ((p[i].x + p[i].y) % 2 == more) addedge(i - l + 1, id[c(x, y)] - l + 1, 1);
                        else addedge(id[c(x, y)] - l + 1, i - l + 1, 1);
                    }
                }
                if (cando) {
                    if ((p[i].x + p[i].y) % 2 == more) {
                        addedge(i - l + 1, t - 2, 1);
                        addedge(i - l + 1, t - 1, 1);
                    } else {
                        addedge(t - 2, i - l + 1, 1);
                    }
                }
            }
            if (dinic() != cnt[more]) {
                ok = 0;
                break;
            }
            for (int i = l; i <= r; i++) {
                if ((p[i].x + p[i].y) % 2 == more) {
                    int u = i - l + 1;
                    for (int j = head[u]; j; j = G[j].nxt) {
                        int v = G[j].v;
                        if (v >= 1 && v < t && !G[j].flow) {
                            if (v == t - 2 || v == t - 1) {
                                for (int k = 0; k < 4; k++) {
                                    int x = p[i].x + dx[k], y = p[i].y + dy[k];
                                    if (x <= 0 || y <= 0 || x > n || y > m) continue;
                                    if (a[c(x, y)] < p[i].v) {
                                        ans1[c(p[i].x, p[i].y)] = p[i].v - a[c(x, y)];
                                        ans2[c(p[i].x, p[i].y)] = ch[k];
                                        break;
                                    }
                                }
                            } else {
                                int x = p[v + l - 1].x, y = p[v + l - 1].y;
                                ans1[c(p[i].x, p[i].y)] = 1;
                                ans1[c(x, y)] = p[i].v - 1;
                                for (int k = 0; k < 4; k++) {
                                    if (p[i].x + dx[k] == x && p[i].y + dy[k] == y) {
                                        ans2[c(p[i].x, p[i].y)] = ch[k];
                                        ans2[c(x, y)] = ch[k ^ 1];
                                        break;
                                    }
                                }
                            }
                            break;
                        }
                    }
                }
            }
            for (int i = head[t - 2]; i; i = G[i].nxt) {
                int v = G[i].v;
                if ((p[v + l - 1].x + p[v + l - 1].y) % 2 != more && !G[i].flow) {
                    for (int j = 0; j < 4; j++) {
                        int x = p[v + l - 1].x + dx[j], y = p[v + l - 1].y + dy[j];
                        if (x <= 0 || y <= 0 || x > n || y > m) continue;
                        if (a[c(x, y)] < p[v + l - 1].v) {
                            ans1[c(p[v + l - 1].x, p[v + l - 1].y)] = p[v + l - 1].v - a[c(x, y)];
                            ans2[c(p[v + l - 1].x, p[v + l - 1].y)] = ch[j];
                            break;
                        }
                    }
                }
            }
        }
        if (ok) {
            printf("YES\n");
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    print(ans1[c(i, j)], j == m ? '\n' : ' ');
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    putchar(ans2[c(i, j)]);
                    if (j == m) putchar('\n');
                    else putchar(' ');
                }
            }
        } else {
            printf("NO\n");
        }
    }
    return 0;
}