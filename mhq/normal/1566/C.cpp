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
        int n;
        cin >> n;
        string s, t;
        cin >> s >> t;
        int ans = 0;
        int bef = -1;
        for (int i = 0; i < n; i++) {
            int tp = 0;
            if (s[i] == '0' || t[i] == '0') tp |= 1;
            if (s[i] == '1' || t[i] == '1') tp |= 2;
            if (tp == 3) {
                ans += 2;
                if (bef == 1) ans++;
                bef = -1;
            }
            else if (tp == 2) {
                if (bef == 1) {
                    ans += 2;
                    bef = -1;
                }
                else {
                    bef = 2;
                }
            }
            else {
                if (bef == 2) {
                    ans += 2;
                    bef = -1;
                }
                else if (bef == 1) {
                    ans += 1;
                    bef = 1;
                }
                else {
                    bef = 1;
                }
            }
        }
        if (bef == 1) ans++;
        cout << ans << '\n';
    }
    return 0;
}