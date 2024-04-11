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
        int l[3];
        cin >> l[0] >> l[1] >> l[2];
        sort(l, l + 3);
        if (l[2] == l[0] + l[1] || (l[0] == l[1] && l[2] % 2 == 0) || (l[1] == l[2] && l[0] % 2 == 0)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}