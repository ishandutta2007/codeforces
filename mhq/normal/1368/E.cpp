#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 10;
vector < int > g[maxN];
bool has_bad[maxN];
vector < int > gr[maxN];
bool alive[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            alive[i] = true;
            g[i].clear();
            gr[i].clear();
            has_bad[i] = false;
        }
        for (int i = 1; i <= m; i++) {
            int x, y;
            cin >> x >> y;
            g[x].emplace_back(y);
            gr[y].emplace_back(x);
        }
        for (int i = 1; i <= n; i++) {
            bool hs = false;
            for (int to : gr[i]) {
                if (alive[to]) has_bad[i] = true;
                if (has_bad[to]) hs = true;
            }
            if (hs) {
                has_bad[i] = false;
                alive[i] = false;
            }
        }
        vector < int > ans;
        for (int i = 1; i <= n; i++) {
            if (!alive[i]) ans.emplace_back(i);
        }
        assert(ans.size() <= (4 * n) / 7);
        cout << ans.size() << '\n';
        for (int to : ans) cout << to << " ";
        cout << '\n';
    }
    return 0;
}