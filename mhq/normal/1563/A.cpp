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
        int a, b;
        cin >> a >> b;
        int total = a + b;
        set<int> s;
        for (int i = 0; i < 2; i++) {
            int x, y;
            if (i == 0) {
                x = total / 2;
                y = (total + 1) / 2;
            }
            else {
                x = (total + 1) / 2;
                y = total / 2;
            }
            for (int a_win = 0; a_win <= x; a_win++) {
                int a_break = a - a_win;
                int b_break = x - a_win;
                int b_win = b - b_break;
                if (a_win >= 0 && a_break >= 0 && b_break >= 0 && b_win >= 0) {
                    s.insert(a_break + b_break);
                }
            }
        }
        cout << s.size() << '\n';
        for (int u : s) cout << u << " ";
        cout << '\n';
    }
    return 0;
}