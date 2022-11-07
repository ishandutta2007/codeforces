#include <bits/stdc++.h>

using namespace std;

const int X = 400;

int zmiany[2][X];
int n, a, b;
char kto;

int main() {

    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        scanf(" %c %d %d", &kto, &a, &b);
        if (kto == 'F')
            kto = 1;
        else kto = 0;
        zmiany[kto][a]++;
        zmiany[kto][b + 1]--;
    }

    int ans = 0;
    int man = 0, woman = 0;
    for (int i = 1; i <= 366; i++) {
        man += zmiany[0][i];
        woman += zmiany[1][i];
            ans = max(ans, 2 * min(woman, man));
    }
    printf("%d\n", ans);
    return 0;
}