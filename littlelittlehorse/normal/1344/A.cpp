#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[200001], b[200001];

int main() {
    scanf("%d", &test);
    for ( ; test--; ) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        for (int i = 0; i < n; i++)
            b[i] = 0;
        bool ok = true;
        for (int i = 0; i < n && ok; i++) {
            int x = i + a[i];
            if (x >= 0)
                x %= n;
            else {
                x = abs(x) % n;
                if (x)
                    x = n - x;
            }
            if (b[x])
                ok = false;
            b[x] = 1;
        }
        if (ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
}