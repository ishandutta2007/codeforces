#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
int b[nax];

void solve() {
    cin >> n;

    int t = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        t ^= a[i];
    }

    if (t == 0) {
        cout << "DRAW\n";
        return ;
    }

    int mx_bit = 0;

    for (int j = 0 ; j < 31 ; ++ j) {
        if (t >> j & 1) mx_bit = j;
    }

    int x = 0, y = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] >> mx_bit & 1) ++ x;
        else ++ y;
    }

    assert(x + y > 0);

    bool result = (((x + 1) / 2) % 2) ? true : false;
    if (result) {
        cout << "WIN\n";
        return ;
    }

    cout << (y % 2 == 0 ? "LOSE" : "WIN") << '\n';
}


int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/