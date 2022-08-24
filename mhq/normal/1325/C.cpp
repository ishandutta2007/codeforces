#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = (int)1e5 + 10;
vector < pair < int, int > > g[maxN];
int deg[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    memset(ans, -1, sizeof ans);
    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].emplace_back(b, i);
        g[b].emplace_back(a, i);
        deg[a]++; deg[b]++;
    }
    bool ok = false;
    for (int i = 1; i <= n; i++) {
        if (deg[i] >= 3) {
            ok = true;
            for (int j = 0; j < 3; j++) {
                ans[g[i][j].second] = j;
            }
            int from = 3;
            for (int j = 1; j <= n - 1; j++) {
                if (ans[j] != -1) continue;
                ans[j] = from;
                from++;
            }
            break;
        }
    }
    if (!ok) {
        for (int i = 1; i <= n - 1; i++) ans[i] = i - 1;
    }
    for (int i = 1; i <= n - 1; i++) cout << ans[i] << '\n';
    return 0;
}