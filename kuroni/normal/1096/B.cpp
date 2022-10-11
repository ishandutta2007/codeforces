#include <iostream>
#include <cstdio>
using namespace std;

const int N = 200005, MOD = 998244353;

int n, l, r;
char s[N];

int main()
{
    scanf("%d\n%s", &n, s + 1);
    for (int i = 2; i <= n; i++)
        if (s[i] != s[i - 1])
        {
            l = i - 1;
            break;
        }
    for (int i = n - 1; i >= 1; i--)
        if (s[i] != s[i + 1])
        {
            r = i + 1;
            break;
        }
    if (s[l] != s[r])
        printf("%d\n", l + 1 + (n + 2 - r) - 1);
    else
        printf("%lld\n", 1LL * (l + 1) * (n + 2 - r) % MOD);
}