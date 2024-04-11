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

struct Node
{
    int l, r;

    Node() : l(-1), r(-1) {}
};

const int N = (int) 2e5 + 100;
Node nodes[N];

map <int, int> qs;

int a[N], b[N];

void solve()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        a[i]--;
    }
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &b[i]);
        b[i]--;
    }
    qs.clear();
    for (int i = 0; i < k; i++)
        qs[b[i]]++;
    for (int i = 0; i < n; i++)
    {
        nodes[a[i]].l = (i == 0) ? -1 : a[i - 1];
        nodes[a[i]].r = (i == n - 1) ? -1 : a[i + 1];
    }

    int ans = 1;
    for (int i = 0; i < k; i++)
    {
        qs[b[i]]--;
        int cnt = 0;
        for (int x : {nodes[b[i]].l, nodes[b[i]].r})
        {
            if (x != -1 && qs[x] == 0)
                cnt++;
        }
        ans = mul(ans, cnt);
        if (nodes[b[i]].l != -1)
            nodes[nodes[b[i]].l].r = nodes[b[i]].r;
        if (nodes[b[i]].r != -1)
            nodes[nodes[b[i]].r].l = nodes[b[i]].l;
    }
    printf("%d\n", ans);
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