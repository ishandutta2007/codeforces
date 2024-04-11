#include<bits/stdc++.h>
using namespace std;
int const nax = 1010;
int n, x;

bool solve() {

    /// true if first player win

    scanf("%d %d", &n, &x);

    int cx = 0;

    for (int i = 1 ; i < n ; ++ i) {
        int u, v;
        scanf("%d %d", &u, &v);

        if (u == x) cx ++ ;
        if (v == x) cx ++;
    }

    if (n == 1) return true;

    if (cx == 1) return true;

    return (n + 1) % 2 ? true : false;

}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ;) {
        puts(solve() ? "Ayush" : "Ashish");

    }
}
/*
    Good Luck
        -Lucina
*/