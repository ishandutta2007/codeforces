#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
char s[nax];
int alt_lft[nax];
int alt_rg[nax];

void solve() {
    cin >> n >> s;

    for (int i = 0 ; i < n ; ++ i) {
        int j = i;
        while (j + 1 < n && s[j + 1] != s[j]) ++ j;

        for (int k = i ; k <= j ; ++ k) alt_rg[k] = j - k + 1;
        i = j;
    }

    for (int i = n - 1 ; i >= 0 ; -- i) {
        int j = i;
        while (j > 0 && s[j - 1] != s[j]) -- j;
        for (int k = i ; k >= j ; -- k) alt_lft[k] = k - j + 1;
        i = j;
    }
/*
    for (int i = 0 ; i < n ; ++ i) {
        cout << alt_lft[i] << ' ';
    }

    cout << '\n';
    for (int i = 0 ; i < n; ++ i) {
        cout << alt_rg[i] << ' ';
    }
    cout << '\n';
*/

    cout << ((s[0] == 'R') ? alt_rg[0] : 0) + 1 << ' ';

    for (int i = 0 ; i < n - 1  ; ++ i) {
        int bar = (s[i + 1] == 'R') ? alt_rg[i + 1] : 0;
        bar += (s[i] == 'L') ? alt_lft[i] : 0;
        bar += 1;
        cout << bar << ' ';

    }
    cout << ((s[n - 1] == 'L') ? alt_lft[n - 1] : 0) + 1 << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}