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


const int K = 11;
const int N = (int) 1e5 + 100;
int a[K][N], pos[K][N];
int d[N];
int n, m;

int getD(int v)
{
    if (d[v] != -1) return d[v];
    int nx = -1;
    d[v] = 1;
    for (int i = 0; i < m; i++)
    {
        int x = pos[i][v];
        if (x == n - 1)
            return d[v];
        int cnx = a[i][x + 1];
        if (nx != -1 && nx != cnx)
            return d[v];
        nx = cnx;
    }
    d[v] += getD(nx);
    return d[v];
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            a[i][j]--;
            pos[i][a[i][j]] = j;
        }
    }
    long long ans = 0; 
    memset(d, -1, sizeof d);
    for (int i = 0; i < n; i++)
        ans += getD(i);

    printf("%lld\n", ans);

	return 0;
}