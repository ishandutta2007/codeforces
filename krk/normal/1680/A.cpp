#include <bits/stdc++.h>
using namespace std;

int T;
int l1, r1, l2, r2;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &l1, &r1, &l2, &r2);
        int res = l1 + l2;
        if (max(l1, l2) <= min(r1, r2)) res = min(res, max(l1, l2));
        printf("%d\n", res);
    }
    return 0;
}