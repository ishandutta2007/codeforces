#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        int res1 = abs(1 - a);
        int res2 = abs(b - c) + abs(1 - c);
        if (res1 < res2) printf("1\n");
        else if (res1 > res2) printf("2\n");
        else printf("3\n");
    }
    return 0;
}