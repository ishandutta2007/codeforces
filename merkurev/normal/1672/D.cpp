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

const int N = (int) 2e5 + 100;
int a[N];
int b[N];
int bal[N];

void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &b[i]);
        b[i]--;
    }
    for (int i = 0; i < n; i++)
        bal[i] = 0;

    bool good = true;
    int ptr = 0;
    for (int i = 0; i < n; i++)
    {
        int x = b[i];
        if (i + 1 < n && b[i] == b[i + 1] && bal[x] > 0)
        {
            bal[x]--;
            continue;
        }
        while (ptr < n && a[ptr] != x)
        {
            bal[a[ptr]]++;
            ptr++;
        }
        if (ptr < n && a[ptr] == x)
            ptr++;
        else
        {
            good = false;
            break;
        }
    }
    printf(good ? "YES\n" : "NO\n");
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