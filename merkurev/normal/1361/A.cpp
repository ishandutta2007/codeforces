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

const int N = (int) 5e5 + 100;
int col[N];
vector <int> g[N];
int p[N];


bool cmpCol(int a, int b)
{
    return col[a] < col[b];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        p[i] = i;
        scanf("%d", &col[i]);
    }

    sort(p, p + n, cmpCol);

    for (int ii = 0; ii < n; ii++)
    {
        int i = p[ii];
        vector <int> v;
        for (int to : g[i])
            if (col[to] <= col[i])
                v.push_back(col[to]);
        sort(v.begin(), v.end());
        int z = 1;
        for (int x : v)
            if (x == z)
                z++;
        if (z != col[i])
        {
            printf("-1\n");
            return 0;
        }
    }
    for (int i = 0; i < n; i++)
        printf("%d ", p[i] + 1);
    printf("\n");

	return 0;
}