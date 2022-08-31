#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = (int)1e6 + 10;
int a[maxN], b[maxN];
int p;
void solve() {
    cin >> n >> m >> p;
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % p != 0 && x == -1) x = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
        if (b[i] % p != 0 && y == -1) y = i;
    }
    assert(x != -1 && y != -1);
    cout << x + y << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst = 1;
//    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}