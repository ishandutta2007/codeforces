#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
bool prime(int x) {
    for (int i = 2; i * i <= x; i++) {
        if (x % i == 0) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        const string first = "Ashishgup";
        const string second = "FastestFinger";
        if (n == 1) {
            cout << second << '\n';
        }
        else if (n == 2) {
            cout << first << '\n';
        }
        else if (n % 2 == 1) {
            cout << first << '\n';
        }
        else {
            if (!(n & (n - 1))) {
                cout << second << '\n';
            }
            else if (n % 4 == 0) {
                cout << first << '\n';
            }
            else {
                if (prime(n / 2)) cout << second << '\n';
                else cout << first << '\n';
            }

        }

    }
    return 0;
}