#include <bits/stdc++.h>
using namespace std;

int T;
int l, r, a;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &l, &r, &a);
        int res = r / a + r % a;
        r = r / a * a;
        if (l < r) res = max(res, (r - 1) / a + (r - 1) % a);
        printf("%d\n", res);
    }
    return 0;
}