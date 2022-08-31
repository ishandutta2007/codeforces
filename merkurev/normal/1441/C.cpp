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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;


const int K = 3000;
const int N = 3005;

int sz[N];
int a[N][N];
long long sum[N];


struct Seg
{
    int l, r, id;

    Seg() : l(), r(), id() {}

    Seg(int _l, int _r, int _id) : l(_l), r(_r), id(_id) {}
};

struct Dp
{
    long long dp[N];

    Dp()
    {
        memset(dp, 0, sizeof dp);
    }

    void operator += (int id)
    {
        for (int i = N - sz[id] - 1; i >= 0; i--)
            dp[i + sz[id]] = max(dp[i + sz[id]], dp[i] + sum[id]);
    }
};

int k;

long long ans = 0;

void solve(int l, int r, vector <Seg> &segs, Dp &dp)
{
    if (l == r)
    {
        long long psum = 0;
        for (int i = 0; i <= min(k, sz[l]); i++)
        {
            if (i != 0)
                psum += a[l][i - 1];
            ans = max(ans, psum + dp.dp[k - i]);
        }
        return;
    }
    int m = (l + r) / 2;
    vector <Seg> lsegs, rsegs;
    Dp ldp = dp, rdp = dp;

    for (Seg seg : segs)
    {
        if (seg.l <= l && seg.r >= m)
           ldp += seg.id;
        else if (seg.l <= m)
            lsegs.push_back(seg);

        if (seg.l <= m + 1 && seg.r >= r)
            rdp += seg.id;
        else if (seg.r >= m + 1)
            rsegs.push_back(seg);
    }

    solve(l, m, lsegs, ldp);
    solve(m + 1, r, rsegs, rdp);

}

vector <Seg> segs;

void addSeg(int l, int r, int id)
{
    segs.push_back(Seg(l, r, id));
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int t;
        scanf("%d", &t);
        for (int j = 0; j < t; j++)
        {
            int x;
            scanf("%d", &x);
            if (j < K)
            {
                sum[i] += x;
                a[i][j] = x;
            }
        }
        sz[i] = min(t, K);
    }

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            addSeg(0, i - 1, i);
        if (i != n - 1)
            addSeg(i + 1, n - 1, i);
    }

    Dp dp = Dp();
    solve(0, n - 1, segs, dp);

    printf("%lld\n", ans);

	return 0;
}