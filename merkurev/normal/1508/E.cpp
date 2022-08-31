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
#include <queue>
#include <random>
#include <ctime>
#include <chrono>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif


typedef long long int int64;
typedef long long int ll;
typedef long long unsigned ull;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
	return (ull)rng() % B;
}

const int N = (int) 3e5 + 100;
int a[N];
int pos[N];

vector <int> ch[N];
int par[N];

int h[N];
int mn[N], mx[N];

int id[N];
int cntRm[N];

void dfsH(int v, int vh)
{
    h[v] = vh;
    mn[v] = a[v];
    mx[v] = a[v];
    for (int to : ch[v])
    {
        dfsH(to, vh + 1);
        mn[v] = min(mn[v], mn[to]);
        mx[v] = max(mx[v], mx[to]);
    }
}

void dfsId(int v, int &cid)
{
    id[v] = ++cid;

    for (int to : ch[v])
        dfsId(to, cid);
}

bool cmpMn(int x, int y)
{
    return mn[x] < mn[y];
}

bool check(int v, int x, int &cid)
{
    if (a[v] < x)
        return true;
    if (a[v] != cid)
        return false;
    cid++;
    for (int to : ch[v])
    {
        if (!check(to, x, cid))
            return false;
    }
    return true;
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
    {
        scanf("%d", &a[i]);
        a[i]--;
        pos[a[i]] = i;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        par[y] = x;
        ch[x].push_back(y);
    }

    dfsH(0, 0);
    for (int i = 0; i < n; i++)
    {
        sort(ch[i].begin(), ch[i].end(), cmpMn);
        for (int j = 0; j + 1 < (int) ch[i].size(); j++)
        {
            eprintf("%d vs %d\n", mx[ch[i][j]], mn[ch[i][j + 1]]);
            if (mx[ch[i][j]] >= mn[ch[i][j + 1]])
            {
                printf("NO\n");
                return 0;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        int v = pos[i];
        ans += h[v];
        if (cntRm[v] != (int)ch[v].size())
        {
            while (v != 0)
            {
                swap(a[v], a[par[v]]);
                v = par[v];
            }

            int cid = i;
            if (!check(0, i, cid))
            {
                printf("NO\n");
                return 0;
            }
            break;
        }

        if (v != 0)
            cntRm[par[v]]++;
    }

    int cid = 0;
    dfsId(0, cid);


    printf("YES\n%lld\n", ans);
    for (int i = 0; i < n; i++)
        printf("%d ", id[i]);
    printf("\n");

	return 0;
}