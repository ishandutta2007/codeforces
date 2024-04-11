#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
    #define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
    #define eprintf(...) 42
#endif

typedef long long int int64;

const int mod = (int)1e9 + 7;
const int d = mod / 2 + 1;

int add(int a, int b)
{
    return (a + b) % mod;
}

int mul(int a, int b)
{
    return (int64)a * b % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif

    int64 a, b;
    scanf("%lld%lld", &a, &b);

    int64 ans = 0;
    for (int64 m = 1; m < b; m++)
    {
        int64 sum_t = mul(mul(mul(m, a + 1), a), d);
        //int64 sum_t = (m + m * a) * a / 2;
        int64 cur_add = mul(b, sum_t) + mul(m, a);
        cur_add %= mod;
        ans = add(ans, cur_add);
    }

    printf("%lld\n", ans);

    return 0;
}