#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m, k;
const int maxN = (int)1e5 + 100;
vector < int > g[maxN];
bool used[maxN];
int sz = 0;
void dfs(int v, int par) {
    sz++;
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) continue;
        dfs(to, v);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int sm = 0;
    int cnt = 0;
    int mlt = 1;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            sz = 0;
            dfs(i, -1);
            cnt++;
            mlt = (1LL * mlt * sz) % k;
            sm += sz;
            sm %= k;
        }
    }
    if (cnt == 1) {
        cout << 1 % k;
        return 0;
    }
    int coef = 1;
    for (int j = 0; j < (cnt - 2); j++) coef = (1LL * coef * sm) % k;
    cout << (1LL * coef * mlt) % k;
    return 0;
}