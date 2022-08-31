#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int w[maxN];
int deg[maxN];
ll delta1[maxN];
ll delta2[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;

        ll ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> w[i];
            ans += w[i];
            deg[i] = 0;
        }
        for (int i = 1; i <= n + 2; i++) {
            delta1[i] = 0;
            delta2[i] = 0;
        }
        vector<ll> add;
        for (int i = 1; i < n; i++) {
            int u, v;
            cin >> u >> v;
            deg[u]++;
            deg[v]++;
        }
        for (int i = 1; i <= n; i++) {
            for (int x = 1; x < deg[i]; x++) {
                add.emplace_back(w[i]);
            }
        }
        sort(add.begin(), add.end());
        reverse(add.begin(), add.end());
        for (int i = 1; i < n; i++) {
            cout << ans << " ";
            if (i - 1 < add.size()) ans += add[i - 1];
        }
        cout << '\n';
    }
    return 0;
}