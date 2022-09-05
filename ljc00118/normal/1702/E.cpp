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

const int N = 2e5 + 5;

vector <int> adj[N];
queue <int> q;
int col[N];
int T, n, ans;

int main() {
    read(T);
    while (T--) {
        read(n);
        for (int i = 1; i <= n; i++) adj[i].clear(), col[i] = 0;
        for (int i = 1; i <= n; i++) {
            int u, v;
            read(u); read(v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ans = 1;
        for (int _ = 1; _ <= n; _++) {
            if (col[_]) continue;
            q.push(_); col[_] = 1;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (auto v : adj[u]) {
                    if (!col[v]) {
                        col[v] = 3 - col[u];
                        q.push(v);
                    } else if (col[u] == col[v]) ans = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if ((int)adj[i].size() > 2) {
                ans = 0;
                break;
            }
        }
        printf("%s\n", ans ? "YES" : "NO");
    }
    return 0;
}