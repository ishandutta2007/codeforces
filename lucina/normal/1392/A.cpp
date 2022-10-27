#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int main () {
    int T;
    scanf("%d", &T);

    while (T -- ) {
        int n;
        static int a[nax];
        scanf("%d", &n);
        for (int i = 1 ; i <= n; ++ i)
            scanf("%d", a + i);
        int x = a[1];

        bool same = true;

        for (int i = 1 ; i <= n;  ++ i)
            same &= a[i] == x;
        if (same) printf("%d\n", n);
        else puts("1");
    }
}
/**
    Try virtual.
*/