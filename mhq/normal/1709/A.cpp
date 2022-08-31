#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int x;
        int c[4];
        cin >> x >> c[1] >> c[2] >> c[3];
        if (x == 0) {
            cout << "NO\n";
        }
        else if (c[x] == 0) {
            cout << "NO\n";
        }
        else if (c[c[x]] == 0 || c[c[x]] == x) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
    return 0;
}