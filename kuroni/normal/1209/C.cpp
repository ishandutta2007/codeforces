#include <bits/stdc++.h>
using namespace std;

int t, n, mx[2];
string s;

string solve() {
    for (int i = 0; i < 10; i++) {
        int pl = -1, pr = n;
        string l = "", r = "", ans = "";
        bool chk = true;
        for (int j = 0; j < n; j++) {
            if (s[j] - '0' < i) {
                if (!l.empty() && l.back() > s[j]) {
                    chk = false;
                }
                l += s[j];
                pl = max(pl, j);
            } else if (s[j] - '0' > i) {
                if (!r.empty() && r.back() > s[j]) {
                    chk = false;
                }
                r += s[j];
                pr = min(pr, j);
            }
        }
        for (int j = 0; j < n; j++) {
            if (s[j] - '0' < i) {
                ans += "1";
            } else if (s[j] - '0' > i) {
                ans += "2";
            } else if (j > pl) {
                ans += "1";
            } else if (j < pr) {
                ans += "2";
            } else {
                chk = false;
            }
        }
        if (chk) {
            return ans;
        }
    }
    return "-";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--) {
        cin >> n >> s;
        cout << solve() << '\n';
    }
}