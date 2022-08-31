#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 1005;
int a[maxN];
void solve() {
    int sm = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    cout << min(m, sm) << '\n';
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