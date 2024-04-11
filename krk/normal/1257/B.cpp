#include <bits/stdc++.h>
using namespace std;

int t;
int x, y;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &x, &y);
        if (x == 2) x = 3;
        if (x >= y || x > 3) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}