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


vector <pair <int, long long>> read(int n, int m)
{
    vector <pair <int, long long>> ans;
    ans.emplace_back(0, 0);

    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        int cnt = 1;
        while (x % m == 0)
        {
            x /= m;
            cnt *= m;
        }
        if (x == ans.back().first)
            ans.back().second += cnt;
        else
            ans.emplace_back(x, cnt);
    }
    return ans;
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    auto a = read(n, m);
    int k;
    scanf("%d", &k);
    auto b = read(k, m);
    printf(a == b ? "Yes\n" : "No\n");
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