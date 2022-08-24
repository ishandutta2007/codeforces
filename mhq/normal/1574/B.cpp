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
        int a, b, c, m;
        cin >> a >> b >> c >> m;
        if (a < b) swap(a, b);
        if (a < c) swap(a, c);
        if (m <= (a - 1) + (b - 1) + (c - 1) && m >= a - 1 - b - c) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}