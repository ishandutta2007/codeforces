#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

void solve() {
    int n;
    cin >> n;

    if (n <= 2) {
        cout << (n == 1 ? "9" : "98") << '\n';
        return ;
    }

    int cur = 9;

    /**
    989xxxx is optimal
    seems like I have been away from CP for too long...
    */

    cout << 98;
    int foo = 9;

    for (int i = 3 ; i <= n ; ++ i) {
        cout << foo++;
        foo %= 10;
    }
    cout << '\n';


}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}