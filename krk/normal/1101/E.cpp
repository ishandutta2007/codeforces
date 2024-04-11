#include <bits/stdc++.h>
using namespace std;

int n;
int x, y;

int main()
{
    scanf("%d", &n);
    while (n--) {
        char typ; int a, b; scanf(" %c %d %d", &typ, &a, &b);
        if (a > b) swap(a, b);
        if (typ == '+') {
            x = max(x, a); y = max(y, b);
        } else printf("%s\n", x <= a && y <= b? "YES": "NO");
    }
    return 0;
}