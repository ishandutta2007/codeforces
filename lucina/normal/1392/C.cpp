#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n;
int a[nax];

void solve() {
    scanf("%d", &n);

    for (int i = 1 ; i <= n;  ++ i)
        scanf("%d", a + i);
    long long ans = 0;

    int from = a[n];

    for (int i = n - 1; i >= 1 ; -- i) {
        if (a[i] > from) {
            ans += a[i] - from;
            from = a[i];
        } else from = a[i];
    }
    printf("%lld\n", ans);
}

int main () {
    int T;
    scanf("%d", &T);
    while (T -- ) {
        solve();
    }
}
/**
    Try virtual.
*/