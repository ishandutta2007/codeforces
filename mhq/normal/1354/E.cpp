#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
int n1, n2, n3;
const int maxN = 5005;
bool used[maxN];
int clr[maxN];
vector < int > g[maxN];
vector < pair < int, int > > all;
int c[2];
vector < int > by[maxN][2];
void dfs(int v) {
    used[v] = true;
    c[clr[v]]++;
    by[all.size()][clr[v]].emplace_back(v);
    for (int to : g[v]) {
        if (!used[to]) {
            clr[to] = clr[v] ^ 1;
            dfs(to);
        }
        else {
            if (clr[to] != (clr[v] ^ 1)) {
                cout << "NO\n";
                exit(0);
            }
        }
    }
}
typedef bitset < maxN > bs;
bs val[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    cin >> n1 >> n2 >> n3;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            c[0] = c[1] = 0;
            dfs(i);
            all.emplace_back(c[0], c[1]);
        }
    }
    val[0][0] = true;
    for (int i = 0; i < all.size(); i++) {
        val[i + 1] |= (val[i] << all[i].first);
        val[i + 1] |= (val[i] << all[i].second);
    }
    if (!val[all.size()][n2]) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i = (int)all.size(); i > 0; i--) {
        int take = -1;
        if (n2 >= all[i - 1].first && val[i - 1][n2 - all[i - 1].first]) {
            take = 0;
            n2 -= all[i - 1].first;
        }
        else {
            take = 1;
            n2 -= all[i - 1].second;
        }
        for (int v : by[i - 1][take]) {
            ans[v] = 2;
        }
        for (int v : by[i - 1][take ^ 1]) {
            if (n1) {
                ans[v] = 1;
                n1--;
            }
            else if (n3) {
                ans[v] = 3;
                n3--;
            }
            else {
                assert(false);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    return 0;
}