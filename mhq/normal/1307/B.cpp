#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
ll a[maxN];
int n, x;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        cin >> n >> x;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (a[i] == x) ok = true;
        }
        if (ok) {
            cout << 1 << '\n';
        }
        else {
            sort(a + 1, a + n + 1);
            cout << max(2LL, (x + a[n] - 1) / a[n]) << '\n';
        }
    }
    return 0;
}