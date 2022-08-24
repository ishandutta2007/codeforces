#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
void print(vector < int > v) {
    assert(v[0] == 1 && v.back() == n);
    cout << v.size() - 1 << '\n';
    for (int p : v) cout << p << " ";
    cout << '\n';
    exit(0);
}
void bad() {
    cout << -1 << '\n';
    exit(0);
}
map < pair < int, int >, bool > ed;
int m;
bool edge(int x, int y) {
    return ed.find(minmax(x, y)) != ed.end();
}
const int maxN = 3e5 + 100;
vector < int > g[maxN];
typedef unsigned long long ull;
ull hsh[maxN];
ull val[maxN];
mt19937 rnd(228);
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        ed[minmax(x, y)] = true;
    }
    for (int i = 1; i <= n; i++) {
        val[i] = rnd() | ((ull)rnd() << (32));
    }
    if (edge(1, n)) {
        print({1, n});
    }
    if (g[1].empty()) bad();
    for (int v : g[1]) {
        if (edge(v, n)) {
            print({1, v, n});
        }
    }
    for (int v : g[1]) {
        for (int u : g[v]) {
            if (u == 1) continue;
            if (edge(u, n)) {
                print({1, v, u, n});
            }
        }
    }
    for (int v : g[1]) {
        for (int u : g[v]) {
            if (u == 1) continue;
            if (!edge(1, u)) {
                print({1, v, u, 1, n});
            }
        }
    }
    for (int v : g[1]) {
        hsh[v] += val[v];
        for (int u : g[v]) {
            hsh[v] += val[u];
        }
    }
    for (int v : g[1]) {
        for (int u : g[v]) {
            if (u == 1) continue;
            if (hsh[u] == hsh[v]) continue;
            for (int t : g[u]) {
                if (t == 1) continue;
                if (t == v) continue;
                if (!edge(t, v)) {
                    print({1, v, u, t, v, n});
                }
            }
            for (int t : g[v]) {
                if (t == 1) continue;
                if (t == u) continue;
                if (!edge(t, u)) {
                    print({1, u, v, t, u, n});
                }
            }
        }
    }
    bad();
    return 0;
}