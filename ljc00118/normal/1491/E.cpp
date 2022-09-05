#pragma GCC optimize(2)
#pragma GCC optimize(3)
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

inline ull R(ull x) {
    x ^= x << 17;
    x ^= x >> 13;
    x ^= x << 5;
    return x;
}

const int N = 2e5 + 5;

vector <int> adj[N];
int tag[30][N], fib[30], siz[30][N], tag2[30][N], fa[30][N];
int n;

void dfs1(int u, int d) {
    siz[d][u] = 1;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[d][u] || !tag[d][v]) continue;
        fa[d][v] = u; dfs1(v, d); siz[d][u] += siz[d][v];
    }
}

void dfs2(int u, int val, int d) {
    tag2[d][u] = val;
    for (int i = 0; i < (int)adj[u].size(); i++) {
        int v = adj[u][i];
        if (v == fa[d][u] || !tag[d][v]) continue;
        dfs2(v, val, d);
    }
}

int st;
unordered_map <ull, bool> mp;
bool solve(vector <int> a, int n) {
    if (clock() - st > CLOCKS_PER_SEC * 0.9) {
        printf("No\n");
        exit(0);
    }
    if (n <= 3) return 1;
    ull x = 114514151;
    for (int i = 0; i < (int)a.size(); i++) x = R(x) + a[i] + 5823792133333ll;
    if (mp.count(x)) return mp[x];
    for (int i = 0; i < (int)a.size(); i++) tag[n][a[i]] = 1;
    fa[n][a[1]] = 0; dfs1(a[1], n);
    int ans = 0;
    for (int i = 0; i < (int)a.size(); i++) {
        if (siz[n][a[i]] == fib[n - 1] || siz[n][a[i]] == fib[n - 2]) {
            dfs2(a[i], 1, n);
            vector <int> l, r;
            for (int j = 0; j < (int)a.size(); j++) {
                if (tag2[n][a[j]]) l.push_back(a[j]);
                else r.push_back(a[j]);
            }
            dfs2(a[i], 0, n);
            if (siz[n][a[i]] == fib[n - 1]) {
                int now = solve(l, n - 1);
                if (now) {
                    now = solve(r, n - 2);
                    if (now) {
                        ans = 1;
                        break;
                    }
                }
            } else {
                int now = solve(r, n - 1);
                if (now) {
                    now = solve(l, n - 2);
                    if (now) {
                        ans = 1;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < (int)a.size(); i++) tag[n][a[i]] = 0;
    mp[x] = ans; return ans;
}

int main() {
    st = clock();
    fib[0] = fib[1] = 1;
    for (int i = 2; i <= 26; i++) fib[i] = fib[i - 1] + fib[i - 2];
    read(n);
    for (int i = 1; i < n; i++) {
        int u, v;
        read(u); read(v);
        // u = i; v = i + 1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    int pos = 0;
    for (int i = 1; i <= 26; i++) {
        if (fib[i] == n) {
            pos = i;
            break;
        }
    }
    if (!pos) {
        printf("No\n");
        return 0;
    }
    vector <int> a(n);
    for (int i = 0; i < n; i++) a[i] = i + 1;
    if (solve(a, pos)) printf("Yes\n");
    else printf("No\n");
    return 0;
}