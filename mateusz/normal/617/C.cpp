#include <bits/stdc++.h>

using namespace std;

const int N = 2005;

int n, xA, xB, yA, yB;
int x[N], y[N], tab[N];

bool cmp(int a, int b) {
    return (long long)(xA - x[a]) * (xA - x[a]) + (long long)(yA - y[a]) * (yA - y[a]) <
           (long long)(xA - x[b]) * (xA - x[b]) + (long long)(yA - y[b]) * (yA - y[b]);
}

int main() {

    scanf("%d %d %d %d %d", &n, &xA, &yA, &xB, &yB);

    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x[i], &y[i]);
    }

    for (int i = 1; i <= n; i++) {
        tab[i] = i;
    }

    sort(tab + 1, tab + 1 + n, cmp);

    long long ans = 1e18;
    long long d2 = 0;
    x[0] = xA, y[0] = yA;
    for (int i = n; i >= 0; i--) {
        long long d1 = (long long)(xA - x[tab[i]]) * (xA - x[tab[i]]) + (long long)(yA - y[tab[i]]) * (yA - y[tab[i]]);
        ans = min(ans, d1 + d2);
        d2 = max(d2, (long long)(xB - x[tab[i]]) * (xB - x[tab[i]]) + (long long)(yB - y[tab[i]]) * (yB - y[tab[i]]));
    }

    printf("%I64d\n", ans);
    return 0;
}