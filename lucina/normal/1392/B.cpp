#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;

int main () {
    int T;

    scanf("%d", &T);
    while (T -- ) {
        int n;
        static int b[nax];
        static pair <int, int> a[nax];
        long long k;
        scanf("%d %lld", &n, &k);
        for (int i = 1 ; i <= n;  ++ i) {
            scanf("%d", b + i);
            a[i] = make_pair(b[i], i);
        }

        sort(b + 1, b + 1 + n);
        sort(a + 1, a + 1 + n);


        static int res[nax];
        if (k % 2) {
            for (int i = 1 ; i <= n ; ++ i)
                res[i] = b[n] - b[i];
        } else
            for (int i = 1 ; i <= n; ++ i)
                res[i] = b[i] - b[1];
        for (int i = 1 ; i <= n; ++ i)
            b[a[i].second] = res[i];

        for (int i = 1 ; i <= n ; ++ i) {
            printf("%d ", b[i]);
        }
        puts("");
    }
}
/**
    Try virtual.
*/