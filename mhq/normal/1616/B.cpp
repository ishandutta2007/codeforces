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
        string s;
        cin >> s;
        if (n == 1) {
            cout << s + s << '\n';
            continue;
        }
        if (((int)s[0] - 'a') <= ((int)s[1] - 'a')) {
            cout << string(2, s[0]) << '\n';
            continue;
        }
        bool fnd = false;
        for (int i = 0; i + 1 < s.size(); i++) {
            if ((int)(s[i] - 'a') < (int)(s[i + 1] - 'a')) {
                string t = s.substr(0, i + 1);
                string p = t;
                reverse(t.begin(), t.end());
                p += t;
                cout << p << '\n';
                fnd = true;
                break;
            }
        }
        if (!fnd) {
            string t = s;
            reverse(s.begin(), s.end());
            t += s;
            cout << t << '\n';
        }
    }
    return 0;
}