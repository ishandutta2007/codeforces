#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, m;
char x[150][150];

void solve () {
    scanf("%d %d", &n, &m);

    for (int i = 1 ; i <= n ; ++ i) {
        for (int j = 1 ; j <= m ; ++ j) {
            if ((i + j) & 1) x[i][j] = 'W';
            else x[i][j] = 'B';
        }
    }

    bool found = false;
    if (n * m % 2 == 0)
    for (int i = 1 ; i <= n ; ++ i) {
        if (x[i][m] == 'W') {
            x[i][m] = 'B';
            found = true;
            break;
        }
    }

   // assert(found);

    for (int i = 1 ; i <= n ; ++ i, printf("\n"))
        for (int j = 1 ; j <= m ; ++ j) {
            printf("%c", x[i][j]);
    }
}

int main () {
    int T;

    for (cin >> T ; T --  ; ) {
        solve();
    }

}
/**
    Good Luck
        -Lucina
*/