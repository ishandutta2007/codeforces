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
vector <int> g[N], rg[N];

bool usedG[N], usedRG[N];

void dfs(int x)
{
    if (usedG[x])
        return;
    usedG[x] = true;
    for (int to : g[x])
        dfs(to);
}

void dfsR(int x)
{
    if (usedRG[x])
        return;
    usedRG[x] = true;
    for (int to : rg[x])
        dfsR(to);
}

vector <int> ord;
bool used[N];

void dfsOrd(int v)
{
    used[v] = true;
    for (int to : g[v])
        if (!used[to])
            dfsOrd(to);
    ord.push_back(v);
}

int pos[N];

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        if (!used[i])
            dfsOrd(i);

    for (int i = 0; i < n; i++)
        pos[ord[i]] = i;

    for (int v = 0; v < n; v++)
        for (int to : g[v])
            if (pos[to] > pos[v])
            {
                printf("-1\n");
                return 0;
            }


    
    int ans = 0;
    string answer;
    for (int i = 0; i < n; i++)
    {
        int x = i;

        if (usedG[x] || usedRG[x])
        {
            answer.push_back('E');
        }
        else
        {
            ans++;
            answer.push_back('A');
        }
        dfs(x);
        dfsR(x);
    }

    printf("%d\n%s\n", ans, answer.c_str());

	return 0;
}