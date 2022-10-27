#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, m;
int a[nax];

void solve() {
    cin >> n >> m;
    /**
        max number can be anything
    */
    if (n == 1) {
        cout << "YES\n";
        cout << m << '\n';
        return;
    }
    if (m < n) {
        cout << "NO\n";
        return;
    }
    if (m == n) {
        cout << "YES\n";
        for (int i = 1 ; i <= n ; ++ i) cout << 1 << ' ';
        cout << '\n';
        return;
    }
    if (n % 2 == 1) {
        cout << "YES\n";
        for (int i = 1 ; i < n ; ++ i) cout << 1 << ' ', m -= 1;
        cout << m << '\n';
        return;
    }
    if (m % 2) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1 ; i <= n - 2 ; ++ i) cout << 1 << ' ';
    cout << (m - n + 2) / 2 << ' ' << (m - n + 2) / 2 << '\n';

}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}
/*
    combined round~
    which faces?
    :D ? :E ? :O ? X<
*/