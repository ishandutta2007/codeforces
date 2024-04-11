#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 1e5 + 10;
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
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (a[1] == 1) {
            cout << n + 1 << " ";
            for (int i = 1; i <= n; i++) cout << i << " ";
            cout << '\n';
        }
        else if (a[n] == 0) {
            for (int i = 1; i <= n + 1; i++) cout << i << " ";
            cout << '\n';
        }
        else {
            int pos = -1;
            for (int i = 1; i <= n - 1; i++) {
                if (a[i] == 0 && a[i + 1] == 1) {
                    pos = i;
                    break;
                }
            }
            assert(pos != -1);
            for (int i = 1; i <= pos; i++) cout << i << " ";
            cout << n + 1 << " ";
            for (int i = pos + 1; i <= n; i++) cout << i << " ";
            cout << '\n';
        }
    }
    return 0;
}