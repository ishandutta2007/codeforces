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
ll ans;
int a[N], b[N];
int n, m, q;

int main() {
    read(n); read(m);
    for(register int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        if(u > v) swap(u, v);
        ++a[u]; ++b[v];
        adj[u].push_back(v);
    }
    for(register int i = 1; i <= n; i++) ans += 1ll * a[i] * b[i];
    print(ans, '\n');
    read(q);
    while(q--) {
        int u; read(u);
        for(register int i = 0; i < (int)adj[u].size(); i++) {
            int v = adj[u][i];
            adj[v].push_back(u);
            ans -= 1ll * a[v] * b[v]; ++a[v]; --b[v]; ans += 1ll * a[v] * b[v];
        }
        ans -= 1ll * a[u] * b[u]; b[u] = a[u] + b[u]; a[u] = 0; adj[u].clear();
        print(ans, '\n');
    }
    return 0;
}