#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")

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

    int n;
    scanf("%d", &n);
    if (n % 2 == 0)
        printf("NO\n");
    else
    {
        printf("YES\n");
        vector <int> a, b;
        for (int i = 0; i < 2 * n;)
        {
            a.push_back(i++);
            b.push_back(i++);
            if (i == 2 * n) break;
            b.push_back(i++);
            a.push_back(i++);
        }
        for (int x : a)
            printf("%d ", x + 1);
        for (int x : b)
            printf("%d ", x + 1);
        printf("\n");
    }

    return 0;
}