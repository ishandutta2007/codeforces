#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ; ) {
        int l, r;
        cin >> l >> r;
        if (2 * l <= r) {
            cout << l << ' ' << 2 * l << '\n';
        } else cout << "-1 -1\n";
    }
}
/*
    Good Luck
        -Lucina
*/