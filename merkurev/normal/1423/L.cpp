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
ull myRand(ull B) {
	return (ull)rng() % B;
}


const int K = 3;

struct Hash
{
    ull a[K];

    Hash() : a() {}


    Hash operator ^ (const Hash &A) const
    {
        Hash ans = Hash();
        for (int i = 0; i < K; i++)
            ans.a[i] = a[i] ^ A.a[i];
        return ans;
    }

    bool operator == (const Hash &A) const
    {
        for (int i = 0; i < K; i++)
            if (a[i] != A.a[i])
                return false;
        return true;
    }

    bool operator < (const Hash &A) const
    {
        for (int i = 0; i < K; i++)
            if (a[i] != A.a[i])
                return a[i] < A.a[i];
        return false;
    }

    void eprint()
    {
        for (int i = 0; i < K; i++)
            eprintf("%llu ", a[i]);
        eprintf("\n");
    }
};


Hash randHash()
{
    Hash ans = Hash();
    for (int i = 0; i < K; i++)
        ans.a[i] = myRand(1ULL << 62);
    return ans;
}


const int N = 1005;
Hash light[N];

Hash sw[N];

const int BOUND = 20;

map <Hash, int> prec;

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, s, d;
    scanf("%d%d%d", &n, &s, &d);

    for (int i = 0; i < n; i++)
        light[i] = randHash();

    for (int i = 0; i < s; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int id;
            scanf("%d", &id);
            id--;
            sw[i] = sw[i] ^ light[id];
        }
    }

    int pref = min(s, BOUND);

    for (int mask = 0; mask < (1 << pref); mask++)
    {
        Hash cur = Hash();
        for (int i = 0; i < pref; i++)
            if (mask & (1 << i))
                cur = cur ^ sw[i];
        int curans = __builtin_popcount(mask);
        auto it = prec.find(cur);
        if (it == prec.end() || curans < it->second)
            prec[cur] = curans;
    }

    int suff = s - pref;

    for (int iter = 0; iter < d; iter++)
    {
        int k;
        scanf("%d", &k);
        Hash cur = Hash();
        for (int i = 0; i < k; i++)
        {
            int id;
            scanf("%d", &id);
            id--;
            cur = cur ^ light[id];
        }
//        eprintf("!!! suff = %d\n", suff);

        int ans = -1;
        for (int mask = 0; mask < (1 << suff); mask++)
        {
            Hash h = cur;
            for (int i = 0; i < suff; i++)
                if (mask & (1 << i))
                    h = h ^ sw[pref + i];
            auto it = prec.find(h);
            if (it == prec.end())
                continue;
            int curans = __builtin_popcount(mask) + it->second;
            if (ans == -1 || curans < ans)
                ans = curans;
        }
//        eprintf("??\n");
        printf("%d\n", ans);
    }

	return 0;
}