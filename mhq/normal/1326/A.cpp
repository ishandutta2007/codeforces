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
        if (n == 1) {
            cout << -1 << '\n';
            continue;
        }
        if ((n - 1) % 3 != 0) {
            cout << string(n - 1, '2') << 3 << '\n';
        }
        else {
            cout << string(n - 2, '2') << 4 << 3 << '\n';
        }
    }
    return 0;
}