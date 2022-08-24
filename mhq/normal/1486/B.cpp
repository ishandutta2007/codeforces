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
        int n;
        cin >> n;
        vector<int> x, y;
        for (int i = 1; i <= n; i++) {
            int a, b;
            cin >> a >> b;
            x.emplace_back(a);
            y.emplace_back(b);
        }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        if (n % 2 == 1) cout << 1 << '\n';
        else {
            cout << (1LL * x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << '\n';
        }
    }
    return 0;
}