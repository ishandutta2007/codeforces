#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int n;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        ll res = 1 << n;
        for (int i = 1; i <= n / 2; i++)
            res -= 1 << (n - i);
        for (int i = n / 2 + 1; i < n; i++)
            res += 1 << (n - i);
        printf("%I64d\n", res);
    }
    return 0;
}