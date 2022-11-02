#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[1000001], c[1000001];
bool b[1001];

bool check() {
    for (int i = 0; i < n; i++)
        b[i] = false;
    for (int i = 1; i <= n; i++)
        b[a[i]] = true;
    for (int i = 0; i < n; i++)
        if (!b[i])
            return false;
    return true;
}

int meg() {
    for (int i = 0; i <= n; i++)
        b[i] = false;
    for (int i = 1; i <= n; i++)
        b[a[i]] = true;
    for (int i = 0; i <= n; i++)
        if (!b[i]) 
            return i;
}

bool de() {
    for (int i = 1; i < n; i++)
        if (a[i] > a[i + 1])
            return false;
    return true;
}

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        int cnt = 0;
        for ( ; !de(); ) {
            int v = meg(), pos = v + 1;
            if (v == n) 
                for (int i = 1; i <= n; i++)
                    if (a[i] != i - 1) {
                        pos = i;
                        break;
                    }
             c[++cnt] = pos;
             a[pos] = v;
        }
        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i++)
            printf("%d ", c[i]);
        printf("\n");
    }
}