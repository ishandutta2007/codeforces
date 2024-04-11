#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    srand(123 + 23123123 + 123123 - 123123);
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    vector < pair < int, int > > all;
    ll ans = 0;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        all.emplace_back(make_pair(x, 0));
    }
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        all.emplace_back(make_pair(x, 1));
    }
    sort(all.begin(), all.end());
    reverse(all.begin(), all.end());
    for (int i = 0; i < 2 * n; i++) {
        if (all[i].second == 0 && i % 2 == 0) ans += all[i].first;
        if (all[i].second == 1 && i % 2 == 1) ans -= all[i].first;
    }
    cout << ans;
    return 0;
}