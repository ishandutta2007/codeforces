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

const int N = (int) 3e5 + 100;
char s[3][N];
char ans[N];


void solve()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 3; i++)
        scanf("%s", s[i]);
    
    for (int i = 0; i < 3; i++)
        for (int j = i + 1; j < 3; j++)
            for (char c = '0'; c <= '1'; c++)
            {
                int cnti = 0;
                int cntj = 0;
                for (int h = 0; h < 2 * n; h++)
                    cnti += (s[i][h] == c);
                for (int h = 0; h < 2 * n; h++)
                    cntj += (s[j][h] == c);
                if (cnti < n || cntj < n)
                    continue;

                int pos = 0;
                int posi = 0, posj = 0;
                for (int k = 0; k < n; k++)
                {
                    while (s[i][posi] != c)
                    {
                        ans[pos++] = s[i][posi++];
                    }
                    while (s[j][posj] != c)
                    {
                        ans[pos++] = s[j][posj++];
                    }
                    ans[pos++] = c;
                    posi++;
                    posj++;
                }
                while (posi < 2 * n)
                    ans[pos++] = s[i][posi++];
                while (posj < 2 * n)
                    ans[pos++] = s[j][posj++];


                ans[pos] = 0;
                printf("%s\n", ans);
                return;
            }
    throw;
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