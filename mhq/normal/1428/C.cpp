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
        reverse(s.begin(), s.end());
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'A') {
                if (!ans.empty() && ans.back() == 'B') {
                    ans.pop_back();
                    continue;
                }
                else {
                    ans += 'A';
                }
            }
            else {
                ans += 'B';
            }
        }
        string tans;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == 'A') tans += ans[i];
            else {
                if (!tans.empty() && tans.back() == 'B') tans.pop_back();
                else tans += 'B';
            }
        }
        cout << tans.size() << '\n';
    }
    return 0;
}