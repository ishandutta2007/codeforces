#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int l(int x) {
    return to_string(x).size();
}

void solve() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        for (int i = n - 2 ; i >= 1 ; -- i) cout << i << ' ';
        cout << n - 1 << ' ' << n << '\n';
        return ;
    }
    for (int i = n - 2 ; i > 3 ; -- i) cout << i << ' ';
    cout << "1 2 3 " << n - 1 << ' ' << n << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}