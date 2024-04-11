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

int get_cnt(vector <int> &v, int l, int r)
{
    return lower_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
}

const int N = (int) 2e5 + 100;
char str[N];
vector <int> v[2];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, q;
    scanf("%d%d", &n, &q);
    scanf("%s", str);

    for (int i = 0; i < n - 1; i++)
    {
        if (str[i] == '0' && str[i + 1] == '0')
            v[0].push_back(i);
        if (str[i] == '1' && str[i + 1] == '1')
            v[1].push_back(i);
    }

    for (int it = 0; it < q; it++)
    {
        int l, r;
        scanf("%d%d", &l, &r);
        l--;
        r--;
        vector <int> cnts = {
            get_cnt(v[0], l, r),
            get_cnt(v[1], l, r)
        };
        sort(cnts.begin(), cnts.end());
        printf("%d\n", cnts[1] + 1);
    }

	return 0;
}