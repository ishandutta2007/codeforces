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

const int MOD = (int) 1e9 + 7;
void sadd(int &a, int b)
{
    a += b;
    if (a >= MOD) a -= MOD;
}
int add(int a, int b)
{
    sadd(a, b);
    return a;
}
void ssub(int &a, int b)
{
    a -= b;
    if (a < 0) a += MOD;
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
int fpow(int x, long long n)
{
    if (n == 0) return 1;
    int a = fpow(x, n >> 1);
    a = mul(a, a);
    if (n & 1) a = mul(a, x);
    return a;
}


const int N = (int) 5e5 + 100;

map <long long, int> id;
int sz = 0;

int getId(long long x)
{
    if (id.count(x) == 0) 
    {
        id[x] = sz++;
    }
    return id[x];
}

vector <pair <int, int> > edges[N];

int par[N];
int csz[N];
int getP(int x)
{
    if (x == par[x]) return x;
    return par[x] = getP(par[x]);
}

bool uni(int a, int b)
{
    a = getP(a);
    b = getP(b);
    if (a == b) 
        return false;
    if (csz[b] > csz[a]) swap(a, b);
    csz[a] += csz[b];
    par[b] = a;
    return true;
}

void clear(int v)
{
    par[v] = v;
    csz[v] = 1;
}

long long a[N];
int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < n; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        x--;
        y--;
        long long val = a[x] ^ a[y];
        edges[getId(val)].emplace_back(x, y);
    }

    int cnt = sub(fpow(2, k), sz);
    int ans = mul(cnt, fpow(2, n));

    for (int i = 0; i < n; i++)
        clear(i);

    for (int i = 0; i < sz; i++)
    {
        int comp = n;
        for (auto p : edges[i] )
            if (uni(p.first, p.second))
                comp--;
        for (auto p : edges[i])
        {
            clear(p.first);
            clear(p.second);
        }
        sadd(ans, fpow(2, comp));
    }
    printf("%d\n", ans);


	return 0;
}