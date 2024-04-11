#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

void upd(int &a, int b)
{
    a = max(a, b);
}

const int N = 2005;
int a[N];
int dp[N][4];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i] );
        a[i]--;
    }
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j + 1 < 4; j++)
            upd(dp[i][j + 1], dp[i][j] );
        if (i == n) break;

        for (int j = 0; j < 4; j++)
            if (j % 2 == a[i] )
                dp[i][j] += 1;

        for (int j = 0; j < 4; j++)
            upd(dp[i + 1][j], dp[i][j]);
    }
    printf("%d\n", dp[n][3] );
    


	return 0;
}