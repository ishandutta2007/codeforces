#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int c0 = 0, c1 = 0, l0 = s.size(), r0 = -1;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '0') {
                ++c0;
                l0 = min(l0, i);
                r0 = max(r0, i);
            }
            else ++c1;
        }
        if (c0 == 0) cout << 0 << '\n';
        else if (r0 - l0 + 1 == c0) cout << 1 << '\n';
        else cout << 2 << '\n';
    }
    return 0;
}