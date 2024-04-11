#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

char s[12][12];

void solve () {
    for (int i = 1 ; i <= 9 ; ++ i)
        scanf("%s", s[i] + 1);
    s[1][1] = s[1][2];
    s[4][2] = s[4][3];
    s[7][3] = s[7][2];

    s[2][4] = s[2][5];
    s[5][5] = s[5][6];
    s[8][6] = s[8][5];

    s[3][7] = s[3][8];
    s[6][8] = s[6][9];
    s[9][9] = s[9][8];

   // puts("");

    for (int i = 1 ; i <= 9 ; ++ i)
        puts(s[i] + 1);
}

int main () {
    int T;

    scanf("%d", &T);

    for ( ; T -- ;) {

        solve();
    }
}