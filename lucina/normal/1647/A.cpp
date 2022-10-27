#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;

void solve() {
    cin >> n;

    if (n % 3 == 0) {
        for (int i = 1 ; i <= n / 3 ; ++ i)
            cout << "21";
        cout << '\n';
    } else {
        for (int s = 0, f = 1 + (n % 3 != 1); s < n ;) {
            cout << f;
            s += f;
            f = 3 - f;
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}