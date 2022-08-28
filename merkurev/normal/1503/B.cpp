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

const int N = 205;

vector <pair <int, int>> v[N];


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            v[i + j].emplace_back(i, j);

    int id = 2;
    int nid = 3;

    int col_id = 1;
    int col_nid = 2;

    for (int i = 0; i < n * n; i++)
    {
        while (v[id].empty())
        {
            id++;
            nid++;
            swap(col_id, col_nid);
        }

        //eprintf("i = %d, id = %d, nid = %d\n", i, id, nid);
        //eprintf("col_id = %d, col_nid = %d\n", col_id, col_nid);

        int x;
        scanf("%d", &x);

        if (x == col_id) {
            if (v[nid].empty()) {
                printf("%d %d %d\n", 3, v[id].back().first, v[id].back().second);
                v[id].pop_back();
            }
            else {
                printf("%d %d %d\n", col_nid, v[nid].back().first, v[nid].back().second);
                v[nid].pop_back();
            }
        }
        else {
            printf("%d %d %d\n", col_id, v[id].back().first, v[id].back().second);
            v[id].pop_back();
        }

        fflush(stdout);
    }

	return 0;
}