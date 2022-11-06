#include <bits/stdc++.h>

using namespace std;

int n, m;

int main() {

    scanf("%d %d", &n, &m);

    if (n == 1 && m == 1) {
        printf("1\n");
        return 0;
    }

    if (2 * m > n) {
        printf("%d\n", m - 1);
    } else {
        printf("%d\n", m + 1);
    }

    return 0;
}