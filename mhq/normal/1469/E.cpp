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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int f = 0;
        int tot = n - k + 1;
        while ((1 << f) <= tot) f++;
        f = min(f, k);
        vector<int> pref(n + 1);
        for (int i = 0; i < s.size(); i++) {
            pref[i + 1] = pref[i];
            if (s[i] == '0') pref[i + 1]++;
        }
        string ans = string(k - f, '0');
        int have = k - f;
        vector<bool> good(1 << f, true);
        for (int i = 0; i <= n - k; i++) {
            if (pref[i] == pref[i + have]) {
                int from = i + have;
                int to = i + k - 1;
                int m = 0;
                for (int j = from; j <= to; j++) {
                    if (s[j] == '1') m |= (1 << (to - j));
                }
                assert(m < (1 << f));
                good[((1 << f) - 1) ^ m] = false;
            }
        }
        int c = 0;
        while (c < (1 << f) && !good[c]) c++;
        if (c == (1 << f)) {
            cout << "NO\n";
        }
        else {
            assert(c != (1 << f));
            for (int x = f - 1; x >= 0; x--) {
                if (c & (1 << x)) ans += '1';
                else ans += '0';
            }
            cout << "YES\n";
            assert(ans.size() == k);
            cout << ans << '\n';
        }
    }
    return 0;
}