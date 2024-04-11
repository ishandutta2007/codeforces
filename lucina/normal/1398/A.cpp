#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;



int main () {
    int T;
    for (cin >> T ; T -- ;) {
        int n;
        static int a[nax];

        scanf("%d", &n);
        for (int i = 1 ; i <= n ; ++ i)
            scanf("%d", a + i);

        if (a[n] >= a[1] + a[2]) {
            printf("1 2 %d\n", n);
        } else puts("-1");
    }
}