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
    while (c < '0' || c > '9') { if (c == '-') fu = -1; c = getchar(); }
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

const int N = 5e5 + 5;

vector <int> adj[N];
int ansl[N], ansr[N], len[N];
int n, cnt;

void dfs1(int u, int fa, int r) {
    int now = 0, cnt = 0;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa) continue;
        ansl[v] = r - cnt; ansr[v] = ansr[u] + now + (int)adj[v].size();
        dfs1(v, u, ansr[v] - 1); now += (len[v] + 1); len[u] += (len[v] + 2);
        ++cnt;
    }
}

int main() {
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ansl[1] = 1; ansr[1] = (int)adj[1].size() + 2;
    dfs1(1, 0, (int)adj[1].size() + 1);
    for (int i = 1; i <= n; i++) print(ansl[i], ' '), print(ansr[i], '\n');
    return 0;
}