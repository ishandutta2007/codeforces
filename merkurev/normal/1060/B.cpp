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

const int INF = (int) 1e9;
const int N = 20;
char str[N];
int dp[2] = {0, -INF};

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%s", str);
    int n = strlen(str);
    reverse(str, str + n);

    for (int i = 0; i < n; i++)
    {
        int c = str[i] - '0';
        int ndp[2] = {-INF, -INF};
        for (int o = 0; o <= 1; o++)
            for (int no = 0; no <= 1; no++)
                for (int a = 0; a <= 9; a++)
                    for (int b = 0; b <= 9; b++)
                    {
                        if (a + b + o != c + 10 * no) continue;
                        ndp[no] = max(ndp[no], dp[o] + a + b);
                    }
        dp[0] = ndp[0];
        dp[1] = ndp[1];
    }

    printf("%d\n", dp[0]);


	return 0;
}