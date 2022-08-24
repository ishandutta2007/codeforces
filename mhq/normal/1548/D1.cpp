#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 6005;
int x[maxN], y[maxN];
ll D[2][2];
ll get(ll x, int sz) {
    if (sz == 0) return 1;
    if (sz == 1) return x;
    if (sz == 2) return (x * (x - 1)) / 2;
    if (sz == 3) {
        return (x * (x - 1) * (x - 2)) / 6;
    }
    else {
        assert(false);
        return -228;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        assert(x[i] % 2 == 0 && y[i] % 2 == 0);
        x[i] /= 2;
        y[i] /= 2;
        D[x[i] % 2][y[i] % 2]++;
    }
    ll ans = 0;
    for (int z1 = 0; z1 <= 3; z1++) {
        for (int z2 = 0; z2 + z1 <= 3; z2++) {
            for (int z3 = 0; z3 + z2 + z1 <= 3; z3++) {
                int z4 = 3 - z3 - z2 - z1;
                vector<pair<int,int>> ids;
                for (int x = 0; x < z1; x++) ids.emplace_back(0, 0);
                for (int x = 0; x < z2; x++) ids.emplace_back(0, 1);
                for (int x = 0; x < z3; x++) ids.emplace_back(1, 0);
                for (int x = 0; x < z4; x++) ids.emplace_back(1, 1);
                assert(ids.size() == 3);
                int cnt = 0;
                for (int A = 0; A < 3; A++) {
                    for (int B = A + 1; B < 3; B++) {
                        auto t1 = ids[A];
                        auto t2 = ids[B];
                        if (t1 != t2) cnt ^= 1;
                    }
                }
                if (cnt == 0) {
                    ll coef = 1;
                    coef *= get(D[0][0], z1);
                    coef *= get(D[0][1], z2);
                    coef *= get(D[1][0], z3);
                    coef *= get(D[1][1], z4);
                    ans += coef;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}