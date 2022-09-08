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

const int N = 1e5 + 5;

vector <int> adj[N];
queue <int> q;
int vis[N];
int n, m, ans;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(register int i = 1; i <= n; i++) {
        if(!vis[i]) {
            int cnt = 1; vis[i] = 1; q.push(i);
            while(!q.empty()) {
                int u = q.front(); q.pop();
                for(register int j = 0; j < (int)adj[u].size(); j++) {
                    int v = adj[u][j];
                    if(!vis[v]) {
                        vis[v] = 1; ++cnt;
                        q.push(v);
                    }
                }
            }
            ans += cnt - 1;
        }
    }
    print(m - ans, '\n');
    return 0;
}