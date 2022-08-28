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

    int b, g, n;
    scanf("%d%d%d", &b, &g, &n);
    
    int ans = 0;
    for (int i = 0; i <= b; i++)
        for (int j = 0; j <= g; j++)
            if (i + j == n)
                ans++;
    printf("%d\n", ans);

    return 0;
}