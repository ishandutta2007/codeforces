#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int a[nax];
int ans[nax];
int deg[nax];
array <int, 3> q[nax];
vector <int> g[nax];


void solve(int k) {

    fill(a + 1, a + 1 + n, -1);
    fill(deg + 1, deg + 1 + n, 0);
    for (int i = 1 ; i <= n ; ++ i) g[i].clear();

    for (int x = 1 ; x <= m ; ++ x) {
        auto [i, j, val] = q[x];
        val = val >> k & 1;

        if (i == j) {
            a[i] = val;
        } else if (val == 0) {
            a[i] = a[j] = 0;
        }
    }

    static int c[nax];

    for (int x = 1 ; x <= m ; ++ x) {
        auto [i, j, val] = q[x];
        val = val >> k & 1;

        if (i == j) {

        } else if (val == 0) {

        } else {
            if (i < j) swap(i, j);
            g[i].push_back(j);
            g[j].push_back(i);
        }
    }
    for (int i = 1 ; i <= n ; ++ i) c[i] = a[i];

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] != -1) continue;
        bool ok = true;


        /// it will consider only edge which
        for (int v : g[i]) {
            if (v < i && a[v] != 1) {
                ok = false;
                a[i] = 1;
                break;
            }
            if (v > i && a[v] == 0) {
                ok = false;
                a[i] = 1;
                break;
            }
            /// it means that??


        }
        if (ok) a[i] = 0;
        assert(a[i] >= 0);
    }

    for (int i = 1 ; i <= n ; ++ i)
        ans[i] |= a[i] << k;

}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;

    for (int i = 1 ; i <= m ; ++ i) {
        for (int j = 0 ; j < 3 ; ++ j)
            cin >> q[i][j];
    }
    for (int k = 29 ; k >= 0 ; -- k) solve(k);

    for (int i = 1 ; i <= n ; ++ i) cout << ans[i] << ' ';
    cout << '\n';
}