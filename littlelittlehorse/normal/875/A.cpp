#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[101];

int main() {
    scanf("%d", &n);
    int cnt = 0;
    for (int i = 1; i <= 100; i++)
        if (n >= i)
        {
            int m = n - i, k = m;
            for (; m; m /= 10)
                k += m % 10;
            if (k == n)
                a[++cnt] = n - i;
        }
    sort(a + 1, a + cnt + 1);
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; i++)
        printf("%d\n", a[i]);
}