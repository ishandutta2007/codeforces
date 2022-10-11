#include <bits/stdc++.h>
using namespace std;

const int INF = 1E9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string s; cin >> s;
        string t = "abacaba";
        string tmp;
        bool yes = false;
        for (int i = 0; i <= (int)s.size() - t.size(); i++) {
            tmp = s;
            bool ok = true;
            for (int j = 0; j < t.size(); j++) {
                if (s[i + j] == '?' || s[i + j] == t[j]) {
                    tmp[i + j] = t[j];
                } else {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                auto xd = tmp.find(t);
                if (tmp.find(t, xd + 1) != tmp.npos) {
                    ok = false;
                }
            }
            if (ok) {
                yes = true;
                break;
            }
        }
        if (yes) {
            cout << "Yes\n";
            for (int i = 0; i < tmp.size(); i++) {
                if (tmp[i] == '?') tmp[i] = 'z';
            }
            cout << tmp << '\n';
        } else {
            cout << "No\n";
        }
    }
}