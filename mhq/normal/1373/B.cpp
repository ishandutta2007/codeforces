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
        int c0 = 0, c1 = 0;
        for (char& c : s) {
            if (c == '0') c0++;
            else c1++;
        }
        int moves = min(c0, c1);
        if (moves % 2 == 0) cout << "NET\n";
        else cout << "DA\n";
    }
    return 0;
}