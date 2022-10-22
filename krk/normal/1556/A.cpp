#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        if ((a + b) % 2 != 0) printf("-1\n");
        else if (a == 0 && b == 0) printf("0\n");
        else if (a == b) printf("1\n");
        else printf("2\n");
    }
    return 0;
}