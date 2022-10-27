#include<bits/stdc++.h>
using namespace std;

int n;

void solve() {
    cin >> n;

    for (int a = 0 ; 3 * a <= n ; ++ a)
    for (int b = 0 ; 5 * b + 3 * a <= n ; ++ b) {
        int res = n - 5 * b - 3 * a;
        if (res % 7 == 0) {
            cout << a << ' ' << b << ' ' << res / 7 << '\n';
            return ;
        }
    }
    cout << "-1\n";
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}