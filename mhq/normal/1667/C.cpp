#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cout << (2 * n + 1) / 3 << '\n';
    if (n % 3 == 2 || n % 3 == 1) {
        for (int i = 1; i <= n / 3; i++) {
            cout << i << " " << (n / 3 + 1) - i << '\n';
        }
        int k = n / 3;
        for (int i = 1; i <= k + 1; i++) {
            cout << i + k << " " << (3 * k + 2 - i - k) << '\n';
        }
    }
    else {
        for (int i = 1; i <= n / 3; i++) {
            cout << i << " " << (n / 3 + 1) - i << '\n';
        }
        int k = n / 3;
        cout << (k + 1) << " " << (k + 1) << '\n';
        for (int i = 2; i <= k; i++) {
            cout << i + k << " " << (3 * k + 2 - i - k) << '\n';
        }
    }
    return 0;
}