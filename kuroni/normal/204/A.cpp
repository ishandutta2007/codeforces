#include <iostream>
#include <cstdio>
using namespace std;

long long l, r, ans, init[20];
int i;

long long solve(long long x)
{
    if (x == 0)
        return 0;
    long long t = x, ret = 0;
    int cnt = 0, f, i;
    while (t != 0)
    {
        f = t % 10;
        t /= 10;
        ++cnt;
    }
    for (i = 1; i < cnt; i++)
        ret += init[i] * 9;
    ret += init[cnt] * (f - 1);
    if (x % 10 >= f)
        ++ret;
    if (x >= 100)
        ret += x / 10 - init[cnt] * f;
    return ret;
}

int main()
{
    scanf("%I64d%I64d", &l, &r);
    init[1] = init[2] = 1;
    for (i = 3; i <= 19; i++)
        init[i] = init[i - 1] * 10;
    printf("%I64d", solve(r) - solve(l - 1));
}