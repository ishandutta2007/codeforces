#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
char s[nax];


int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ; ) {
        cin >> (s + 1);
        int n = strlen(s + 1);
        vector <int> bk;
        for (int i = 1 ; i <= n ; ++ i) {
            if (s[i] == '1') {
                int c = 0;
                while (i <= n && s[i] == '1') ++ i, ++ c;
                bk.push_back(c);
                -- i;
            }
        }

        int ans = 0;
        sort(bk.begin(), bk.end());

        while (!bk.empty()) {
            ans += bk.back();
            bk.pop_back();
            if (!bk.empty()) bk.pop_back();
        }

        cout << ans << '\n';
    }
}