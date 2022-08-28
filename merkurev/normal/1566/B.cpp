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
char s[N];

void solve()
{
    scanf("%s", s);
    int n = strlen(s);

    bool all1 = true;
    for (int i = 0; i < n; i++)
        if (s[i] == '0')
            all1 = false;
    if (all1)
    {
        printf("0\n");
        return;
    }
    int i = 0;
    while (i < n && s[i] != '0')
        i++;
    while (i < n && s[i] != '1')
        i++;
    while (i < n && s[i] != '0')
        i++;
    if (i == n)
    {
        printf("1\n");
        return;
    }
    printf("2\n");
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