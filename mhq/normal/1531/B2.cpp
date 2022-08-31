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
    int n;
    cin >> n;
    vector<int> h(n), w(n);
    map<pair<int,int>, int> all;
    ll ans = 0;
    map<int, int> by;
    for (int i = 0; i < n; i++) {
        cin >> h[i] >> w[i];
        if (h[i] > w[i]) swap(h[i], w[i]);
        ans += by[h[i]];
        by[h[i]]++;
        if (h[i] != w[i]) {
            ans += by[w[i]];
            by[w[i]]++;
        }
        if (h[i] != w[i]) {
            ans -= all[make_pair(h[i], w[i])];
            all[make_pair(h[i], w[i])]++;
        }
    }
    cout << ans << '\n';
    return 0;
}