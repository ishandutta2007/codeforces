#include<bits/stdc++.h>
using namespace std;
const int nax = 512;
int n, m;
int a[nax][nax];
int b[nax][nax];
char f[nax];

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= n ; ++ i) {
        cin >> f + 1;
        for (int j = 1 ; j <= m ; ++ j)
            a[i][j] = f[j] == 'B';
    }
    int ans = 0;
    for (int i = n ; i >= 1 ; -- i)
    for (int j = m ; j >= 1 ; -- j) {
        b[i][j] = (a[i][j] + a[i + 1][j] + a[i][j + 1] + a[i + 1][j + 1]) & 1;
        if (b[i][j]) ans += 1;
    }

    int found = 0;
    for (int i = n - 1 ; i >= 1 ; -- i)
    for (int j = m - 1 ; j >= 1 ; -- j) {
        if (b[i][j] && b[n][j] && b[i][m] && b[n][m]) found = 1;
    }
    cout << ans - found << '\n';
}
/**
    Only operation 1 and 3 make sense.
    If two or more 3 were done, we can replace it with operations of type 1
    Nice trick is to modify grid a little bit such that O(1) changes occur per operation
    One such way is to take xor sum of (2x2) frame and only corner changes value
*/

/*
    Well, such a long time from last div.2 round
*/