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
        int n, m, x;
        cin >> n >> m >> x;
        vector<pair<int,int>> all(n);
        for (int i = 0; i < n; i++) {
            cin >> all[i].first;
            all[i].second = i;
        }
        sort(all.begin(), all.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[all[i].second] = i % m;
        }
        cout << "YES\n";
        for (int i = 0; i < n; i++) {
            cout << ans[i] + 1 << " ";
        }
        cout << '\n';
    }
    return 0;
}