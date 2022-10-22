#include <bits/stdc++.h>
using namespace std;

int T;
int x, y;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        int d = x * x + y * y;
        int s = 0;
        while (s * s < d) s++;
        int res = 0;
        if (s * s == d)
            if (s > 0) res = 1;
            else res = 0;
        else res = 2;
        printf("%d\n", res);
    }
    return 0;
}