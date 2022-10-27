#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
int a[nax], n;
int ss[nax];

void solve () {
    scanf("%d", &n);


    fill(ss + 1 , ss + 1 + n, 0);

    for (int i = 1 ; i <= n; ++ i) {
        scanf("%d", a + i);
        ss[a[i]] ++ ;
    }

    int all = 0;
    for (int i = 1 ; i <= n;  ++ i) {
        if (ss[i]) ++ all;
    }

    int ans = 0;

    for (int i = 1 ; i <= n ; ++ i) {
        if (ss[i] == 0) continue;
        if (all - 1 >= ss[i]) {
            ans = max(ans, ss[i]);
        } else {
            int has = ss[i] - all + 1;
            ans = max(ans, all - (has < 2));
        }
    }

    printf("%d\n", ans);
}

int main () {
    int T;

    for (cin >> T ; T -- ; ) {
        solve();
    }
}