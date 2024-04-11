#include<bits/stdc++.h>
using namespace std;

void solve () {
        int p[3];
        for (int i = 0 ; i < 3 ; ++ i) {
            cin >> p[i];
        }

        for (int x = 0 ; x < 3 ; ++ x)
        for (int y = 0 ; y < 3 ; ++ y)
        for (int z = 0 ; z < 3 ; ++ z) {
            int a = p[x], b = p[y], c = p[z];
            if (max(a, b) == p[0] && max(a, c) == p[1] && max(b, c) == p[2]) {
                cout << "YES" << '\n';
                cout << a << ' ' << b << ' ' << c << '\n';
                return ;
            }
        }

        cout << "NO" << '\n';

}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t -- ) {
            solve();
    }

}