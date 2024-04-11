#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = (int)1e5 + 100;
int a[maxN];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    cin >> n;
    int fl = 0;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x % 2 == 0) {
            cout << x / 2 << '\n';
        }
        else {
            if (fl) {
                cout << ((x + 1)) / 2 << '\n';
            }
            else {
                cout << ((x - 1)) / 2 << '\n';
            }
            fl ^= 1;
        }
    }
    return 0;
}