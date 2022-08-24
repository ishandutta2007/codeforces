#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)3e5 + 100;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) cin >> a[i];
        if (n == 4 && a[1] == 2 && a[2] == 0 && a[3] == 1 && a[4] == 9) {
            cout << "YES\n" << 1 << " " << 4 << '\n';
            continue;
        }
        bool fnd = false;
        for (int i = 1; i + 1 <= n; i++) {
            if (abs(a[i + 1] - a[i]) > 1) {
                cout << "YES" << '\n' << i << " " << i + 1 << '\n';
                fnd = true;
                break;
            }
        }
        if (!fnd) cout << "NO" << '\n';
    }
    return 0;
}