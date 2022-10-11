#include <iostream>
#include <cstdio>
#define ab (1LL * p * m)
#define ll I64
using namespace std;

const int P = 1E6 + 5;

int a, b, p, pos[P], m;
long long x, cnt = 0;

void init()
{
    fill(pos, pos + P, -1);
    for (long long cur = 1, i = 0; i < p - 1; i++)
    {
        pos[cur] = i;
        (cur *= a) %= p;
        if (cur == 1)
        {
            m = i + 1;
            return;
        }
    }
}

long long pw(int a, int t)
{
    if (t == 0)
        return 1;
    long long ret = pw(a, t / 2);
    (ret *= ret) %= p;
    if (t & 1)
        (ret *= a) %= p;
    return ret;
}

int main()
{
    scanf("%d%d%d%lld", &a, &b, &p, &x);
    a %= p;
    b %= p;
    if (a == 0)
    {
        printf("%lld", (b == 0) ? x : 0);
        return 0;
    }
    else
    {
        if (b == 0)
        {
            printf("%lld", x / p);
            return 0;
        }
        else
        {
            init();
            for (int i = 1; i < p; i++)
            {
                int j = pos[pw(i, p - 2) * b % p];
                if (j == -1)
                    continue;
                long long ans = 1LL * j * p - 1LL * i * (p - 1);
                ((ans %= ab) += ab) %= ab;
                cnt += (ans > x ? 0 : (x - ans) / ab + 1);
            }
            printf("%lld", cnt);
            return 0;
        }
    }
}