#include <bits/stdc++.h>
using namespace std;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n == 1) printf("2\n");
        else printf("%d\n", (n - 1) / 3 + 1);
    }
    return 0;
}