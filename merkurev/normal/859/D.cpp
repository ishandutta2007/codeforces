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


const int K = 6;
const int N = (1 << 6);
long double p[N + 1][N + 1];

long double pa[K + 1][N + 1];
long double win[K + 1][N + 1];
void upd(long double &a, long double b)
{
    a = max(a, b);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int k;
    scanf("%d", &k);
    int n = (1 << k);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            double x;
            scanf("%lf", &x);
            p[i][j] = x / 100.;
        }

    for (int i = 0; i < n; i++)
    {
        pa[0][i] = 1;
        win[0][i] = 0;
    }

    for (int it = 0; it < k; it++)
    {
        int sh = (1 << it);
        for (int s = 0; s < n; s += (sh << 1) )
        {
            for (int a = s; a < s + sh; a++)
                for (int b = s + sh; b < s + 2 * sh; b++)
                {
                    {
                        pa[it + 1][a] += pa[it][a] * pa[it][b] * p[a][b];
                        long double get = win[it][a] + win[it][b];

                        for (int wb = s + sh; wb < s + 2 * sh; wb++)
                            get += pa[it][a] * pa[it][wb] * p[a][wb] * sh;

                        upd(win[it + 1][a], get);
                    }
                    {
                        pa[it + 1][b] += pa[it][a] * pa[it][b] * p[b][a];
                        long double get = win[it][a] + win[it][b];
                        
                        for (int wa = s; wa < s + sh; wa++)
                            get += pa[it][b] * pa[it][wa] * p[b][wa] * sh;
                    
                        upd(win[it + 1][b], get);
                    }
                }
        }
/*        for (int i = 0; i < n; i++)
            eprintf("%.5Lf ", pa[it + 1][i] );
        eprintf("\n");
        for (int i = 0; i < n; i++)
            eprintf("%.5Lf ", win[it + 1][i] );
        eprintf("\n\n");
*/
    }
    long double ans = 0;
    for (int i = 0; i < n; i++)
        ans = max(ans, win[k][i] );
    printf("%.12Lf\n", ans);


	return 0;
}