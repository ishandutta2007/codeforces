#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int tst;
const int maxN = 505;
int a[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        bool f[2] = {false, false};
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            f[x] = true;
        }
        if (f[0] && f[1]) {
            cout << "Yes\n";
        }
        else {
            bool c = false;
            for (int i = 1; i + 1 <= n; i++) {
                if (a[i] > a[i + 1]) c = true;
            }
            if (c) cout << "No\n";
            else cout << "Yes\n";
        }
    }
    return 0;
}