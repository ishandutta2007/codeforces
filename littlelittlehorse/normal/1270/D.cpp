#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, k, a[1001], c[1001];

int main() {
    memset(a, 0, sizeof(a));
  
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= k + 1; i++) {
        printf("?");
        for (int j = 1; j <= k + 1; j++)
            if (j != i)
                printf(" %d", j);
        printf("\n");
        fflush(stdout);
        int x, y;
        scanf("%d %d", &x, &y);
        ++a[x]; c[x] = y;
    }
    
    int xx = 1 << 30, cnt = 0;
    for (int i = 1; i <= k + 1; i++)
        if (a[i] && c[i] < xx)
            xx = c[i], cnt = a[i];
    printf("! %d\n", k + 1 - cnt);
    
}