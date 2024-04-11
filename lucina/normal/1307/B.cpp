#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10 ;
int n, x, a[nax];
int solve () {
    scanf("%d %d", &n, &x);
    for (int i = 1 ; i <= n;  ++ i)
        scanf("%d", a + i);
    sort(a + 1 ,  a + 1 + n);
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] == x)
            return 1 ;
    }
    int ans = 0;
    return max(2, (x - 1) / a[n] + 1);
}

int main () {
    int T;
    for (cin >> T ; T -- ; printf("%d\n", solve()))
        ;
}
/*
    Good Luck
        -Lucina
*/