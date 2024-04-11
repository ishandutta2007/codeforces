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
        int n, x;
        cin >> n >> x;
        bool f[2] = {false, false};
        int sm = 0;
        for (int i = 1; i <= n; i++) {
            int c;
            cin >> c;
            f[c % 2] = true;
            sm ^= (c % 2);
        }
        if (x == n) {
            if (sm % 2 == 0) cout << "No\n";
            else cout << "Yes\n";
            continue;
        }
        if (f[0] && f[1]) {
            cout << "Yes\n";
        }
        else if (f[1] && (x % 2 == 1)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}