#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
char s[nax];
int n;


void solve () {
    cin >> (s + 1);
    n = strlen(s + 1);

    if (n == 2) {
        cout << "0\n";
        return ;
    }

    int ans = 0;

    for (int i = 0 ; i < 10 ; ++ i) {
        int cur = 0;
        for (int j = 1 ; j <= n; ++ j) {
            if (s[j] - '0' == i) ++ cur;
        }
        ans = max(ans, cur);
    }

    for (int i = 0 ; i < 10 ; ++ i) {
    for (int j = 0 ; j < 10 ; ++ j) {
        int cur = 0;
        bool sw = true;
        int cur_want = i;
        for (int k = 1 ; k <= n ; ++ k) {
            if (s[k] - '0' == cur_want) {
                ++ cur;
                if (cur_want == i) cur_want = j;
                else cur_want = i;
                if (cur % 2 == 0) ans = max(ans, cur);
            }
        }
    }
    }

    cout << n - ans << '\n';

}

int main () {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    cin >> T;

    for (; T -- ; ) {
        solve();
    }
}
/*
    Good Luck
        -Lucina
*/