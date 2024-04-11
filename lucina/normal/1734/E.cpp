#include<bits/stdc++.h>
using namespace std;
const int nax = 512;
const int64_t INF = 1e17;
int n;
int b[nax];
int a[nax][nax];


void solve() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> b[i];
    }

    for (int i = 1 ; i <= n ; ++ i) {

        for (int j = 1, x = 0 ; j <= n ; ++ j) {
            x = (x + i) % n;
            a[i][j] = x;
        }
    }

    for (int j = 1 ; j <= n ; ++ j) {
        int d = -a[j][j] + b[j];
        for (int i = 1 ; i <= n ; ++ i) {
            a[i][j] = (a[i][j] + d + n) % n;
        }
    }

    for (int i = 1 ; i <= n ; ++ i, cout << '\n') {
        for (int j = 1 ; j <= n ; ++ j)
            cout << a[i][j] << ' ';
    }
    /**
        why is it important that n is a prime number?
        What if not?, Let's say n = 4

        x x x x
        x x x x
        x x x x
        x x x x
    */
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (T = 1; T -- ;) {
        solve();
    }
}