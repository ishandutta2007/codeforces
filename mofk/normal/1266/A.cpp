#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        string s;
        cin >> s;
        int tot = 0, ans = 1, zero = 0, even = 0;
        for (int i = 0; i < s.size(); ++i) {
            tot += (s[i] - '0');
            zero += (s[i] == '0');
            even += ((s[i] - '0') % 2 == 0);
        }
        if (tot % 3 != 0 || !zero) ans = 0;
        if (s.size() > 1 && even <= 1) ans = 0;
        cout << (ans ? "red" : "cyan") << '\n';
    }
    return 0;
}