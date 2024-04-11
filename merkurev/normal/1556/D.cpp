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


int get_sum(int a, int b)
{
    int OR, AND;
    printf("or %d %d\n", a + 1, b + 1);
    fflush(stdout);
    scanf("%d", &OR);
    printf("and %d %d\n", a + 1, b + 1);
    fflush(stdout);
    scanf("%d", &AND);
    return OR + AND;
}

const int N = (int) 1e4 + 100;
int q[N];


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);

    int ab = get_sum(0, 1);
    int ac = get_sum(0, 2);
    int bc = get_sum(1, 2);

    q[0] = (ab + ac - bc) / 2;
    q[1] = ab - q[0];
    q[2] = ac - q[0];
    for (int i = 3; i < n; i++)
        q[i] = get_sum(0, i) - q[0];
    sort(q, q + n);
    printf("finish %d\n", q[k - 1]);
    fflush(stdout);

	return 0;
}