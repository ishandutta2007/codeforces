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
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    //2*ai + 2 * aj > ai - aj
    //3 * aj > ai
    while (tst--) {
        int n;
        cin >> n;
        ll c = 1;
        vector<int> gg;
        const ll INF = 1000000000;
        for (int i = 1; i <= n; i++) {
            gg.emplace_back(c);
            c *= 3;
            if (c > INF) break;
        }
        if (gg.size() == n) {
            cout << "YES\n";
            for (ll t : gg) cout << t << " ";
            cout << '\n';
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}