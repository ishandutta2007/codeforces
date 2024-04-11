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
        int l = 1e9;
        int r = 0;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt++;
                l = min(l, i);
                r = max(r, i);
            }
        }
        if (cnt == 0) {
            cout << 0 << '\n';
        }
        else if (cnt == r - l + 1) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }
    return 0;
}