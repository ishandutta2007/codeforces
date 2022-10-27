#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10 ;
int n  ,a [nax], d;
int solve () {
    scanf("%d %d", &n, &d);
    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);
    for (int j = 1 ; j <= d ; ++ j) {
        for (int i = 2 ; i <= n ; i ++) {
            if (a[i] > 0) {
                a[i - 1] ++;
                a[i] --;
                break;
            }
        }
    }
    return a[1];
}

int main () {
    int T;
    for (cin >> T ; T -- ; ) {
        printf("%d\n", solve());
    }
}
/*
    Good Luck
        -Lucina
*/