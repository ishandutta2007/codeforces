#include <bits/stdc++.h>
using namespace std;

int p, y;

bool Check(int x)
{
    for (int i = 2; i * i <= x; i++) if (x % i == 0) {
        if (i <= p) return false;
        while (x % i == 0) x /= i;
    }
    if (x > 1 && x <= p) return false;
    return true;
}

int main()
{
    scanf("%d %d", &p, &y);
    while (y > p && !Check(y)) y--;
    if (y <= p) printf("-1\n");
    else printf("%d\n", y);
    return 0;
}