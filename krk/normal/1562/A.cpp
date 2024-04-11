#include <bits/stdc++.h>
using namespace std;

int T;
int l, r;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        int cur = (r + 1) / 2;
        int res = cur >= l? cur - 1: r % l;
        printf("%d\n", res);
    }
    return 0;
}