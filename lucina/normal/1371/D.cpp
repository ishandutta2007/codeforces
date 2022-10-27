#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, k;
int a[304][304];

int sq (int x) {
    return x * x;
}

void solve() {
    cin >> n >> k;

    memset(a, 0, sizeof(a));

    int start = 0;

    while (true) {
        int tar = min(n, k);
        k -= tar;
        int x = start, y = 0;

        for (int i = 0 ; i < tar ; ++ i) {
            a[x][y] = 1;
            ++ x; ++ y;
            x %= n;
            y %= n;
        }

        if (k == 0) break;
        ++ start;
    }

    int max_c = 0, min_c = INT_MAX, max_r = 0,  min_r = INT_MAX;

    for (int i = 0 ; i < n ; ++ i) {
        int sum = 0;
        for (int j = 0  ; j < n ; ++ j)
            sum += a[i][j];
        max_r = max(max_r, sum);
        min_r = min(min_r, sum);
    }

    for (int j = 0 ; j < n;  ++ j) {
        int sum = 0;
        for (int i = 0 ; i < n ; ++ i)
        sum += a[i][j];
        max_c = max(max_c, sum);
        min_c = min(min_c, sum);
    }

    cout << sq(max_c - min_c) + sq(max_r - min_r) << '\n';

    for (int i = 0 ; i < n; ++ i, cout << '\n')
    for (int j = 0 ; j < n; ++ j) {
        cout << a[i][j];
    }
}

int main () {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}
/*
    Song of leaving home.
*/