#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll a[Maxn];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%I64d", &a[i]);
    if (n == 1) {
        printf("1 1\n");
        printf("%I64d\n", -a[0]);
        printf("1 1\n");
        printf("0\n");
        printf("1 1\n");
        printf("0\n");
        return 0;
    }
    printf("1 %d\n", n);
    for (int i = 0; i < n; i++) {
        int md = abs(a[i]) % (n - 1);
        ll tims = (n - 1 - md) % (n - 1);
        if (a[i] < 0) tims = -tims;
        printf("%I64d%c", tims * ll(n), i + 1 < n? ' ': '\n');
        a[i] += tims * ll(n);
    }
    printf("1 %d\n", n - 1);
    for (int i = 0; i < n - 1; i++)
        printf("%I64d%c", -a[i], i + 1 < n - 1? ' ': '\n');
    printf("%d %d\n", n, n);
    printf("%I64d\n", -a[n - 1]);
    return 0;
}