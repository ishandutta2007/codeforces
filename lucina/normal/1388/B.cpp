#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n;

void solve() {
    scanf("%d", &n);
    int bk = n - (n - 1) / 4;

    for (int i = 1 ; i < bk ; ++ i) {
        putchar('9');
    }

    for (int i = bk ; i <= n ; ++ i)
        putchar('8');
    puts("");
}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }
}
/*
    Very hard game. :(
*/