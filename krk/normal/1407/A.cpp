#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n;
int zers, ones;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        zers = ones = 0;
        for (int i = 0; i < n; i++) {
            int a; scanf("%d", &a);
            if (a == 0) zers++;
            else ones++;
        }
        if (zers >= ones) {
            printf("%d\n", zers);
            for (int i = 0; i < zers; i++)
                printf("0%c", i + 1 < zers? ' ': '\n');
        } else {
            ones = ones / 2 * 2;
            printf("%d\n", ones);
            for (int i = 0; i < ones; i++)
                printf("1%c", i + 1 < ones? ' ': '\n');
        }
    }
    return 0;
}