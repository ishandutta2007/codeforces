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




int main()
{
#ifdef LOCAL
 //   freopen("input.txt", "r", stdin);
 //   freopen("output.txt", "w", stdout);
#endif

    int n, e, d;
    scanf("%d%d%d", &n, &e, &d);
    int ans = n;
    d *= 5;
    for (int i = 0; i * e <= n; i++)
    {
        int cur = (n - i * e) % d;
        ans = min(ans, cur);
    }
    printf("%d\n", ans);

    return 0;
}