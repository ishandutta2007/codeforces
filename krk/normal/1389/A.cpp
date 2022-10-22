#include <bits/stdc++.h>
using namespace std;

int T;
int l, r;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &l, &r);
        if (2 * l <= r) printf("%d %d\n", l, 2 * l);
        else printf("-1 -1\n");
    }
    return 0;
}