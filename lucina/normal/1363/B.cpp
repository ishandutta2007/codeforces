#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

char s[nax];

int solve () {

    cin >> s + 1;

    int n = strlen(s + 1);

    int c0 = 0, c1 = 0;

    int ans = INT_MAX;

    int z = 0, o = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (s[i] == '0') ++ z;
        else ++ o;
    }

    for (int i = 1 ; i <= n ; ++ i) {

        if (s[i] == '0') ++ c0;
        else ++ c1;

        /// 1111 i 00000000

        ans = min(ans, c0 + (o - c1));

        ans = min(ans, c1 + (z - c0));
    }

    return ans;
}

int main () {

    int T;
    cin.tie(0)->sync_with_stdio(false);

    for (cin >> T  ; T -- ; ) {
        cout << solve() << '\n';
    }
}
/*
    Good Luck
        -Lucina
*/