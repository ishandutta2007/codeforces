#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;

int nice_prime[11] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
int c[nax], n, a[nax];


int main () {
    int T;

    for (scanf("%d", &T) ; T --; ) {
        scanf("%d", &n);

        vector<int> g[12];
        for (int i = 1 ; i <= n; ++ i) {
            int x;
            scanf("%d", &x);

            bool found = false;
            for (int v = 0 ; v < 11 ; ++ v) {
                if (x % nice_prime[v] == 0) {
                    g[v].push_back(i);
                    found = true;
                    break;
                }
            }
            if (!found) throw;
        }

        int cur = 1;

        for (int v = 0 ; v < 11 ; ++ v) {
            if (g[v].empty()) continue;

            for (int i : g[v])
                c[i] = cur;

            ++ cur;
        }

        printf("%d\n", cur - 1);
        for (int i = 1 ; i <= n; ++ i)
            printf("%d " , c[i]);
        printf("\n");
    }
}
/*
    Good Luck
        -Lucina
*/