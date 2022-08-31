#ifndef LOCAL
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#endif

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


const int N = (int) 3e5 + 100;
int h[N];

vector <int> ch[N];

void print(int v)
{
    printf("(");
    for (int to : ch[v])
    {
        eprintf("%d -> %d\n", v, to);
        print(to);
    }
    printf(")");
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    long long k;
    scanf("%d%lld", &n, &k);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        h[i] = i;
        sum += i;
    }

    if (sum < k)
    {
        printf("Impossible\n");
        return 0;
    }

    for (int i = n - 1; i > 0; i--)
    {
        long long x = min((long long)i, sum - k);
        h[i] -= x;
        sum -= x;
    }

    if (sum != k)
        throw;
    for (int i = 1; i < n; i++)
        if (h[i])
            ch[h[i] - 1].push_back(i);

    for (int i = 0; i < n; i++)
        if (h[i] == 0)
            print(i);

	return 0;
}