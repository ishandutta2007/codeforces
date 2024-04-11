#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int n, m;
vector<int> v[maxN];
int ans[maxN];
bool was[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    memset(ans, -1, sizeof ans);
    ans[0] = 0;
    const int P = 100000;
    for (int i = 1; i <= n; i++) {
        int t;
        ll x;
        int y;
        cin >> t >> x >> y;
        for (int r = 0; r <= m; r++) {
            v[r].clear();
        }
        memset(was, 0, sizeof was);
        for (int r = 0; r <= m; r++) {
            if (ans[r] != -1) {
                v[0].emplace_back(r);
                was[r] = true;
            }
        }
        for (int r = 0; r <= y - 1; r++) {
            for (int u : v[r]) {
                ll nxt;
                if (t == 1) {
                    nxt = (u + (x + P - 1) / P);
                }
                else {
                    nxt = ((1LL * u * x) + P - 1) / P;
                }
                if (nxt > m) continue;
                if (!was[nxt]) {
                    was[nxt] = true;
                    ans[nxt] = i;
                    v[r + 1].emplace_back(nxt);
                }
            }
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i] << " ";
    return 0;
}