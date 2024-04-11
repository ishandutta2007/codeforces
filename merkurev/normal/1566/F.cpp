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
long long p[N];

const long long INF = (long long) 1e12;


void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%lld", &p[i]);
    p[n++] = INF;
    p[n++] = -INF;
    sort(p, p + n);

    vector <pair <long long, long long>> v;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        v.emplace_back(a, -b);
    }
    sort(v.begin(), v.end());
    for (auto &cur : v)
        cur.second = -cur.second;

    vector <pair <long long, long long>> st;
    for (auto cur : v)
    {
        while (!st.empty() && cur.second <= st.back().second)
            st.pop_back();
        st.push_back(cur);
    }
    v = st;

    int ptr = 0;
    vector <pair <long long, long long>> prv, cur;
    vector <long long> prv_dp, cur_dp;

    prv.push_back({p[0], p[0]});
    prv_dp.push_back(0);

    for (int it = 0; it + 1 < n; it++)
    {
        long long pa = p[it];
        long long pb = p[it + 1];

        cur.clear();
        while (ptr < (int) v.size() && v[ptr].first <= pa)
            ptr++;
        //eprintf("[%lld, %lld]:\n", pa, pb);

        cur.push_back({pa, pa});
        while (ptr < (int) v.size() && v[ptr].second < pb)
        {
            //eprintf("%lld %lld\n", v[ptr].first, v[ptr].second);
            cur.push_back(v[ptr]);
            ptr++;
        }
        cur.push_back({pb, pb});

        long long bst = INF;
        for (int i = 0; i < (int) prv.size(); i++)
        {
            //eprintf("%lld + 2 * (%lld - %lld)\n", prv_dp[i], pa, prv[i].second);
            bst = min(bst, prv_dp[i] + 2 * (pa - prv[i].second));
        }

        long long bst_fin = INF;
        for (int i = 0; i < (int) prv.size(); i++)
            bst_fin = min(bst_fin, prv_dp[i] + (pa - prv[i].second));

        //eprintf("bst = %lld, bst_fin = %lld\n", bst, bst_fin);
    
        cur_dp.clear();
        for (int i = 0; i < (int) cur.size(); i++)
            cur_dp.push_back(INF);
        
        //eprintf("bst = %lld, bst_fin = %lld\n", bst, bst_fin);
        //eprintf("cur_dp: ");
        for (int i = 0; i + 1 < (int) cur.size(); i++)
        {
            long long val = min(
                    bst + (cur[i].first - pa),
                    bst_fin + 2 * (cur[i].first - pa)
                    );
            cur_dp[i + 1] = val;
            //eprintf("%lld ", val);
        }
        //eprintf("\n");

        prv = cur;
        prv_dp = cur_dp;
    }
    
    printf("%lld\n", prv_dp.back());
    
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