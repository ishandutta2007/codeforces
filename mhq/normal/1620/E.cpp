#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 5e5 + 10;
vector<int> occ[maxN];
int ans[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    int sz = 0;
    while (n--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            int x;
            cin >> x;
            sz++;
            occ[x].emplace_back(sz);
        }
        else if (tp == 2) {
            int x, y;
            cin >> x >> y;
            if (x != y) {
                if (occ[x].size() > occ[y].size()) swap(occ[x], occ[y]);
                for (int u : occ[x]) occ[y].emplace_back(u);
                occ[x].clear();
            }
        }
    }
    for (int i = 1; i <= 500000; i++) {
        for (int z : occ[i]) {
            ans[z] = i;
        }
    }
    for (int i = 1; i <= sz; i++) cout << ans[i] << " ";
    return 0;
}