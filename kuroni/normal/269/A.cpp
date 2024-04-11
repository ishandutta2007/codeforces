#include <iostream>
#include <cstdio>
using namespace std;

int ans = 0, k, a, n;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d%d", &k, &a); --a;
        do
        {
            k++;
            a >>= 2;
        } while (a > 0);
        ans = max(ans, k);
    }
    printf("%d", ans);
}