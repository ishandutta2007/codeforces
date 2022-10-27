#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int  n, x;

int main () {
    int T;
    for (scanf("%d", &T) ; T -- ;) {
        set<int> s;
        scanf("%d", &n);
        for (int i = 1 ; i <= n;  ++ i) {
            scanf("%d", &x);
            s.insert(x);
        }
        printf("%d\n", (int)s.size());
    }
}
/*
    Good Luck
        -Lucina
*/