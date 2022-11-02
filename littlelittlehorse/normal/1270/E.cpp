#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int n, a[1001][3];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d%d", &a[i][0], &a[i][1]);
    
    for (;;) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1; i <= n; i++)
            if ((a[i][0] + a[i][1]) & 1)
                ++cnt1;
            else
                ++cnt2;
        if (cnt1 != n && cnt1 > 0) {
            printf("%d\n", cnt1);
            for (int i = 1; i <= n; i++)
                if ((a[i][0] + a[i][1]) & 1)
                    printf("%d ", i);
            printf("\n");
            break;
        }
        for (int i = 1; i <= n; i++) {
            int x = a[i][0] + a[i][1], y = a[i][1] - a[i][0];
            if (x & 1)
                --x;
            if (y & 1)
                --y;
            a[i][0] = x / 2; a[i][1] = y / 2;
        }
    }   
}