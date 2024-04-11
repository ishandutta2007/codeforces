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


const int N = 4005;
int a[N][N];
long long psum[N][N];
char str[3 * N];
long long gsum[N][N];

long long _getSum(long long l, long long r)
{
    r++;
    long long ans = psum[r][r] - psum[r][l] - psum[l][r] + psum[l][l];
    return ans;
}

long long getSum(long long l, long long r)
{
    return gsum[l][r];
}

struct Func
{
    int id;
    long long sy;
    int k;

    Func(int _id, long long _sy, int _k) : id(_id), sy(_sy), k(_k) {}

    pair <long long, int> getVal(int pos)
    {
        return make_pair(sy + getSum(id, pos - 1), k);
    }

    bool operator < (const Func &A) const
    {
        if (id == A.id) return false; // TODO
        return false;
    }
};

struct Hull
{
    vector <pair <int, Func>> st;
    int ptr;

    Hull () : st(), ptr() {}

    void addFunc(int s, Func func, int n)
    {
        while (!st.empty() && st.back().first >= s)
        {
            int x = st.back().first;
            if (func.getVal(x) <= st.back().second.getVal(x))
                st.pop_back();
            else
                break;
        }
        ptr = min(ptr, (int) st.size());
        
        if (st.empty())
        {
            st.emplace_back(s, func);
            return;
        }
        int lb = max(s - 1, st.back().first), rb = n + 1;
        while (rb - lb > 1)
        {
            int mb = (lb + rb) / 2;
            if (func.getVal(mb) <= st.back().second.getVal(mb))
                rb = mb;
            else
                lb = mb;
        }
        if (rb != n + 1)
            st.emplace_back(rb, func);
    }

    pair <long long, int> getMin(int pos)
    {
        while (ptr + 1 < (int) st.size() && st[ptr + 1].first <= pos)
            ptr++;
        return st[ptr].second.getVal(pos);
        //auto it = upper_bound(st.begin(), st.end(), make_pair(pos, Func(0,0,0)));
        //it--;
        //return it->second.getVal(pos);
    }
};

pair <long long, int> solve(int n, long long fine)
{
    Hull hull = Hull();
    hull.addFunc(1, Func(0, fine, 1), n);

    for (int i = 1; i < n; i++)
    {
        auto p = hull.getMin(i);
        p.first += fine;
        p.second++;
        hull.addFunc(i + 1, Func(i, p.first, p.second), n);
    }
    auto ans = hull.getMin(n);
    return ans; 
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
	{
		scanf(" %[^\n]", str);
		for (int j = 0; j < n; j++)
			a[i][j] = str[j * 2] - '0';
	}


    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            psum[i + 1][j + 1] = psum[i + 1][j] + psum[i][j + 1] + a[i][j] - psum[i][j];

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            psum[i][j] *= k;

    for (int i = 0; i <= n; i++)
        for (int j = i; j <= n; j++)
            gsum[i][j] = _getSum(i, j);

    long long lb = -1, rb = (long long) n * (long long) n * (long long) k * 10LL;

    while (rb - lb > 1)
    {
        long long mb = (lb + rb) / 2;
        auto p = solve(n, mb);
        if (p.second <= k)
            rb = mb;
        else
            lb = mb;
    }

    auto p = solve(n, rb);
    long long ans = p.first - p.second * rb;
    ans -= (k - p.second) * rb;
    //if (p.second < k)
    //    ans = rb;
    printf("%lld\n", ans / k / 2);

	return 0;
}