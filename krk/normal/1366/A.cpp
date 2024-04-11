#include <bits/stdc++.h>
using namespace std;

int T;
int a, b;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &a, &b);
        int res = min((a + b) / 3, min(a, b));
        printf("%d\n", res);
    }
    return 0;
}