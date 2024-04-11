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

const int MOD = 998244353;


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
int fpow(int x, int n)
{
    if (n == 0)
        return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1)
        a = mul(a, x);
    return a;
}

int half;
    
const int N = 305;
vector <int> g[N];
int ls[N];


struct Ans
{
    vector <int> bdown;
    vector <int> dup;

    Ans()
    {
        bdown.clear();
        dup.clear();
        bdown.push_back(half);
        dup.push_back(half);
    }

    int no()
    {
        int ans = 0;
        for (int x : bdown)
            sadd(ans, x);
        return ans;
    }

    void eprint()
    {
        int X = 1 << (int) bdown.size();
        eprintf("bdown: ");
        for (int x : bdown)
            eprintf("%d ", mul(x, X)); eprintf("\n");
        eprintf("dup: ");
        for (int x : dup)
            eprintf("%d ", mul(x, X)); eprintf("\n");
    }
};

Ans merge(Ans av, Ans ato, int r)
{
    Ans ans = Ans();
    ans.bdown.clear();
    ans.dup.clear();

    ans.bdown.resize(max(av.bdown.size(), ato.bdown.size() + 1));
    ans.dup.resize(max(av.bdown.size(), ato.bdown.size() + 1));

    for (int i = 0; i < (int) av.dup.size(); i++)
    {
        for (int j = 0; j < (int) ato.bdown.size(); j++)
        {
            int cur = mul(av.dup[i], ato.bdown[j]);
            if (i + j >= r)
                sadd(ans.dup[i], cur);
            else
                sadd(ans.bdown[j + 1], cur);
        }
        for (int j = 0; j < min(r, (int) ato.dup.size()); j++)
        {
            int cur = mul(av.dup[i], ato.dup[j]);
            sadd(ans.dup[max(i, j + 1)], cur);
        }
    }
    for (int i = 0; i < (int) av.bdown.size(); i++)
    {
        for (int j = 0; j < (int) ato.bdown.size(); j++)
        {
            int cur = mul(av.bdown[i], ato.bdown[j]);
            sadd(ans.bdown[min(i, j + 1)], cur);
        }
        for (int j = 0; j < min(r, (int) ato.dup.size()); j++)
        {
            int cur = mul(av.bdown[i], ato.dup[j]);
            if (i + j >= r)
                sadd(ans.dup[j + 1], cur);
            else
                sadd(ans.bdown[i], cur);
        }
    }
    if ((int) ans.dup.size() > r)
        ans.dup[r] = 0;

    return ans;
}

Ans ans[N];

void solve(int v, int par, int r)
{
    ans[v] = Ans();

    for (int to : g[v])
    {
        if (to == par)
            continue;
        solve(to, v, r);
        ans[v] = merge(ans[v], ans[to], r);
    }
    //eprintf("v = %d, r = %d\n", v, r);
    //ans[v].eprint();
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n;

    half = fpow(2, MOD - 2);

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

    for (int r = 0; r <= n; r++)
    {
        // calc prob ans < r
        solve(0, 0, r);
        ls[r] = ans[0].no();
        //eprintf("%d) %d [%d]\n", r, ls[r], mul(ls[r], 1 << n));
    }
    ls[n + 1] = 1;
    int answer = 0;
    for (int r = 0; r <= n + 1; r++)
    {
        int cur = ls[r];
        if (r > 0)
            ssub(cur, ls[r - 1]);

        //eprintf("%d * %d\n", mul(cur, 1 << n), r - 1);

        cur = mul(cur, sub(r, 1));
        sadd(answer, cur);
    }
    printf("%d\n", answer);

	return 0;
}