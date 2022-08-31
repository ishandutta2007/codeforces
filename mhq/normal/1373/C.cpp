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
        string s;
        cin >> s;
        int mn_bal = 0;
        int b = 0;
        for (char &c : s) {
            if (c == '-') {
                mn_bal--;
            }
            else {
                mn_bal++;
            }
            b = min(b, mn_bal);
        }
        int to = -b;
        ll tot = 0;
        int cur_mn = 0;
        int cur_bal = 0;
        for (char &c : s) {
            if (c == '-') {
                cur_bal--;
            }
            else {
                cur_bal++;
            }
            tot += (to + cur_mn + 1);
            cur_mn = min(cur_mn, cur_bal);
        }
        cout << tot << '\n';
    }
    return 0;
}