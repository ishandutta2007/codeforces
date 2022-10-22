#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
ll sum;

ll gcd(ll x, ll y) { return x? gcd(y % x, x): y; }

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        sum += i;
    for (int i = 1; i <= n && i < sum; i++)
        if (gcd(i, sum - i) > 1) {
            printf("Yes\n");
            printf("1 %d\n", i);
            printf("%d", n - 1);
            for (int j = 1; j <= n; j++) if (j != i)
                printf(" %d", j);
            printf("\n");
            return 0;
        }
    printf("No\n");
    return 0;
}