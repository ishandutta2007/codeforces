#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool win[228];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);

    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        if (n % 2 == 1) {
            cout << "Bob\n";
            continue;
        }
        if ((n & (n - 1))) {
            cout << "Alice\n";
            continue;
        }
        for (int x = 0; ; x++) {
            if (n == (1 << x)) {
                if (x % 2 == 0) {
                    cout << "Alice\n";
                }
                else {
                    cout << "Bob\n";
                }
                break;
            }
        }
    }
    return 0;
}