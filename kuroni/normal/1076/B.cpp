#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int ret = 0;
    long long n;
    scanf("%lld", &n);
    if (n % 2 == 1)
        for (int i = 3; 1LL * i * i <= n; i += 2)
            if (n % i == 0)
            {
                n -= i;
                ret++;
                break;
            }
    if (n % 2 == 1 && ret == 0)
        printf("1\n");
    else
        printf("%lld", n / 2 + ret);
}