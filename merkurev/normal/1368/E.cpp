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
vector <int> g[N];
vector <int> ord;
int pos[N];
bool used[N];

int state[N];

const int S_NEW = 0;
const int S_REMOVE = 1;
const int S_KEEP = 2;
const int S_Q = 3;

void dfsOrd(int v)
{
    used[v] = true;
    for (int to : g[v])
        if (!used[to])
            dfsOrd(to);

    ord.push_back(v);
}

void solve()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        state[i] = S_NEW;
        used[i] = false;
        g[i].clear();
    }
    ord.clear();
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
    }
    for (int i = 0; i < n; i++)
        if (!used[i])
            dfsOrd(i);
    reverse(ord.begin(), ord.end());
    for (int i = 0; i < n; i++)
        pos[ord[i]] = i;

    for (int i = 0; i < n; i++)
    {
        int v = ord[i];
        if (state[v] == S_REMOVE)
            continue;
        if (state[v] == S_Q)
        {
            state[v] = S_KEEP;
            for (int to : g[v])
                state[to] = S_REMOVE;
            continue;
        }
        state[v] = S_KEEP;
        for (int to : g[v])
            if (state[to] != S_REMOVE)
                state[to] = S_Q;
    }
    vector <int> ans;
    for (int i = 0; i < n; i++)
        if (state[i] == S_REMOVE)
            ans.push_back(i);
    printf("%d\n", (int) ans.size());
    for (int x : ans)
        printf("%d ", x + 1);
    printf("\n");
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