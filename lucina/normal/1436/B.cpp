#include<bits/stdc++.h>
using namespace std;
int const nax = 128;
int n;
int a[nax][nax];

bool is_prime(int x) {
    if (x <= 1) return false;
    for (int i = 2 ; i * i <= x ; ++ i) {
        if (x % i == 0) return false;
    }
    return true;
}


void solve() {
    cin >> n;
    for (int i = 1 ; i < n ; ++ i)
    for (int j = 1 ; j < n ; ++ j) {
        a[i][j] = 1;
    }

    int bar;
    int foo = n;
    while (true) {
        while (!is_prime(foo)) {
            foo ++;
        }
        bar = foo - n + 1;
        if (!is_prime(bar)) break;
        foo ++;
    }

    assert(bar > 0);

    for (int i = 1 ; i < n ; ++ i)
        a[n][i] = a[i][n] = bar;
    foo = a[n][1] * (n - 1) + 1;
    while (true) {
        while (!is_prime(foo)) ++ foo;
        bar = foo - a[n][1] * (n - 1);
        if (!is_prime(bar)) break;
        foo++;
      //  cout << "FOO " << foo << '\n';
    }
    a[n][n] = bar;

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ;j  <= n ; ++ j)
            cout << a[i][j] << ' ';
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