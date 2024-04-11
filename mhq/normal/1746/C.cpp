#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int n;
const int maxN = 1e5 + 10;
int a[maxN];
int x[maxN];
void solve() {
    cin >> n;
    ll added = 0;
    vector<pair<int,int>> need;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i > 1) {
            need.emplace_back(max(0, a[i - 1] - a[i]), i);
        }
    }
    sort(need.begin(), need.end());
    reverse(need.begin(), need.end());
    for (int p = 0; p < need.size(); p++) {
        assert(n - p >= need[p].first);
        x[n - p] = need[p].second;
    }
    x[1] = n;
    for (int i = 1; i <= n; i++) {
        cout << x[i] << " ";
    }
    cout << '\n';


}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}