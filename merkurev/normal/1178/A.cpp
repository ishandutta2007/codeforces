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


const int N = 105;
int a[N];

int main()
{
#ifdef LOCAL
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    vector <int> good;
    int sum = 0, goodSum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (i == 0 || a[i] * 2 <= a[0])
        {
            goodSum += a[i];
            good.push_back(i);
        }
    }
    if (goodSum * 2 > sum)
    {
        printf("%d\n", (int) good.size());
        for (int x : good)
            printf("%d ", x + 1);
    }
    else
        printf("0\n");

    return 0;
}