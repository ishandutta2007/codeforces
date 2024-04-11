#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        if ((y - x) % (a + b) == 0) {
            cout << (y - x) / (a + b) << '\n';
        }
        else {
            cout << -1 << '\n';
        }
    }
    return 0;
}