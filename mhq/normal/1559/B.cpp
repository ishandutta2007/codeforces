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
        int pos = -1;
        for (int i = 0; i < n; i++) {
            if (s[i] != '?') {
                pos = i;
                break;
            }
        }
        if (pos == -1) {
            for (int i = 0; i < n; i++) {
                cout << ((i % 2 == 0) ? 'B' : 'R');
            }
            cout << '\n';
        }
        else {
            for (int i = pos - 1; i >= 0; i--) {
                if (s[i] != '?') continue;
                s[i] = ('R' ^ 'B') ^ s[i + 1];
            }
            for (int i = pos + 1; i < n; i++) {
                if (s[i] != '?') continue;
                s[i] = ('R' ^ 'B') ^ s[i - 1];
            }
            cout << s << '\n';
        }
    }
    return 0;
}