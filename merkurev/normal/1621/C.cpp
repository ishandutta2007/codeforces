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


const int N = (int) 1e4 + 100;
bool used[N];
int ans[N];

void solve()
{
    memset(used, false, sizeof used);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        if (used[i])
            continue;
        vector <int> p;
        while (true)
        {
            printf("? %d\n", i + 1);
            fflush(stdout);
            int x;
            scanf("%d", &x);
            x--;
            if (used[x])
                break;
            p.push_back(x);
            used[x] = true;
        }

        for (int j = 0; j < (int) p.size(); j++)
            ans[p[j]] = p[(j + 1) % (int) p.size()];
    }
    printf("!");
    for (int i = 0; i < n; i++)
        printf(" %d", ans[i] + 1);
    printf("\n");
    fflush(stdout);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++)
        solve();



	return 0;
}