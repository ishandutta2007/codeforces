#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int q;
    cin >> q;
    set<pair<int,int>> byTime, byCost;
    int sz = 0;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 1) {
            sz++;
            int cost;
            cin >> cost;
            byTime.insert(make_pair(sz, cost));
            byCost.insert(make_pair(cost, -sz));
        }
        else if (tp == 2) {
            auto it = *byTime.begin();
            byTime.erase(it);
            byCost.erase(make_pair(it.second, -it.first));
            cout << it.first << " ";
        }
        else {
            auto it = *(--byCost.end());
            byCost.erase(it);
            byTime.erase(make_pair(-it.second, it.first));
            cout << -it.second << " ";
        }
    }
    return 0;
}