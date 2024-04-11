#include <bits/stdc++.h>
using namespace std;
string s, t;
vector < string > ans;
int main() {
    ios_base::sync_with_stdio(false);
    cin >> s >> t;
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            string x1;
            for (int i1 = 0; i1 < i; i1++) {
                x1 += s[i1];
            }
            for (int j1 = 0; j1 < j; j1++) {
                x1 += t[j1];
            }
            ans.push_back(x1);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[0];
}