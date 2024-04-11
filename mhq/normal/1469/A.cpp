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
        if (s.size() % 2 == 1) {
            cout << "NO\n";
        }
        else {
            int bal = 0;
            bool ok = true;
            int cnt = (s.size() - 2) / 2;
            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '?') {
                    if (cnt == 0) {
                        s[i] = ')';
                    }
                    else {
                        s[i] = '(';
                        cnt--;
                    }
                }
                if (s[i] == '(') bal++;
                else bal--;
                if (bal < 0) ok = false;
            }
            if (bal != 0) ok = false;
            if (ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}