#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
ll a[maxN], b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        ll f = 0;
        ll mn = 1e18;
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
        }
        for (int i = 0; i < n; i++) {
            f += max(0LL, a[i] - b[(i + n - 1) % n]);
            mn = min(mn, a[i] - max(0LL, a[i] - b[(i + n - 1) % n]));
        }
        cout << mn + f << '\n';
    }
    return 0;
}