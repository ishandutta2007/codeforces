#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

const int mod = 1e9 + 7;

int x, y;
map<int, int> f;

int pow(int u)
{
    if (u == 0)
        return 1;
    long long ret = pow(u / 2);
    (ret *= ret) %= mod;
    if (u & 1)
        (ret *= 2) %= mod;
    return ret;
}

int find_ans(int x)
{
    if (x == 1)
        return 1;
    if (f.count(x) > 0)
        return f[x];
    int ret = pow(x - 1);
    for (int i = 1; i * i <= x; i++)
        if (x % i == 0)
        {
            (ret -= find_ans(i)) %= mod;
            if (i * i < x && i != 1)
                (ret -= find_ans(x / i)) %= mod;
        }
    return f[x] = (ret + mod) % mod;
}

int main()
{
    scanf("%d%d", &x, &y);
    if (y % x != 0)
    {
        printf("0");
        return 0;
    }
    printf("%d", find_ans(y / x));
}