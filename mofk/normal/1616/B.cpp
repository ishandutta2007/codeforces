#include <bits/stdc++.h>

using namespace std;

string ans(string s, int id) {
    string a, b;
    for (int i = 0; i <= id; ++i) a += s[i];
    b = a;
    reverse(b.begin(), b.end());
    return a + b;
}

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int ntest;
    cin >> ntest;
    while (ntest--) {
        int n;
        string s;
        cin >> n >> s;
        int idx = 0;
        if (n > 1) {
            if (s[1] < s[0]) {
                idx = 1;
                while (idx + 1 < n && s[idx + 1] <= s[idx]) ++idx;
            }
        }
        cout << ans(s, idx) << '\n';
    }
    return 0;
}