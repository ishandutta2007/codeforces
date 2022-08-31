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
        int n, s;
        cin >> n >> s;
        if (n % 2 == 0) {
            cout << (s / (n / 2 + 1)) << '\n';
        }
        else {
            cout << (s / (n / 2 + 1)) << '\n';
        }
    }
    return 0;
}