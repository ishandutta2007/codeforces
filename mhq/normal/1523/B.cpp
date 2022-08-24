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
        //a[1] = a[1] + a[2]
        for (int i = 1; i <= n; i++) {
            int tr;
            cin >> tr;
        }
        cout << 6 * (n / 2) << '\n';
        for (int i = 1; i <= n; i += 2) {
            int l = i;
            int r = i + 1;
            cout << "1 " << l << " " << r << '\n';
            cout << "2 " << l << " " << r << '\n';
            cout << "1 " << l << " " << r << '\n';
            cout << "1 " << l << " " << r << '\n';
            cout << "2 " << l << " " << r << '\n';
            cout << "1 " << l << " " << r << '\n';
        }
    }
    return 0;
}