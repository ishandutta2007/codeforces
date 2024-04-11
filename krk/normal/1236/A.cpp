#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        int res = 0;
        for (int i = 0; i <= 100; i++)
            for (int j = 0; j <= 100; j++)
                if (i <= a && 2 * i + j <= b && 2 * j <= c)
                    res = max(res, (i + j) * 3);
        printf("%d\n", res);
    }
    return 0;
}