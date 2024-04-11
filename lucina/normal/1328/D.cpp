#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int n , a[nax], c[nax], k;

void print_ans () {
    printf("%d\n", k);
    for (int i = 1 ; i <= n;  ++ i)
        printf("%d ", c[i]);
    puts("");
}

void solve () {
    scanf("%d", &n);

    for (int i = 1 ; i <= n ; ++ i) {
        scanf("%d", a + i);
    }

    a[n + 1] = -1;
    int large = -1;
    k = 1;

    int huh = n;

    for (; a[huh] == a[1] ; -- huh);
    ++ huh;
    if (huh == 1) {
        fill(c + 1, c + 1 + n, 1);
        k = 1;
        return print_ans();
    }

    int new_n = huh - 1;

    k = 2;

    c[0] = 2;

    for (int v = new_n + 1 ; v <= n ; ++ v)
        c[v] = 1;

    for (int i = 1 , j = 1; i <= new_n ; i = j + 1) {

        for (j = i ; j <= new_n && a[i] == a[j] ; ++ j);
        -- j;

        if (j - i + 1 >= 2 || (i == 1 && new_n < n)) large = j;

        if (j == new_n) {
            int to_col = 3 - c[i - 1];
            if (to_col != c[1]) {
                for (int v = i ; v <= j ; ++ v)
                    c[v] = to_col;

            } else if (j - i + 1 >= 2) {
                for (int v = i ; v < j ; ++ v)
                    c[v] = to_col;
                c[j] = 3 - to_col;
            } else if (large != -1) {
                for (int v = i ; v <= j ; ++ v)
                    c[v] = to_col;
                for (int v = large ; v <= j ; ++ v) {
                    c[v] = 3 - c[v];
                }
            }  else {
                k = 3;
                for (int v = i ; v <= j ; ++ v)
                    c[v] = 3;
            }

        } else {
            for (int v = i ; v <= j ; ++ v) {
                c[v] = 3 - c[i - 1];
            }
        }
    }

    return print_ans();
}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; ) {
        solve();
    }


}