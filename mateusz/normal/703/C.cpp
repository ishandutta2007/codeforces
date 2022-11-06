#include <bits/stdc++.h>

using namespace std;

int n, w, v, u, x, y;

int main() {

    scanf("%d %d %d %d", &n, &w, &v, &u);

    bool before = true;
    double minTime = 0.0;
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &x, &y);
        if ((long long)x * u < (long long)y * v) {
            before = false;
        }
        minTime = max(minTime, (double)x / v - (double)y / u);
    }
    if (before == true) {
        printf("%.10f\n", (double)w / u);
    } else {
        printf("%.10f\n", minTime + (double)w / u);
    }

    return 0;
}