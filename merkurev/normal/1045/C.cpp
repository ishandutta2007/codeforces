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
bool isV[N];
int timer = 146;
int tin[N], tup[N];

vector <int> st;
int compCnt;
int compId[N];
vector <int> G[N];

void dfs(int v, int par)
{
    st.push_back(v);
    tin[v] = timer++;
    tup[v] = tin[v];
    int cntDown = 0;
    for (int to : g[v])
    {
        if (to == par) continue;
        if (tin[to] != 0)
        {
            tup[v] = min(tup[v], tin[to]);
            continue;
        }
        cntDown++;
        int sz = (int) st.size();
        dfs(to, v);
        tup[v] = min(tup[v], tup[to]);
        if (tup[to] >= tin[v] )
        {
            // act with root
            vector <int> comp;
            while ((int)st.size() > sz)
            {
                comp.push_back(st.back());
                st.pop_back();
            }
            comp.push_back(v);
            if (v != par) isV[v] = true;
            for (int x : comp)
                compId[x] = compCnt;
            vector <int> vs;
            for (int x : comp)
                if (isV[x])
                    vs.push_back(x);
            if (!isV[v])
                vs.push_back(v);
            for (int x : vs)
            {
                G[x].push_back(compCnt);
                G[compCnt].push_back(x);
            }
            compCnt++;
        }
    }
    if (v == par && cntDown > 1)
        isV[v] = true;
//    eprintf("%d: %d\n", v, isV[v]);
}


const int LOG = 18;
int GH[N];
int GP[N][LOG];
void dfsG(int v, int par, int ch)
{
//    eprintf("%d -> %d : %d\n", par, v, ch);
    GH[v] = ch;
    GP[v][0] = par;
    for (int i = 1; i < LOG; i++)
        GP[v][i] = GP[GP[v][i - 1]][i - 1];
    for (int to : G[v])
    {
        if (to == par) continue;
        dfsG(to, v, ch + 1);
    }
}

int goUpG(int v, int d)
{
    for (int i = 0; i < LOG; i++)
        if (d & (1 << i))
            v = GP[v][i];
    return v;
}

int lcaG(int a, int b)
{
    if (GH[a] < GH[b]) 
        swap(a, b);
    a = goUpG(a, GH[a] - GH[b]);
    if (a == b) 
        return a;
    for (int i = LOG - 1; i >= 0; i--)
        if (GP[a][i] != GP[b][i])
        {
            a = GP[a][i];
            b = GP[b][i];
        }
    return GP[a][0];
}

int getDist(int a, int b)
{
    int l = lcaG(a, b);
//    eprintf("lca(%d, %d) = %d\n", a, b, l);
    return GH[a] + GH[b] - 2 * GH[l];
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, q;
    scanf("%d%d%d", &n, &m, &q);
    compCnt = n;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0);
    int s = 0;
    while (G[s].empty() && s < N) s++;
    dfsG(s, s, 0);
    for (int i = 0; i < n; i++)
        if (isV[i])
            compId[i] = i;

//    for (int i = 0; i < n; i++)
//        eprintf("%d) %d\n", i, compId[i]);
    for (int it = 0; it < q; it++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        int ca = compId[a];
        int cb = compId[b];
        int dist = getDist(ca, cb);
//        eprintf("ca = %d, cb = %d, dist = %d\n", ca, cb, dist);
        int ans = 0;
        if (ca == cb) ans = 1;
        else
        {
            if (!isV[a] )
            {
                dist--;
                ans++;
            }
            if (!isV[b])
            {
                dist--;
                ans++;
            }
            ans += dist / 2;
        }
        printf("%d\n", ans);
    }



	return 0;
}