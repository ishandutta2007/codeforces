#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 +  10 ;

int main () {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    for( cin >> T ; T -- ; ) {
        auto solve = [&] ( ) {
        string a, b, c;
        cin >> a >> b >> c;
        int n = a.length();
        for (int i = 0 ; i < n; i ++) {
            if (a[i] == b[i]) {
                if (c[i] != a[i])
                    return false;
            }
            if (! (c[i] == a[i] || c[i] == b[i])) return false;
        }
        return true;
        };
        if (solve()) {
            cout << "Yes\n";
        }
        else cout << "No\n";
    }

}
/*
    Good Luck
        -Lucina
*/