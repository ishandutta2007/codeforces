#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        int sum = 0, dif = 0;
        for (char c : s) {
            if (c == '?') {
                sum++;
            } else if (c == '(') {
                dif--;
            } else {
                dif++;
            }
        }
        int open = (dif + sum) / 2;
        int end_pos = n;
        for (int i = 0; i < n; i++) {
            open -= (s[i] == '?');
            if (open < 0) {
                end_pos = i;
                break;
            }
        }
        vector<int> pf(end_pos), sf(end_pos);
        for (int i = 0; i < end_pos; i++) {
            pf[i] = (i == 0 ? 0 : pf[i - 1]) + (s[i] == ')' ? -1 : 1);
        }
        for (int i = end_pos - 1; i >= 0; i--) {
            sf[i] = min(i + 1 == end_pos ? n : sf[i + 1], pf[i]);
        }
        bool ok = false;
        for (int i = 0; i < end_pos; i++) {
            if (s[i] == '?' && pf[i] >= 2 && sf[i] >= 2) {
                ok = true;
                break;
            }
        }
        cout << (ok ? "NO\n" : "YES\n");
    }
}