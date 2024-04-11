#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   // freopen("input.txt", "r", stdin);
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
            cout << "ALICE\n";
        }
    }
    return 0;
}