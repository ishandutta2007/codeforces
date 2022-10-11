#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#define lim 63 - __builtin_clzll(n)
using namespace std;

const long long INF = 1E18 + 7, SINF = 1E6 + 5;
const int MAX = 64;

int t, f[MAX];
long long n;
vector<long long> pw[MAX];

void init()
{
    for (int i = 2; i <= SINF; i++)
    {
        long long cur = 1LL * i * i;
        for (int j = 3; ; j++)
        {
            if (INF / cur < i)
                break;
            cur *= i;
            if (j > 2)
                pw[j].push_back(cur);
        }
    }
}

int main()
{
    init();
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &n);
        long long ans = n - 1;
        for (int i = lim; i >= 2; i--)
        {
            f[i] = (i == 2 ? sqrt(n) - 1: distance(pw[i].begin(), upper_bound(pw[i].begin(), pw[i].end(), n)));
            for (int j = i * 2; j <= lim; j += i)
                f[i] -= f[j];
            ans -= f[i];
        }
        printf("%lld\n", ans);
    }
}