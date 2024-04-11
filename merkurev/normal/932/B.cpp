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


const int K = 10;
const int N = (int) 1e6 + 100;
int f[N];
int p[N][K];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < 10; i++)
        f[i] = i;
    for (int i = 10; i < N; i++)
    {
        int ii = i;
        int x = 1;
        while (ii > 0)
        {
            int c = ii % 10;
            if (c > 0)
                x *= c;
            ii /= 10;
        }
        f[i] = f[x];
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < K; j++)
            p[i][j] = p[i - 1][j];
        p[i][f[i - 1] ]++;
    }
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int l, r, k;
        scanf("%d%d%d", &l, &r, &k);
        printf("%d\n", p[r + 1][k] - p[l][k] );
    }




	return 0;
}