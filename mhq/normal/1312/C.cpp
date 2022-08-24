#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 65;
bool ok[maxN][maxN];
int k;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n >> k;
        memset(ok, 0, sizeof ok);
        bool can = true;
        for (int i = 1; i <= n; i++) {
            ll x;
            cin >> x;
            for (int pos = 0; pos < maxN; pos++) {
                int t = x % k;
                x /= k;
                if (t > 1) {
                    can = false;
                }
                else if (t == 1) {
                    if (ok[pos][t]) can = false;
                    ok[pos][t] = true;
                }
            }
        }
        if (can) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}