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

const int N = 3e5 + 5;

set <pii> adj[N];
set < pair <ll, int> > all;
int f[N]; ll a[N];
int n, m, need;

int find(int x) { return f[x] == x ? x : f[x] = find(f[x]); }

int main() {
    read(n); read(m); read(need);
    ll sum = 0;
    for (int i = 1; i <= n; i++) read(a[i]), sum += a[i];
    if (sum < 1ll * (n - 1) * need) {
        printf("NO\n");
        return 0;
    }
    int blocks = n;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= m; i++) {
        int u, v;
        read(u); read(v);
        if (find(u) != find(v)) {
            --blocks;
            f[find(u)] = find(v);
            adj[u].insert(make_pair(v, i));
            adj[v].insert(make_pair(u, i));
        }
    }
    if (blocks != 1) {
        printf("NO\n");
        return 0;
    }
    for (int i = 1; i <= n; i++) all.insert(make_pair(a[i], i));
    printf("YES\n");
    for (int _ = 1; _ < n; _++) {
        pair <ll, int> x = *(--all.end());
        int u = x.second, v = (*adj[u].begin()).first;
        int ans = (*adj[u].begin()).second;
        print(ans, '\n');
        assert(a[u] + a[v] >= need);
        if (adj[u].size() > adj[v].size()) swap(u, v);
        all.erase(make_pair(a[u], u));
        all.erase(make_pair(a[v], v));
        adj[u].erase(make_pair(v, ans)); adj[v].erase(make_pair(u, ans));
        for (auto it : adj[u]) {
            adj[v].insert(it);
            auto it2 = adj[it.first].lower_bound(make_pair(u, 0));
            adj[it.first].insert(make_pair(v, it2 -> second));
            adj[it.first].erase(it2);
        }
        a[v] = a[u] + a[v] - need;
        all.insert(make_pair(a[v], v));
    }
    return 0;
}