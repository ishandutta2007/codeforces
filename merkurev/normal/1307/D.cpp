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


const int N = (int) 2e5 + 100;
int is[N];

vector <int> g[N];

void getD(int d[], int s)
{
    for (int i = 0; i < N; i++)
        d[i] = N;
    d[s] = 0;

    vector <int> qu;
    qu.push_back(s);

    for (int i = 0; i < (int) qu.size(); i++)
    {
        int v = qu[i];

        for (int to : g[v])
            if (d[to] > d[v] + 1)
            {
                d[to] = d[v] + 1;
                qu.push_back(to);
            }
    }
}

struct V
{
    int ds, dt;

    V(int _ds, int _dt) : ds(_ds), dt(_dt) {}

    bool operator < (const V &A) const
    {
        return dt - ds < A.dt - A.ds;
    }
};

int ds[N], dt[N];


vector <V> v;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);

    for (int i = 0; i < k; i++)
    {
        int x;
        scanf("%d", &x);
        x--;
        is[x] = 1;
    }

    bool ch = true;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
        if (is[a] && is[b])
        {
            ch = false;
        }
    }

    getD(ds, 0);
    getD(dt, n - 1);

    if (!ch)
    {
        printf("%d\n", ds[n - 1]);
        return 0;
    }

    for (int i = 0; i < n; i++)
        if (is[i])
        {
            eprintf("%d: %d %d\n", i, ds[i], dt[i]);
            v.emplace_back(ds[i], dt[i]);
        }

    sort(v.begin(), v.end());

    int ans = 0;
    int mxt = -N;
    for (auto p : v)
    {
        ans = max(ans, mxt + p.ds + 1);
        mxt = max(mxt, p.dt);
    }

    printf("%d\n", min(ans, ds[n - 1]));

	return 0;
}