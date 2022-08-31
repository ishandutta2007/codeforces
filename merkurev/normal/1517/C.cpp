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


const int N = 505;

int ans[N][N];


void solve(int n, int id, vector <int> p)
{
    if (p.size() == 0)
        return;

    int pos1 = 0;
    while (p[pos1] != 1 + id)
        pos1++;

    vector <int> np;
    for (int i = 0; i < (int) p.size(); i++)
    {
        ans[i + id][i] = p[i];
        if (i == pos1)
            continue;
        np.push_back(p[i]);
    }
    solve(n, id + 1, np);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <int> p(n);
    for (int i = 0; i < n; i++)
        scanf("%d", &p[i]);
    solve(n, 0, p);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
            printf("%d ", ans[i][j]);
        printf("\n");
    }


	return 0;
}