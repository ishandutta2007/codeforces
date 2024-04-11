#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int test, n, m, a[1001], b[1001];

int main() {
    scanf("%d", &test);
    for (; test--;) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        
        memcpy(b, a, sizeof(b));
        for (int i = 1; i <= m; i++) {
            bool ok = false;
            for (int j = 1; j <= n && !ok; j++)
                if (a[j])
                    for (int k = n; k && !ok; --k)
                            --a[j], ++a[k], ok = true;
            ok = false;
            for (int j = 1; j <= n; j++)
                if (a[j] < b[j]) {
                    ok = true;
                    break;
                } else
                    if (a[j] > b[j])
                        break;
            if (ok)
                memcpy(b, a, sizeof(b));
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", b[i]);
        printf("\n");
    }
}