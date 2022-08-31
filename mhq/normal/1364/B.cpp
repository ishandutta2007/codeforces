#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int p[maxN];
void solve() {
    vector < int > ans;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        while (ans.size() >= 2 && ((ans[ans.size() - 2] <= ans.back() && ans.back() <= x) || (ans[ans.size() - 2] >= ans.back() && ans.back() >= x))) {
            ans.pop_back();
        }
        ans.emplace_back(x);
    }
    cout << ans.size() << '\n';
    for (int v : ans) cout << v << " ";
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}