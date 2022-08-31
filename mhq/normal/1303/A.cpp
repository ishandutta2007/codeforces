#include <bits/stdc++.h>

using namespace std;

int main() {
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        string s;
        cin >> s;
        int fi = -1;
        int lst = -1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                if (fi == -1) fi = i;
                lst = i;
            }
        }
        if (fi == -1) cout << 0 << '\n';
        else {
            int cnt = 0;
            for (int i = 0; i < s.size(); i++) {
                if (fi <= i && i <= lst && s[i] == '0') cnt++;
            }
            cout << cnt << '\n';
        }
    }
    return 0;
}