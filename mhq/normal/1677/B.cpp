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
        vector<bool> can(m);
        int cnt = 0;
        vector<int> cnt_good(n);
        vector<int> ans(n * m);
        int last = -1;
        for (int i = 0; i < n * m; i++) {
            if (s[i] == '1') last = i;
            if (s[i] == '1' && !can[i % m]) {
                can[i % m] = true;
                cnt++;
            }
            if (i >= m) {
                ans[i] = ans[i - m];
            }
            if (last >= max(i - m + 1, 0)) {
                ans[i]++;
            }
            cout << ans[i] + cnt << " ";
        }
        cout << '\n';
    }
    return 0;
}