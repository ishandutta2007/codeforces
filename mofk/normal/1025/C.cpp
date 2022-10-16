#include <bits/stdc++.h>

using namespace std;

string s;

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> s;
    int n = s.size();
    s += s;
    int ans = 1, cur = 1;
    for (int i = 1; i <= s.size(); ++i) {
        if (i < s.size() && s[i] != s[i-1]) ++cur;
        else {
            ans = max(ans, cur);
            cur = 1;
        }
    }
    cout << min(ans, n) << endl;
    return 0;
}