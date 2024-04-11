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


vector <int> getDivs(int n)
{
    vector <int> ans;
    for (int i = 1; i * i <= n; i++)
        if (n % i == 0)
        {
            ans.push_back(i);
            ans.push_back(n / i);
        }
    return ans;
}

const int N = 1005;
int a[N][N];
long long ans[N];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    vector <int> a0 = getDivs(a[0][1]);
    for (long long x : a0)
    {
        if (a[0][1] * 1LL * a[0][2] != a[1][2] * x * x)
            continue;
        if ((double) x * (double) x * (double)a[1][2] > 2e18)
            continue;

        ans[0] = x;
        for (int i = 1; i < n; i++)
            ans[i] = a[0][i] / x;

        for (int i = 0; i < n; i++)
            printf("%lld ", ans[i]);
        printf("\n");
        return 0;
    }

    return 0;
}