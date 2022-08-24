#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t = s;
        reverse(s.begin(), s.end());
        int cnt0 = 0;
        for (char& c : s) cnt0 += (c == '0');
        if (s == t) {
            if (cnt0 == 1 || (n % 2 == 0) || s[n / 2] == '1') {
                cout << "BOB\n";
            }
            else {
                cout << "ALICE\n";
            }
        }
        else {
            int cnt_dif = 0;
            int zer = 0;
            for (int i = 0; i < n - i - 1; i++) {
                if (s[i] != s[n - i - 1]) cnt_dif++;
                if (s[i] == '0' && s[i] == s[n - i - 1]) zer++;
            }
            bool has = false;
            if (n % 2 == 1 && s[n / 2] == '0') has = true;
            if (cnt0 == 1) {
                cout << "ALICE\n";
                continue;
            }
            if (!has) {
                cout << "ALICE\n";
                continue;
            }
            else {
                if (cnt_dif == 1 && !zer) {
                    cout << "DRAW\n";
                }
                else {
                    cout << "ALICE\n";
                }
            }
        }
    }
    return 0;
}