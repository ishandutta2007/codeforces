#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

#ifdef LOCAL
    #define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
    #define eprintf(...)
#endif

const int MOD = 998244353;

int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}



int main()
{
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif
    int n, m;
    scanf("%d%d", &n, &m);

    int ans = 1;
    for (int i = 0; i < n + m; i++)
        ans = mul(ans, 2);
    printf("%d\n", ans);

    return 0;
}