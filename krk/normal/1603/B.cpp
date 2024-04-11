#include <bits/stdc++.h>
using namespace std;

int T;
int x, y;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &x, &y);
        if (x > y) printf("%d\n", x + y);
        else {
            x = y / x * x;
            printf("%d\n", (x + y) / 2);
        }
    }
    return 0;
}