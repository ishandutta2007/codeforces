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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}


const int N = 105;
int ans[N][N];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    vector <pair<int, int>> v;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x;
            scanf("%d", &x);
            v.emplace_back(x, i);
        }
    sort(v.begin(), v.end());

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = -1;

    for (int i = 0; i < m; i++)
    {
        ans[i][v[i].second] = v[i].first;
    }
    for (int i = m; i < n * m; i++)
    {
        int id = 0;
        while (ans[id][v[i].second] != -1)
            id++;
        ans[id][v[i].second] = v[i].first;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", ans[j][i]);
        printf("\n");
    }
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