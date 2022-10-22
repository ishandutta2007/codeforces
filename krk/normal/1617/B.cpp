#include <bits/stdc++.h>
using namespace std;

int T;
int n;

void Solve(int n)
{
    if (n % 2 == 0)
        printf("%d %d %d\n", (n - 1) / 2, n / 2, 1);
    else if (n % 4 == 3)
        printf("%d %d %d\n", n / 2 - 2, n / 2 + 2, 1);
    else printf("%d %d %d\n", n / 2 - 1, n / 2 + 1, 1);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        Solve(n);
    }
    return 0;
}