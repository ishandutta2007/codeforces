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
map <pii, int> wxw;
priority_queue <pii> Q;
int dis[N], p[N], cnt[N];
int n, m, ans1, ans2, l;

int main() {
    read(n); read(m);
    for (int i = 1; i <= m; i++) {
        int u, v; 
        read(u); read(v);
        adj[v].push_back(u);
    }
    read(l);
    for (int i = 1; i <= l; i++) read(p[i]);
    memset(dis, 0x7f, sizeof(dis)); dis[p[l]] = 0; Q.push(make_pair(0, p[l]));
    while (!Q.empty()) {
        pii u = Q.top(); Q.pop();
        if (dis[u.second] > -u.first) continue;
        for (int i = 0; i < (int)adj[u.second].size(); i++) {
            int v = adj[u.second][i];
            if (dis[v] > dis[u.second] + 1) {
                dis[v] = dis[u.second] + 1;
                Q.push(make_pair(-dis[v], v));
            }
        }
    }
    for (int u = 1; u <= n; u++) {
        for (int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            if (dis[v] == dis[u] + 1) {
                ++cnt[v];
                wxw[make_pair(v, u)] = 1;
            }
        }
    }
    for (int i = 1; i < l; i++) {
        if (!wxw[make_pair(p[i], p[i + 1])]) ++ans1, ++ans2;
        else if(cnt[p[i]] >= 2) ++ans2;
    }
    print(ans1, ' '); print(ans2, '\n');
    return 0;
}