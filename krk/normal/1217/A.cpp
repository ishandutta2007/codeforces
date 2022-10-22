#include <bits/stdc++.h>
using namespace std;

int t;
int a, b, c;

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &a, &b, &c);
        int res = 0;
        if (a + c > b) res = min(c + 1, (a + c + 1 - b) / 2);
        printf("%d\n", res);
    }
    return 0;
}