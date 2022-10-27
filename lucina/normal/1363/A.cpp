#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;
int a[nax];
int x;

bool solve() {
    scanf("%d %d", &n, &x);

    int o = 0, e = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
        if (a[i] % 2) ++ o;
        else ++ e;
    }

    o = min(o, x);
    e = min(e, x);

    if (o == 0) return false;

    if (o % 2 == 0) -- o;

    if (o + e >= x) return true;
    else return false;

}


int main () {

    int T;

    for (scanf("%d", &T) ; T -- ;) {
        puts(solve() ? "Yes" : "No");
    }
}
/*
    Good Luck
        -Lucina
*/