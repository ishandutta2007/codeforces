#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int n, a[nax];


int solve () {

    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i)
        scanf("%d", a + i);

    sort(a + 1, a + 1 + n);

    int mx = 0;

    for (int i = 1 ; i <= n ; ++ i) {

        if (i >= a[i])
            mx = i;
    }

    return mx + 1;
}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        printf("%d\n", solve());
    }
}
/*
    Long time no see...
        CF round
*/