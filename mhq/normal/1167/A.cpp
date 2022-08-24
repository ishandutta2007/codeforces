#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int mx = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '8') {
                mx = max(mx, (int)s.size() - 1 - i - 1 + 1);
            }
        }
        if (mx >= 10) cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}