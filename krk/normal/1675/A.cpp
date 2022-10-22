#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c, x, y;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d", &a, &b, &c, &x, &y);
        int tk = min(a, x); x -= tk;
        tk = min(b, y); y -= tk;
        printf("%s\n", x + y <= c? "YES": "NO");
    }
    return 0;
}