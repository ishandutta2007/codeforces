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
 
const int N = 1e5 + 5;
 
priority_queue <pii> Q;
unordered_map <int, int> edg[N];
vector <int> adj[N];
int deg[N], used[N], tmp[N];
int T, n, m, k, tot, len;
 
int main() {
    read(T);
    while (T--) {
        read(n); read(m); read(k);
        for (int i = 1; i <= n; i++) adj[i].clear(), edg[i].clear(), deg[i] = used[i] = 0;
        for (int i = 1; i <= m; i++) {
            int u, v;
            read(u); read(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
            edg[u][v] = edg[v][u] = 1;
            ++deg[u]; ++deg[v];
        }
        while (!Q.empty()) Q.pop();
        for (int i = 1; i <= n; i++) Q.push(make_pair(-deg[i], i));
        int cando = 0;
        while (!Q.empty()) {
            pii t = Q.top(); Q.pop();
            if (-t.first != deg[t.second]) continue;
            if (-t.first >= k) {
                cando = 1;
                break;
            }
            int u = t.second;
            if (-t.first == k - 1) {
                tmp[len = 1] = u;
                for (int i = 0; i < (int)adj[u].size(); i++) {
                    int v = adj[u][i];
                    if (!used[v]) tmp[++len] = v;
                }
                int can = 1;
                for (int i = 1; i <= len; i++) {
                    for (int j = i + 1; j <= len; j++) {
                        if (!edg[tmp[i]].count(tmp[j])) {
                            can = 0;
                            break;
                        }
                    }
                    if (!can) break;
                }
                if (can) {
                    cando = 2;
                    print(2, '\n');
                    for (int i = 1; i <= k; i++) print(tmp[i], ' ');
                    putchar('\n');
                    break;
                }
            }
            for (int i = 0; i < (int)adj[u].size(); i++) {
                int v = adj[u][i];
                if (!used[v]) {
                    --deg[v];
                    Q.push(make_pair(-deg[v], v));
                }
            }
            used[u] = 1;
        }
        if (cando) {
            if (cando == 1) {
                int cnt = 0;
                for (int i = 1; i <= n; i++) {
                    if (!used[i]) {
                        ++cnt;
                    }
                }
                print(1, ' '); print(cnt, '\n');
                for (int i = 1; i <= n; i++) {
                    if (!used[i]) {
                        print(i, ' ');
                    }
                }
                putchar('\n');
            }
        } else {
            print(-1, '\n');
        }
    }
    return 0;
}