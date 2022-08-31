#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 3005;
int x[maxN], y[maxN];
vector<int> g[maxN];
bool used[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= 2 * n; i++) {
        cin >> x[i] >> y[i];
        g[x[i]].emplace_back(y[i]);
        g[y[i]].emplace_back(x[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            vector<int> cycle;
            int c = i;
            while (!used[c]) {
                used[c] = true;
                cycle.emplace_back(c);
                if (c == i) {
                    c = g[c][0];
                }
                else {
                    c = (g[c][0] ^ g[c][1]) ^ (cycle[cycle.size() - 2]);
                }
            }
            assert(cycle.size() % 2 == 0);
            for (int z = 0; z < cycle.size(); z++) {
                //z, z + 1
                ll l1 = cycle[z];
                ll r1 = cycle[z];
                ll l2 = cycle[(z + 1) % cycle.size()];
                ll r2 = cycle[(z + 1) % cycle.size()];
                //E
                for (int t = 1; t < cycle.size(); t++) {
                   int edge = (z + t) % cycle.size();

                   int he = cycle[(edge + 1) % cycle.size()];
                   if (t % 2 != 0) {
                       //good
                       if (l1 <= he && he <= r1) continue;
                       if (l1 <= n) {
                           ll f = (l2 - n) * (2 * n + 1 - r2);
                           if (he < l1) {
                               ans += f * (n + 1 - r1) * (l1 - he);
                           }
                           else {
                               ans += f * l1 * (he - r1);
                           }
                       }
                       else {
                           ll f = (l2) * (n + 1 - r2);
                           if (he < l1) {
                               ans += f * (2 * n + 1 - r1) * (l1 - he);
                           }
                           else {
                               ans += f * (l1 - n) * (he - r1);
                           }
                       }
                   }
                   //EXIST
                   if (t % 2 != 0) {
                       l1 = min(l1, (ll)he);
                       r1 = max(r1, (ll)he);
                   }
                   else {
                       l2 = min(l2, (ll)he);
                       r2 = max(r2, (ll)he);
                   }
                }
                //cycle case
                if (z % 2 == 0) {
                    if (l1 <= n) {
                        ans += l1 * (n + 1 - r1) * (l2 - n) * (2 * n + 1 - r2);
                    }
                    else {
                        ans += (l1 - n) * (2 * n + 1 - r1) * l2 * (2 * n + 1 - r2);
                    }
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}