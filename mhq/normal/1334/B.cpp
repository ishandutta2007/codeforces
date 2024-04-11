#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
int x;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n >> x;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + n + 1);
        reverse(a + 1, a + n + 1);
        int mx = 0;
        ll sm = 0;
        for (int i = 1; i <= n; i++) {
            sm += a[i];
            if (sm >= 1LL * i * x) mx = max(mx, i);
        }
        cout << mx << '\n';
    }
    return 0;
}