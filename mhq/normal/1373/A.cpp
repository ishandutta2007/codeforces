#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int a, ta, b, tb;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        ll a, b, c;
        cin >> a >> b >> c;
        if (a < c) cout << 1 << " ";
        else cout << -1 << " ";
        if (a * b > c) cout << b << " ";
        else cout << -1 << " ";
        cout << '\n';
    }
    return 0;
}