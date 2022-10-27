#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    int z;
    cin >> n;
    int ans = 0;
    int lst = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        if (a[i] == 0 && lst != 0) {
            ans ++;
            lst = 0;
        }
        lst = a[i];
    }
    if (lst) ans ++;
    cout << min(ans, 2) << '\n';
}


int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/**
    ....Global round....
*/