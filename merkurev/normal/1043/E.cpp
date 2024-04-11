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

const int N = (int) 4e5 + 100;
int x[N], y[N];

long long ans[N];

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    vector <pair <int, int> > v;

    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &x[i], &y[i]);
        v.emplace_back(x[i] - y[i], i);
    }
    sort(v.begin(), v.end());

    long long sumy = 0, sumx = 0;
    for (int i = 0; i < n; i++)
        sumy += y[i];
    for (int pos = 0; pos < n; pos++)
    {
        int i = v[pos].second;
        sumy -= y[i];
        ans[i] += (n - 1 - pos) * 1LL * x[i];
        ans[i] += sumy;
        ans[i] += (pos) * 1LL * y[i];
        ans[i] += sumx;
        sumx += x[i];
    }


    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        ans[a] -= min(x[a] + y[b], x[b] + y[a]);
        ans[b] -= min(x[a] + y[b], x[b] + y[a]);
    }


    for (int i = 0; i < n; i++)
        printf("%lld ", ans[i] );
    printf("\n");

	return 0;
}