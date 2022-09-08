#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
int m;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
int myRand() {
    return rng() % 2;
}

const int maxN = 2e5 + 10;
int u[maxN], v[maxN];
int p[maxN], sz[maxN];
int get(int x) {
    if (x == p[x]) return p[x];
    return p[x] = get(p[x]);
}

bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    sz[x] += sz[y];
    p[y] = x;
    return true;
}
int f[maxN];
void solve() {
    cin >> n;
    cin >> m;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    int ans = 2 * n - m;
    while (true) {

        for (int i = 1; i <= m; i++) {
            f[i] = myRand();
        }
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            if (!f[i] && !unite(u[i], v[i])) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        for (int i = 1; i <= n; i++) {
            p[i] = i;
            sz[i] = 1;
        }
        for (int i = 1; i <= m; i++) {
            if (f[i] && !unite(u[i], v[i])) {
                ok = false;
                break;
            }
        }
        if (!ok) continue;
        for (int i = 1; i <= m; i++) cout << f[i];
        cout << '\n';
        return;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();

    }
    return 0;
}