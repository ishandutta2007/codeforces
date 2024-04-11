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

const int N = 1e5 + 5, B = 300;

vector <int> seq[N];
int p[N], q[N], op[N], x[N], y[N], vis[N], vis2[N], cyc[N], go[N];
int n, m, len;

inline int getnxt(int x) {
    if (vis2[x]) return p[x];
    return go[x];
}

int main() {
    read(n); read(m);
    for (int i = 1; i <= n; i++) read(p[i]);
    for (int i = 1; i <= m; i++) {
        read(op[i]); read(x[i]); read(y[i]);
    }
    for (int l = 1, r; l <= m; l = r + 1) {
        memset(vis, 0, sizeof(vis));
        memset(vis2, 0, sizeof(vis2));
        memcpy(q, p, sizeof(q));
        r = min(m, l + B - 1);
        for (int i = 1; i <= n; i++) seq[i].clear(), seq[i].shrink_to_fit();
        for (int i = l; i <= r; i++) {
            if (op[i] == 1) {
                vis[x[i]] = vis[y[i]] = 1;
                vis2[x[i]] = vis2[y[i]] = 1;
                vis[q[x[i]]] = vis[q[y[i]]] = 1;
                swap(q[x[i]], q[y[i]]);
            }
            if (op[i] == 2) vis[x[i]] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (vis[i]) {
                int now = p[i];
                seq[i].push_back(i);
                while (!vis[now]) {
                    seq[i].push_back(now);
                    now = p[now];
                }
                go[i] = now;
            }
        }
        for (int i = l; i <= r; i++) {
            if (op[i] == 1) {
                swap(p[x[i]], p[y[i]]);
            }
            if (op[i] == 2) {
                cyc[len = 1] = x[i];
                int now = getnxt(x[i]), sum = seq[x[i]].size();
                while (now != x[i]) {
                    cyc[++len] = now;
                    sum += seq[now].size();
                    now = getnxt(now);
                }
                int k = y[i] % sum;
                for (int j = 1; j <= len; j++) {
                    if (k < (int)seq[cyc[j]].size()) {
                        print(seq[cyc[j]][k], '\n');
                        break;
                    }
                    k -= seq[cyc[j]].size();
                }
            }
        }
    }
    return 0;
}