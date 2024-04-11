#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);


    for (cin >> T ; T -- ;) {
        int n;
        string s;

        cin >> n >> s;

        int ans = 0;

        while (true) {
            int min_bal = 0, bal = 0;

            for (int i = 0 ; i < n; ++ i) {
                bal += s[i] == '(' ? 1 : -1;
                min_bal = min(min_bal, bal);
            }

            if (min_bal >= 0) break;
            ++ ans;
            int pos = -1;
            for (int i = n - 1 ; i >= 0 ;-- i) {
                if (s[i] == '(') {
                    pos = i;
                    break;
                }
            }

            string new_s;
            new_s += '(';

            for (int i = 0 ; i < n; ++ i) {
                if (i != pos) new_s += s[i];
            }

            s = new_s;
        }

        cout << ans << '\n';
    }
}