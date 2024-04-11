#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
void solve() {
    int n, k;
    cin >> n >> k;
    if (n == 1) {
        cout << 1 << '\n';
        return;
    }
    n--;
    string s = to_string(n);
    string ans;
    for (int i = s.size() - 1; i >= 0; i--) {
        int dig = s[i] - '0';
        for (int j = dig + 1; j <= 9; j++) {
            set<int> gg;
            gg.insert(j);
            for (int x = 0; x < i; x++) gg.insert(s[x] - '0');
            if (gg.size() > k) continue;
            if ((int)gg.size() < k) {
                cout << s.substr(0, i) + (char)('0' + j) + string(s.size() - 1 - i, '0') << '\n';
                return;
            }
            else {
                int min_dig = 9;
                min_dig = min(min_dig, j);
                for (int p = 0; p < i; p++) min_dig = min(min_dig, s[p] - '0');
                cout << s.substr(0, i) + (char)('0' + j) + string(s.size() - 1 - i, min_dig + '0') << '\n';
                return;
            }

        }
    }
    if (k == 1) {
        cout << string(s.size() + 1, '1') << '\n';
    }
    else {
        cout << '1' + string(s.size(), '0') << '\n';
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        solve();
    }
    return 0;
}