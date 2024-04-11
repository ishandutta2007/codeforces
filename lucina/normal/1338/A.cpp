#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long ;
int n;
int a[nax];
int b[nax];

int first_bit (int x) {
    return x == 0 ? 0 : 31 - __builtin_clz(x);
}

int solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", b + i);
    }

    for (int k = 0 ; k <= 60 ; ++ k) {
        for (int i = 1 ; i <= n ; ++ i)
            a[i] = b[i];


        bool ok = true;

        for (int i = 2 ; i <= n;  ++ i) {
            if (a[i] < a[i - 1]) {
                int ret = first_bit(a[i - 1] - a[i]);
                if (ret > k - 1) {
                    ok = false;
                }
                a[i] = a[i - 1];
            }
        }

        if (ok) return k;
    }

    throw;
}

int main () {
    int T;

    for (cin >> T ; T -- ;) {
        printf("%d\n", solve());
    }
}
/*
    Good Luck
        -Lucina
*/