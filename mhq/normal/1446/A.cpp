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
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        ll w;
        cin >> n >> w;
        vector<pair<ll,int>> all;
        ll s = 0;
        for (int i = 0; i < n; i++) {
            ll t;
            cin >> t;
            if (t > w) continue;
            all.emplace_back(t, i);
            s += t;
        }
        sort(all.begin(), all.end());
        if (s < (w + 1) / 2) {
            cout << -1 << '\n';
            continue;
        }
        int ind = -1;
        ll x = 0;
        for (int i = 0; i < all.size(); i++) {
            x += all[i].first;
            if (x >= (w + 1) / 2) {
                ind = i;
                break;
            }
        }
        assert(ind != -1);
        int ind2 = 0;
        while (x > w) {
            x -= all[ind2].first;
            ind2++;
        }
        assert(x >= (w + 1) / 2 && x <= w);
        cout << ind - ind2 + 1 << '\n';
        for (int j = ind2; j <= ind; j++) {
            cout << all[j].second + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}