#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 5005;

int n, a[N], dp[N][N];

int find_ans(int l, int r)
{
    if (dp[l][r] != -1)
        return dp[l][r];
    return dp[l][r] = (a[l] == a[r] ? find_ans(l + 1, r - 1) : min(find_ans(l, r - 1), find_ans(l + 1, r))) + 1;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", a + i);
    n = distance(a + 1, unique(a + 1, a + n + 1));
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            dp[i][j] = -1;
    printf("%d", find_ans(1, n));
}