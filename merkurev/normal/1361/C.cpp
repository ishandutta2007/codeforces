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


const int N = (int) (1 << 20) + 100;
int a[N][2];
bool used[N];

vector <int> g[N];

int getVal(int x, int ans)
{
    return x & ((1 << ans) - 1);
}

vector <int> ord;
vector <int> bst;

void dfs(int v, int ans)
{
    while (!g[v].empty())
    {
        int id = g[v].back();
        g[v].pop_back();
        if (used[id])
            continue;
        used[id] = true;
        int to = getVal(a[id][0], ans) ^ getVal(a[id][1], ans) ^ v;
        dfs(to, ans);
        ord.push_back(id);
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
    for (int i = 0; i < n; i++)
        for (int t = 0; t < 2; t++)
            scanf("%d", &a[i][t]);

    for (int i = 0; i < n; i++)
        bst.push_back(i);

    int lb = 0, rb = 21;
    while (rb - lb > 1)
    {
        int ans = (lb + rb) / 2;
        
        for (int i = 0; i < (1 << ans); i++)
            g[i].clear();

        for (int i = 0; i < n; i++)
        {
            used[i] = false;
            int v = getVal(a[i][0], ans);
            int u = getVal(a[i][1], ans);
            g[v].push_back(i);
            g[u].push_back(i);
        }
        int s = getVal(a[0][0], ans);

        bool good = true;
        for (int i = 0; i < (1 << ans); i++)
            if ((int) g[i].size() % 2)
                good = false;

        ord.clear();
        if (good)
            dfs(s, ans);

        if ((int)ord.size() == n)
        {
            bst = ord;
            lb = ans;
        }
        else
            rb = ans;
    }

    ord = bst;
    int ans = lb;

    int cur = getVal(a[0][0], ans);

    printf("%d\n", ans);
    for (int id : ord)
    {
        if (getVal(a[id][0], ans) == cur)
            printf("%d %d ", 2 * id + 1, 2 * id + 2);
        else
            printf("%d %d ", 2 * id + 2, 2 * id + 1);
        cur ^= getVal(a[id][0], ans) ^ getVal(a[id][1], ans);
    }

    printf("\n");

	return 0;
}