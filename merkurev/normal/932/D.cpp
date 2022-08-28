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


const long long INF = (long long) 1e18;
const int N = (int) 4e5 + 100;
const int LOG = 20;

int par[N][LOG];
long long sumw[N];
long long w[N];
int h[N];
int sz = 2;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    h[1] = 1;
    w[0] = INF;
    sumw[1] = sumw[0] = INF;

    long long last = 0;
    int q;
    scanf("%d", &q);

    for (int it = 0; it < q; it++)
    {
        int t;
        long long a, b;
        scanf("%d%lld%lld", &t, &a, &b);
        a ^= last;
        b ^= last;

        if (t == 1)
        {
            int v = sz++;
            w[v] = b;
            int x = a;
            for (int i = LOG - 1; i >= 0; i--)
                if (w[par[x][i] ] < w[v] )
                    x = par[x][i];
            if (w[x] < w[v] )
                x = par[x][0];
            par[v][0] = x;
            h[v] = h[x] + 1;
            sumw[v] = sumw[par[v][0] ] + w[v];
            for (int i = 1; i < LOG; i++)
                par[v][i] = par[par[v][i - 1]][i - 1];
//            eprintf("v = %d, x = %d, sumw = %lld\n", v, x, sumw[v]);
        }
        else
        {
            int v = a;
            long long x = b;
            for (int i = LOG - 1; i >= 0; i--)
                if (sumw[a] - sumw[par[v][i] ] + w[par[v][i] ] <= x)
                    v = par[v][i];
            int ans = h[a] - h[v] + 1;
//            eprintf("a = %lld, v = %d, x = %lld\n", a, v, x);
            v = par[v][0];
            if (sumw[a] - sumw[v] > x) ans = 0;
            printf("%d\n", ans);
            last = ans;
        }
    }




	return 0;
}