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

struct Edge
{
    int a, b, c;
    int id;

    Edge() : a(), b(), c(), id() {}

    void read(int _id)
    {
        id = _id;
        scanf("%d%d%d", &a, &b, &c);
        a--;
        b--;
    }

    bool operator < (const Edge &A) const
    {
        return c < A.c;
    }
};

const int N = (int) 5e5 + 100;
Edge edge[N], edge_by_id[N];
bool canBe[N];
int par[N];
int sz[N];
bool used[N];

vector <int> g[N];

int getPar(int v)
{
    if (v == par[v] ) return v;
    return par[v] = getPar(par[v] );
}

bool uni(int a, int b)
{
    a = getPar(a);
    b = getPar(b);
    if (a == b) return false;
    if (sz[a] < sz[b] ) swap(a, b);
    sz[a] += sz[b];
    par[b] = a;
    return true;
}

bool dfs(int v, int parx)
{
    used[v] = true;
    for (int to : g[v] )
    {
        if (to == parx) continue;
        if (used[to] ) return false;
        if (!dfs(to, v)) return false;
    }
    return true;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif


    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
        edge[i].read(i);
    sort(edge, edge + m);

    for (int i = 0; i < n; i++)
    {
        par[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; )
    {
        int j = i;
        while (j < m && edge[j].c == edge[i].c) j++;
        for (int h = i; h < j; h++)
        {
            int a = edge[h].a;
            int b = edge[h].b;

            a = getPar(a);
            b = getPar(b);

            edge[h].a = a;
            edge[h].b = b;

            eprintf("%d : %d %d\n", edge[h].id, edge[h].a, edge[h].b);
        }
        for (int h = i; h < j; h++)
        {
            int a = edge[h].a;
            int b = edge[h].b;

            uni(a, b);
        }

        i = j;
    }

    for (int i = 0; i < m; i++)
    {
        edge_by_id[edge[i].id] = edge[i];
    }
    
    int q;
    scanf("%d", &q);
    for (int it = 0; it < q; it++)
    {
        int k;
        scanf("%d", &k);
        vector <Edge> v;
        bool ans = true;

        for (int i = 0; i < k; i++)
        {
            int id;
            scanf("%d", &id);
            id--;
            v.push_back(edge_by_id[id] );
        }
    
        sort(v.begin(), v.end() );
        for (int i = 0; i < (int) v.size();)
        {
            int j = i;
            while (j < (int) v.size() && v[i].c == v[j].c) j++;

            for (int h = i; h < j; h++)
            {
                g[v[h].a].push_back(v[h].b);
                g[v[h].b].push_back(v[h].a);
            }
            
            for (int h = i; h < j; h++)
            {
                if (!used[v[h].a] )
                    ans &= dfs(v[h].a, -1);
                if (!used[v[h].b] )
                    ans &= dfs(v[h].b, -1);
            }
            
            for (int h = i; h < j; h++)
            {
                used[v[h].a] = false;
                used[v[h].b] = false;
                g[v[h].a].clear();
                g[v[h].b].clear();
            }

            i = j;
        }

        printf(ans ? "YES\n" : "NO\n");
    }

	return 0;
}