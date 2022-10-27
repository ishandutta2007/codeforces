#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T ; T -- ;) {
        string s;
        cin >> s;
        int one = 0, zero = 0;
        for (int i = 0 ; i < (int)s.size();  ++ i) {
            if (s[i] == '1') ++ one;
            else ++ zero;
        }

        int tot = min(one, zero);
        cout  << ((tot) % 2 ? "DA" : "NET") << '\n';
    }
}
/*
    Sue is best girl in A19.
*/