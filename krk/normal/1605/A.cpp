#include <bits/stdc++.h>
using namespace std;

int T;
int a, b, c;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d", &a, &b, &c);
        int res = abs(a + c - 2 * b);
        printf("%d\n", res % 3? 1: 0);
    }
    return 0;
}