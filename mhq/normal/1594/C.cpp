#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3e5 + 10;
char tp[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        char c;
        cin >> n >> c;
        bool can = true;
        for (int i = 1; i <= n; i++) {
            cin >> tp[i];
            can &= (tp[i] == c);
        }
        if (can) {
            cout << 0 << '\n';
            continue;
        }
        int fnd = -1;
        for (int i = 1; i <= n; i++) {
            bool ok = true;
            for (int j = i; j <= n; j += i) {
                if (tp[j] != c) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                fnd = i;
                break;
            }
        }
        if (fnd != -1) {
            cout << 1 << '\n' << fnd << '\n';
        }
        else {
            cout << 2 << '\n' << n - 1 << " " << n << '\n';
        }
    }
    return 0;
}