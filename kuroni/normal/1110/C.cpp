#include <iostream>
#include <cstdio>
using namespace std;

int q;
long long a, ans;

int main()
{
    scanf("%d", &q);
    while (q--)
    {
        scanf("%lld", &a);
        if (64 - __builtin_clzll(a) == __builtin_popcountll(a))
        {
            ans = 1;
            for (int i = 2; 1LL * i * i <= a; i++)
                if (a % i == 0)
                {
                    ans = a / i;
                    break;
                }
        }
        else
            ans = (1LL << (64 - __builtin_clzll(a))) - 1;
        printf("%lld\n", ans);
    }
}