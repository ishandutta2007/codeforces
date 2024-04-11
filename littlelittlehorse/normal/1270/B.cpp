#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, k1, k2, m, a[200001];

int main() {
    scanf("%d", &test);
    for (; test--;) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        bool ok = false;
        for (int i = 1; i < n && !ok; i++)
            if (abs(a[i] - a[i + 1]) >= 2) {
                ok = true;
                printf("YES\n%d %d\n", i, i + 1);
            }
        if (!ok)
            printf("NO\n");
    }
}