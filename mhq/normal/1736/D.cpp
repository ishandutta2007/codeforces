#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int cnt0 = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') cnt0++;
        }
        if (cnt0 % 2 != 0) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> st;
        for (int i = 0; i < s.size(); i += 2) {
            if (s[i] != s[i + 1]) {
                st.emplace_back(i);
            }
        }
        assert(st.size() % 2 == 0);
        vector<int> ans;
        for (int p = 0; p < st.size(); p++) {
            if (s[st[p]] == (char)('0' + p % 2)) {
                ans.emplace_back(st[p]);
            }
            else {
                ans.emplace_back(st[p] + 1);
            }
        }
        cout << ans.size() << '\n';
        for (int v : ans) cout << v + 1 << " ";
        cout << '\n';
        for (int x = 1; x <= 2 * n; x += 2) cout << x << " ";
        cout << '\n';
    }
    return 0;
}