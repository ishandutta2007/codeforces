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


const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0)
        a += MOD;
}
int sub(int a, int b)
{
    ssub(a, b);
    return a;
}
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}

const int N = (int) 5e5 + 100;
bool good[N];
int sz[N];
int par[N];

int getP(int v)
{
    if (v == par[v])
        return v;
    return par[v] = getP(par[v]);
}
bool uni(int a, int b)
{
    a = getP(a);
    b = getP(b);
    if (a == b)
        return false;
    if (sz[a] < sz[b])
        swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    good[a] |= good[b];
    return true;
}

vector <int> ans;


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int _n, m;
    scanf("%d%d", &_n, &m);

    for (int i = 0; i < m; i++)
    {
        sz[i] = 1;
        par[i] = i;
    }

    for (int i = 0; i < _n; i++)
    {
        int k;
        scanf("%d", &k);
        if (k == 1)
        {
            int x;
            scanf("%d", &x);
            x--;
            x = getP(x);
            if (!good[x])
            {
                good[x] = true;
                ans.push_back(i);
            }
        }
        else
        {
            int a, b;
            scanf("%d%d", &a, &b);
            a--;
            b--;
            a = getP(a);
            b = getP(b);
            if (a != b && (!good[a] || !good[b]))
            {
                uni(a, b);
                ans.push_back(i);
            }
        }
    }
    int bad = 0;
    for (int i = 0; i < m; i++)
    {
        if (par[i] == i && !good[i])
            bad++;
    }
    int ansx = 1;
    for (int i = 0; i < m - bad; i++)
        ansx = mul(ansx, 2);
    
    //sort(ans.begin(), ans.end());
    printf("%d %d\n", ansx, (int) ans.size());
    for (int x : ans)
        printf("%d ", x + 1);
    printf("\n");


	return 0;
}