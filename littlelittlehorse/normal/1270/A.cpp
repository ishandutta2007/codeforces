#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, k1, k2, m;

int main() {
    scanf("%d", &test);
    for (; test--;) {
        scanf("%d%d%d", &n, &k1, &k2);
        bool ok = true;
        for (int i = 1; i <= k1; i++) {
            int x;
            scanf("%d", &x);
        }
        for (int i = 1; i <= k2; i++) {
            int x;
            scanf("%d", &x);
            if (x == n)
                ok = false;
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}