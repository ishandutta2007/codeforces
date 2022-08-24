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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> l(n, -1), r(n, -1);
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') l[i] = i;
            else {
                if (i) l[i] = l[i - 1];
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '1') r[i] = i;
            else {
                if (i + 1 < n) r[i] = r[i + 1];
            }
        }
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') cout << '1';
            else {
                if (l[i] == -1 && r[i] == -1) cout << 0;
                else if (l[i] == -1) {
                    if (r[i] - i <= m) cout << 1;
                    else cout << 0;
                }
                else if (r[i] == -1) {
                    if (i - l[i] <= m) cout << 1;
                    else cout << 0;
                }
                else {
                    if (i - l[i] == r[i] - i) {
                        cout << 0;
                    }
                    else {
                        if (i - l[i] <= m || r[i] - i <= m) {
                            cout << 1;
                        }
                        else {
                            cout << 0;
                        }
                    }
                }
            }
        }
        cout << '\n';
    }
    return 0;
}