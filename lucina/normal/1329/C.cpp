#include<bits/stdc++.h>
using namespace std;
int const nax = (1 << 20) + 101;

int h, g;

int path[25], a[nax];

int pull (int v) {
    int res = a[v];
    a[v] = 0;

    int top = 0;
    path[++ top] = v;

    while (v * 2 < (1 << h) && a[v] < max(a[v * 2], a[v * 2 + 1])) {
        if (a[v * 2] > a[v * 2 + 1]) {
            swap(a[v], a[v * 2]);
            v = v * 2;
        } else {
            swap(a[v], a[v * 2 + 1]);
            v = v * 2 + 1;
        }

        path[++ top] = v;
    }


    if (v < (1 << g)) {
        ///we failed to go down
        for (int i = top ; i >= 1 ; -- i)
            a[path[i]] = a[path[i - 1]];
        a[path[1]] = res;
        return 0;
    }

    return res;
}

int to_print[nax];


void solve () {
    scanf("%d %d", &h, &g);

    long long ans = 0;

    for (int i = 1 ; i < (1 << h) ; ++ i) {
        scanf("%d", a + i);
        ans += a[i];
    }

    int top = 0;
    for (int i = 1 ; i < (1 << h) ; ++ i) {
        while (true) {
            int c = pull(i);
            if (c > 0) {
                ans -= c;
                to_print[++ top] = i;
            } else break;
        }
        if (top == (1 << h) - (1 << g)) break;
    }

    printf("%lld\n", ans);
    for (int i = 1 ; i <= top ; ++ i) printf("%d ", to_print[i]);
    printf("\n");

}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ; solve()) {

    }
}
/*
    Good Luck
        -Lucina
*/