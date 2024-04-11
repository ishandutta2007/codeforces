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

const int K = 20;
char st[K + 1], fin[K + 1];

const int N = (int) 1e6 + 100;
int op[N][2];

int goTo[N][K];
int goMask[N];
int rMask[N];

const int SZ = (1 << K);
int dist[SZ];
int getBy[SZ];

int qu[SZ];

int k;

void addMask(int mask, int by)
{
    if (dist[mask] == 0)
        return;
    dist[mask] = 0;
    getBy[mask] = by;
    int r = 0;
    qu[r++] = mask;
    for (int i = 0; i < r; i++)
    {
        int cur = qu[i];
        int cdist = dist[cur];
        for (int j = 0; j < k; j++)
        {
            int nmask = cur ^ (1 << j);
            if (dist[nmask] > cdist + 1)
            {
                dist[nmask] = cdist + 1;
                getBy[nmask] = by;
                qu[r++] = nmask;
            }
        }
    }
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    for (int i = 0; i < SZ; i++)
        dist[i] = K + 1;

    int n, m;
    scanf("%d%d%d", &n, &m, &k);
    scanf("%s%s", st, fin);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &op[i][0], &op[i][1]);
        op[i][0]--;
        op[i][1]--;
    }

    for (int i = 0; i < k; i++)
        goTo[n][i] = i;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < k; j++)
            goTo[i][j] = goTo[i + 1][j];
        swap(goTo[i][op[i][0]], goTo[i][op[i][1]]);
        for (int j = 0; j < k; j++)
            goMask[i] |= ((st[j] - '0') << goTo[i][j]);
    }
    // goMask[i] : i, i + 1, .. n - 1

    for (int i = 0; i < k; i++)
        goTo[n][i] = i;
    
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < k; j++)
            rMask[i] |= ((fin[j] - '0') << goTo[i][j]);
        
        for (int j = 0; j < k; j++)
            goTo[i - 1][j] = goTo[i][j];
        swap(goTo[i - 1][op[i - 1][0]], goTo[i - 1][op[i - 1][1]]);
    //    for (int j = 0; j < k; j++)
    //        goMask[i] |= ((st[j] - '0') << goTo[i][j]);
    }
   /* 
    for (int i = n; i > 0; i--)
    {
        for (int j = 0; j < k; j++)
            rMask[i] |= ((fin[j] - '0') << j);
        swap(fin[op[i - 1][0]], fin[op[i - 1][1]]);
    }*/
    // rMask[i] : n - 1, n - 2, ... i

    int ans = k + 1;
    int ansl = 0, ansr = 0;

    for (int i = 0; i + m <= n; i++)
    {
        addMask(goMask[i], i); // i ... n - 1
        int cur = dist[rMask[i + m]]; // n - 1 ... i + m
        eprintf("rMask = %d\n", rMask[i + m]);
        if (cur < ans)
        {
            ans = cur;
            ansl = getBy[rMask[i + m]] + 1;
            ansr = i + m;
        }
    }

    printf("%d\n%d %d\n", k - ans, ansl, ansr);


	return 0;
}