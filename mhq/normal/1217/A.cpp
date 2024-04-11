#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll a, b, ex;
        cin >> a >> b >> ex;
        ll at_least = max(0LL, (ex + b - a + 2) / 2);
        cout << max(0LL, ex - at_least + 1) << '\n';
    }
    return 0;
}