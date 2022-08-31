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

int mx;

const int N = (int) 1e5 + 100;
vector <int> g[N];

vector <pair <int, int>> ans;

void solve(int v, int par, int t)
{
    int tin = t;
    ans.emplace_back(v, t);

    int cntCh = (int) g[v].size() - 1;
    if (v == par)
        cntCh++;

    int goUp = mx - t;
    int goDown = max(0, cntCh - goUp);
    int tpTo = tin - 1 - goDown;

    for (int to : g[v])
    {
        if (to == par)
            continue;
        if (t == mx)
        {
            t = tpTo;
            ans.emplace_back(v, t);
        }
        t++;
        solve(to, v, t);
        ans.emplace_back(v, t);
    }
    if (t != tin - 1 && par != v)
    {
        t = tin - 1;
        ans.emplace_back(v, t);
    }
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
        mx = max(mx, (int) g[i].size());

    solve(0, 0, 0);

    printf("%d\n", (int) ans.size());
    for (auto p : ans)
        printf("%d %d\n", p.first + 1, p.second);


	return 0;
}