#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s, t;
        cin >> s >> t;
        if (s.size() < (int)t.size()) {
            cout << "NO" << '\n';
            continue;
        }

        if (s.size() % 2 != (int)t.size() % 2) s = ' ' + s;
        string ans = "NO";
        int cur = 0, id = 0;
        while (id < s.size() && cur < t.size()) {
            if (s[id] == t[cur]) {
                ++cur;
                ++id;
            }
            else id += 2;
        }
        if (cur == t.size()) ans = "YES";
        cout << ans << '\n';
    }
    return 0;
}