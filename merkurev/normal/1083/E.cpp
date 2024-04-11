#ifndef LOCAL
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma,tune=native")
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


struct Rect
{
    long long x, y, a;
    Rect() : x(), y(), a() {}
    Rect(long long _x, long long _y, long long _a) : x(_x), y(_y), a(_a) {}

    long long s()
    {
        return x * 1LL * y;
    }

    bool operator < (const Rect &A) const
    {
        return x < A.x;
    }
};

vector <Rect> v;

const long long MX = (long long) 2e9;

struct Line
{
    long long y0, k;
    Line(long long _y0, long long _k) : y0(_y0), k(_k) {}

    long long getVal(long long x) const
    {
        return y0 + k * x;
    }
    long long startDominate(const Line &A) const
    {
        long long dk = k - A.k;
        return (A.y0 - y0 + dk - 1) / dk;
    }
    void eprint()
    {
        eprintf("%lld + %lld x\n", y0, k);
    }
};


struct Hull
{
    vector <pair <long long, Line>> st;
    int ptr;

    void addLine(Line cur)
    {
        //cur.eprint();
        while (!st.empty())
        {
            if (cur.getVal(st.back().first) >= st.back().second.getVal(st.back().first))
                st.pop_back();
            else
                break;
        }
        if (st.empty())
        {
            ptr = 0;
            st.emplace_back(MX, cur);
            return;
        }
        ptr = min(ptr, (int) st.size() - 1);
        Line A = st.back().second;
        if (cur.getVal(0) <= A.getVal(0))
            return;
        long long sx = A.startDominate(cur) - 1;
        st.emplace_back(sx, cur);
    }

    long long getVal(long long x)
    {
        while (ptr + 1 < (int) st.size() && x <= st[ptr + 1].first)
            ptr++;
        return st[ptr].second.getVal(x);
    }
};

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        long long x, y, a;
        scanf("%lld%lld%lld", &x, &y, &a);
        v.emplace_back(x, y, a);
    }
    sort(v.begin(), v.end());

    Hull H = Hull();
    H.addLine(Line(0, 0));
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        long long cur = H.getVal(v[i].y) + v[i].s() - v[i].a;
        ans = max(ans, cur);
        H.addLine(Line(cur, -v[i].x));
    }
    printf("%lld\n", ans);

	return 0;
}