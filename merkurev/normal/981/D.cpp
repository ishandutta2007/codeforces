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


const int N = 55;
long long a[N];
bool cb[N][N];
int n, k;

bool canGet(long long x)
{
    memset(cb, 0, sizeof cb);
    cb[0][0] = true;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < k; j++)
        {
            if (!cb[i][j] ) continue;
            long long s = 0;
            for (int h = i; h < n; h++)
            {
                s += a[h];
                if ( (s & x) == x)
                    cb[h + 1][j + 1] = true;
            }
        }
    return cb[n][k];
}

void gen(int id, long long x)
{
    if (id == -1)
    {
        printf("%lld\n", x);
        return;
    }
    if (canGet(x ^ (1LL << id) ) )
        gen(id - 1, x ^ (1LL << id));
    else
        gen(id - 1, x);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i] );

    gen(60, 0);



	return 0;
}