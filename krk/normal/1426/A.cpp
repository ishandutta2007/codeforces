#include <bits/stdc++.h>
using namespace std;

int T;
int n, x;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &x);
        if (n <= 2) printf("1\n");
        else printf("%d\n", 2 + (n - 3) / x);
    }
    return 0;
}