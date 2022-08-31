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
        int n = s.size();
        int best = n;
        int f[2] = {0, 0};
        for (int x = 0; x < n; x++) {
            f[s[x] - '0']++;
        }
        int c[2] = {0, 0};
        for (int pref = 0; pref <= n; pref++) {
            if (pref > 0) {
                c[s[pref - 1] - '0']++;
            }
            for (int r = 0; r < 2; r++) {
                int val = c[r] + ((f[r ^ 1] - c[r ^ 1]));
                best = min(best, val);
            }
        }
        cout << best << '\n';
    }
    return 0;
}