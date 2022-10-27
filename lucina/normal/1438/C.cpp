#include<bits/stdc++.h>
using namespace std;
int const nax = 128;
int a[nax][nax];
int b[nax][nax];

void solve() {
    int n, m;

    cin >> n >> m;

    for (int i = 1 ; i <=  n ; ++ i, cout << '\n')
    for (int j = 1 ; j <= m ; ++ j) {
        int x;
        cin >> x;
        if (x % 2 != (i + j) % 2) ++ x;
        cout << x << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
   // cout << "ANS\n";

    for (cin >> T ; T -- ;) {
        solve();
    }
}