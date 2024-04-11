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
        ll s = 0;
        bool ok = true;
        for (int i = 1; i <= n; i++) {
            int h;
            cin >> h;
            s += h - (i - 1);
            if (s < 0) ok = false;
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}