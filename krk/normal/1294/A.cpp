#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c, n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &a, &b, &c, &n);
        int my = (a + b + c + n) / 3;
        if (3 * my == a + b + c + n && my >= a && my >= b && my >= c)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}