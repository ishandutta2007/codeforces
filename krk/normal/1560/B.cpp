#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        int len = 2 * abs(a - b);
        if (a > len || b > len || c > len) printf("-1\n");
        else {
            int d = c;
            d--;
            d = (d + len / 2) % len;
            d++;
            printf("%d\n", d);
        }
    }
    return 0;
}