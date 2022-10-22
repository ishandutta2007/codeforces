#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        if (2 * b - c > 0 && (2 * b - c) % a == 0)
            printf("YES\n");
        else if ((a + c) % 2 == 0 && (a + c) / 2 % b == 0)
            printf("YES\n");
        else if (2 * b - a > 0 && (2 * b - a) % c == 0)
            printf("YES\n");
        else printf("NO\n"); 
    }
    return 0;
}