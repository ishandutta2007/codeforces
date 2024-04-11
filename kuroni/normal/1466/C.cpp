#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        int cur = 0, ans = 0;
        cin >> s;
        for (int i = 1; i < s.size(); i++) {
            bool chk = false;
            if (s[i] == s[i - 1] || (i >= 2 && s[i] == s[i - 2])) {
                chk = true;
            }
            if (chk) {
                s[i] = cur + 'A';
                (++cur) %= 26;
                ans++;
            }
        }
        cout << ans << '\n';
    }
}