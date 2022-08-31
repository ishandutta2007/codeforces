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

const int LOG = 18;
const int LEVEL = (1 << LOG);
const int SZ = (LEVEL << 1);
const int INF = (int) 1e9;

struct Tree
{
    int mn[SZ];
    Tree() : mn() {}

    void setVal(int pos, int val)
    {
        pos += LEVEL;
        mn[pos] = val;
        while (pos > 1)
        {
            pos /= 2;
            mn[pos] = min(mn[2 * pos], mn[2 * pos + 1]);
        }
    }

    int getMin(int v, int tl, int tr, int l, int r)
    {
        if (r < tl || tr < l)
            return INF;
        if (l <= tl && tr <= r)
            return mn[v];
        int tm = (tl + tr) / 2;
        return min(
                getMin(2 * v, tl, tm, l, r),
                getMin(2 * v + 1, tm + 1, tr, l, r)
                );
    }

    int getMin(int l, int r)
    {
        return getMin(1, 0, LEVEL - 1, l, r);
    }

} treeMin, treeMax;


    
const int N = (int) 3e5 + 100;
vector <int> stMin, stMax;

int a[N];
int dp[N];

void solve()
{
    stMin.clear();
    stMax.clear();
    stMin.push_back(0);
    stMax.push_back(0);
    treeMin.setVal(0, 0);
    treeMax.setVal(0, 0);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++)
    {
        while (!stMin.empty() && a[stMin.back()] > a[i])
            stMin.pop_back();
        while (!stMax.empty() && a[stMax.back()] < a[i])
            stMax.pop_back();

        int pos_min = 0;
        if (!stMax.empty())
            pos_min = lower_bound(stMin.begin(), stMin.end(), stMax.back()) - stMin.begin();
        int pos_max = 0;
        if (!stMin.empty())
            pos_max = lower_bound(stMax.begin(), stMax.end(), stMin.back()) - stMax.begin();
        //for (int x : stMin)
        //    eprintf("%d ", x); eprintf("stMin\n");
        //for (int x : stMax)
        //    eprintf("%d ", x); eprintf("stMax\n");
        //eprintf("min: %d - %d\nmax: %d - %d\n", pos_min, (int) stMin.size() - 1, pos_max, (int) stMax.size() - 1);
        dp[i] = min(
                treeMin.getMin(pos_min, (int) stMin.size() - 1),
                treeMax.getMin(pos_max, (int) stMax.size() - 1)
                ) + 1;
        treeMin.setVal(stMin.size(), dp[i]);
        treeMax.setVal(stMax.size(), dp[i]);
        stMin.push_back(i);
        stMax.push_back(i);
        eprintf("dp[%d] = %d\n", i, dp[i]);
    }
    printf("%d\n", dp[n - 1]);
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