#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
const string need = "abacaba";
char s[nax];
char t[nax];
int n;

bool try_replace (int i) {
    for (int j = 1 ; j <= n; ++ j)
        t[j] = s[j];
    for (int j = 0 ; j < 7 ; ++ j)
        t[i + j] = need[j];
    for (int j = 1 ; j <= n;  ++ j)
        if (t[j] == '?') t[j] = 'z';

    int valid_count = 0;

    for (int j = 1 ; j + 6 <= n ; ++ j) {
        bool valid = true;
        for (int v = 0; v < 7 ; ++ v)
            valid &= (t[j + v] == need[v]);
        valid_count += valid ? 1 : 0;
    }
    t[n + 1] = '\0';


    if (valid_count == 1) {
        cout << "Yes\n";
        cout << t + 1 << '\n';
        return true;
    }
    return false;
}

void solve () {
    cin >> n >> s + 1;

    for (int i = 1 ; i + 6 <= n ; ++ i) {
        bool valid = true;
        for (int j = 0 ; j < 7 ; ++ j) {
            valid &= (s[i + j] == need[j] || s[i + j] == '?');
        }

        if (valid)
            if (try_replace(i)) return;
    }

    cout << "No\n";
}

int main () {
    int T;
    cin.tie(0)->sync_with_stdio(false);
    for ( cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    not ryza again.
*/