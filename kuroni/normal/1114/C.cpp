#include <iostream>
#include <cstdio>
using namespace std;

long long b, n, ans = 1E18 + 7;

int main()
{
    scanf("%lld%lld", &n, &b);
    for (int i = 2; 1LL * i * i <= b; i++)
        if (b % i == 0)
        {
            int cnt = 0;
            while (b % i == 0)
            {
                b /= i;
                cnt++;
            }
            long long tmp = i, cur = 0;
            while (true)
            {
                cur += n / tmp;
                if (n / tmp < i)
                    break;
                tmp *= i;
            }
            ans = min(ans, cur / cnt);
        }
    if (b > 1)
    {
        long long tmp = b, cur = 0;
        while (true)
        {
            cur += n / tmp;
            if (n / tmp < b)
                break;
            tmp *= b;
        }
        ans = min(ans, cur);
    }
    printf("%lld", ans);
}