#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n, p[nax], c[nax];

bool solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i ) {
        scanf("%d %d", p + i, c + i);

    }

    for (int i = 1 ; i <= n ; ++ i) {
        if (p[i] < c[i]) return false;
    }

    for (int i = 2 ; i <= n ; ++ i) {
        if (c[i] < c[i - 1] || p[i] < p[i - 1]) return false;
        int add = p[i] - p[i - 1];
        if (add < c[i] - c[i - 1]) return false;
    }

    return true;
}

int main () {

    int  T ;
    for (cin >>  T ; T -- ; ) {
        puts(solve() ? "YES" : "NO");
    }




}
/*
    Good Luck
        -Lucina
*/