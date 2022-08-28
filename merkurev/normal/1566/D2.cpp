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

const int N = (int) 1e5 + 100;
int a[N];
int as[N];

const int K = 305;
int used[K][K];

int get_id(int val, int n)
{
    return lower_bound(as, as + n, val) - as;
}

vector <pair <int, int>> pos[N];

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    
    for (int i = 0; i < n * m; i++)
    {
        scanf("%d", &a[i]);
        as[i] = a[i];
    }
    sort(as, as + n * m);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int cur = i * m + j;
            pos[get_id(as[cur], n * m)].emplace_back(i, -j);
        }
    for (int i = 0; i < n * m; i++)
    {
        sort(pos[i].begin(), pos[i].end());
        reverse(pos[i].begin(), pos[i].end());
    }

    memset(used, false, sizeof used);

    int ans = 0;
    for (int i = 0; i < n * m; i++)
    {
        int val = get_id(a[i], n * m);
        int x = pos[val].back().first;
        int y = -pos[val].back().second;
        pos[val].pop_back();
        used[x][y] = true;
        //eprintf("%d (%d) -> %d %d\n", val, i, x, y);
        for (int j = 0; j < y; j++)
            ans += used[x][j];

    }
    printf("%d\n", ans);
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