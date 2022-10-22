#include <bits/stdc++.h>
using namespace std;

const int Maxb = 30;

int T;

bool Has(int add, int b)
{
    printf("? %d %d\n", add, add + (1 << b + 1));
    fflush(stdout);
    int res; scanf("%d", &res);
    return res & 1 << b;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int add = 1;
        for (int i = 0; i < 30; i++) {
            bool has = Has(add, i);
            if (has) add += 1 << i;
        }
        int res = (1 << 30) - add;
        printf("! %d\n", res);
        fflush(stdout);
    }
    return 0;
}