#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; string s;
        cin >> n >> s;
        bool chk = true;
        if (count_if(s.begin(), s.end(), [](const char u) {
            return u == 'M';
        }) != n / 3) {
            chk = false;
        }
        for (int i = 0; i < 2; i++) {
            int cur = 0;
            for (char c : s) {
                cur += (c == 'M' ? -1 : 1);
                if (cur < 0) {
                    chk = false;
                    break;
                }
            }
            reverse(s.begin(), s.end());
        }
        cout << (chk ? "YES\n" : "NO\n");
    }
}