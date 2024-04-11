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



const int N = (int) 4e5 + 100;

int A[N], B[N];

int mxr[N];

int getAns(int a0, int a1, int b0, int b1)
{
    return min(a0 + b1, a1 + b0);
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    vector <pair<pair<int, int>, int>> v;
    
    int MXL = 0, MNR = N;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        A[i] = a;
        B[i] = b;
        MXL = max(MXL, min(a, b));
        MNR = min(MNR, max(a, b));
        v.emplace_back(make_pair(min(a, b), max(a, b)), i);
    }
    if (MXL > MNR)
    {
        printf("-1\n");
        return 0;
    }
    sort(v.begin(), v.end());

    for (int i = n - 1; i >= 0; i--)
        mxr[i] = max(mxr[i + 1], v[i].first.second);

    int xa = N, xb = N;

    int ans = 0;
    int cnta_0 = 0, cnta_1 = 0, cntb_0 = 0, cntb_1 = 0;
    for (int i = 0; i < n; i++)
    {
        int id = v[i].second;
        int r = v[i].first.second;
        if (mxr[i] < xa) {
            xa = N;
            xb = N;
            ans += getAns(cnta_0, cnta_1, cntb_0, cntb_1);
            //ans += min(cnta, cntb);
            xa = r;
            cnta_0 = 0;
            cnta_1 = 0;
            cntb_0 = 0;
            cntb_1 = 0;
            //cnta_0++;
            if (B[id] == r)
                cnta_0++;
            else
                cnta_1++;
        }
        else if (r < xa) {
            xa = r;
            if (B[id] == r)
                cnta_0++;
            else
                cnta_1++;
        }
        else if (r < xb) {
            xb = r;
            if (B[id] == r)
                cntb_0++;
            else
                cntb_1++;
        }
        else {
            printf("-1\n");
            return 0;
        }
    }
    ans += getAns(cnta_0, cnta_1, cntb_0, cntb_1);

    printf("%d\n", ans);

	return 0;
}