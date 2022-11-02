#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int test, n, m, a[100001];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d%d", &n, &m);
        int Max = 0, Min = 1 << 30, pa = 0, pi = 0;
        bool ok = false;
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            if (a[i] == m)
                ok = true;
            if (a[i] > Max)
                Max = a[i];
        }
        if (!ok)
            printf("no\n");
        else
            if (n == 1)
                printf("yes\n");
            else {
                    for (int i = 1; i <= n; i++)
                        if (a[i] >= m)
                            a[i] = m;
                    ok = false;
                    for (int i = 1; i < n && !ok; i++) {
                        if (a[i] == m && a[i + 1] == m)
                            ok = true;
                        if (i + 2 <= n && a[i] == m && a[i + 2] == m)
                            ok = true;
                    }
                    if (ok)
                        printf("yes\n");
                    else
                        printf("no\n");
                }
    }
}