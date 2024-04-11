#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, a[1001];

int main() {
    scanf("%d", &test);
    for (; test--; ) {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            int x;
            scanf("%d", &x);
            if (i & 1)
                printf("%d ", abs(x));
            else
                printf("%d ", -abs(x));
        }
        printf("\n");
    }
}