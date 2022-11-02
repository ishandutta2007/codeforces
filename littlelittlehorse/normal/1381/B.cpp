#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[4001], m, c[4001], f[4001];
bool b[4001];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n + n; i++)
            scanf("%d", &a[i]);
        m = 0;
        memset(b, false, sizeof(b));
        for (int i = 1; i <= n + n; i++)
            if (!b[i]) {
                c[++m] = 1; b[i] = true;
                for (int j = i + 1; j <= n + n; j++)
                    if (a[j] > a[i])
                        break;
                    else
                        ++c[m], b[j] = true;
            }
        memset(f, 0, sizeof(f));
        f[0] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = n - c[i]; j >= 0; --j)
                if (f[j])
                    f[j + c[i]] = 1;
        if (f[n])
            printf("YES\n");
        else
            printf("NO\n");
    }
        
}