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

const int INF = (int) 1e9 + 100;

bool isP(int x)
{
    for (int i = 2; i * i <= x; i++)
        if (x % i == 0) return false;
    return true;
}

const int N = (int) 1e6 + 100;
int mxp[N];

int solve(int x)
{
    if (mxp[x] == 0) return INF;
    return x - mxp[x] + 1;
}

void init()
{
    for (int i = 2; i < N; i++)
    {
        if (mxp[i] != 0) continue;
        for (int j = 2 * i; j < N; j += i)
            mxp[j] = i;
    }
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    init();

    int x;
    scanf("%d", &x);
    vector <int> p;
    int ans = x;
    for (int i = x - 1; i >= 2; i--)
        if (x % i == 0 && isP(i) )
        {
            eprintf("i = %d\n", i);
            for (int j = i - 1; j >= 0; j--)
                ans = min(ans, solve(x - j) );
            break;
        }
    printf("%d\n", ans);

	return 0;
}