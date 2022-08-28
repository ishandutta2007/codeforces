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

const int N = (int) 8e6 + 100;
int a[N];

vector <int> ans;

bool canRemove(int v, int g)
{
    if (g == -1)
        return true;
    if (a[v] == 0)
        return false;
    if (a[2 * v] > a[2 * v + 1])
        return canRemove(2 * v, g - 1);
    else
        return canRemove(2 * v + 1, g - 1);
}

void remove(int v)
{
    if (a[v] == 0)
        return;
    if (a[2 * v] > a[2 * v + 1])
    {
        a[v] = a[2 * v];
        remove(2 * v);
    }
    else
    {
        a[v] = a[2 * v + 1];
        remove(2 * v + 1);
    }
}

int h;

void solve(int v, int g)
{
    if (a[v] == 0)
        return;
    //eprintf("solve %d %d\n", v, g);
    //for (int i = 1; i < (1 << h); i++)
    //    eprintf("%d ", a[i]); eprintf("\n");
    while (a[v] != 0 && canRemove(v, g))
    {
        ans.push_back(v);
        remove(v);
    }
    //for (int i = 1; i < (1 << h); i++)
    //    eprintf("%d ", a[i]); eprintf("\n");
    solve(2 * v, g - 1);
    solve(2 * v + 1, g - 1);
}

void solve()
{
    int g;
    scanf("%d%d", &h, &g);
    for (int i = 1; i < (2 << h); i++)
        a[i] = 0;
    for (int i = 1; i < (1 << h); i++)
        scanf("%d", &a[i]);

    ans.clear();
    solve(1, g);

    long long ansSum = 0;
    for (int i = 1; i < (1 << g); i++)
        ansSum += a[i];
    if ((int) ans.size() != (1 << h) - (1 << g))
        throw;
    printf("%lld\n", ansSum);
    for (int x : ans)
        printf("%d ", x);
    printf("\n");
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
        solve();

	return 0;
}