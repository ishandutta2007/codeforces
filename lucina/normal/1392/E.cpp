#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
long long f[35][35];
int n, q;

void construct_grid() {

    for (int i = 2 ; i <= n ; i += 2)
    for (int j = 1 ; j <= n ; ++ j) {
        f[i][j] = 1LL << (i + j);
    }
}

void output() {
    for (int i = 1; i <= n; ++ i) {
        for (int j = 1 ;j <= n ;++ j) {
            cout << f[i][j] << ' ';
        }
        cout << '\n';
    }

    cout.flush();
}

void backtrack() {
    long long k;
    cin >> k;
    int x = 1, y = 1;
    vector <pair <int, int>> path;

    do {
        cout << x << ' ' << y << '\n';

        if (x == n) {
            y += 1;
        } else if (y == n) {
            x += 1;
        } else {
            if (f[x + 1][y] & k) {
                x += 1;
            } else if (f[x][y + 1] & k) {
                y += 1;
            } else {
                if (f[x + 1][y] == 0) x += 1;
                else y += 1;
            }
        }
    } while (make_pair(x, y) != make_pair(n, n));
    cout << x << ' ' << y << '\n';
    cout.flush();
}

int main () {
    cin.tie(0)->sync_with_stdio(false);


    cin >> n;
    construct_grid();
    output();
    cin >> q;

    while (q --) backtrack();
}
/**
    Try virtual.
*/