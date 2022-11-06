#include <bits/stdc++.h>

using namespace std;

int n, xo, yo, x, y, v;

int main() {

    scanf("%d %d %d", &xo, &yo, &n);

    double minTime = 1e9;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d %d", &x, &y, &v);
        double dist = sqrt((x - xo) * (x - xo) + (y - yo) * (y - yo));
        minTime = min(minTime, dist / v);
    }

    printf("%.10f\n", minTime);

    return 0;
}