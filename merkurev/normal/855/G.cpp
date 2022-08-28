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


long long sqr(long long x)
{
    return x * x;
}

const int N = (int) 1e5 + 100;
vector <int> g[N];

int p[N], sz[N], up[N];

int tp[N], tsz[N], th[N];

int n;
long long sumS2[N];
long long answer;


void fixAnswer(int pid, int k)
{
    answer -= k * sumS2[pid] * sz[pid];
    answer += k * sqr(n - sz[pid] ) * sz[pid];
//    eprintf("answer = %lld\n", answer);
    answer += k * (sz[pid] * 1LL * (sz[pid] - 1) * 1LL * (sz[pid] - 2) );
    answer += 2 * k * (sz[pid] * 1LL * (sz[pid] - 1) * (n - sz[pid] ) );
}

int getP(int a)
{
    if (a == p[a] ) return a;
    return p[a] = getP(p[a] );
}

bool uni(int a, int b)
{
//    eprintf("%d - %d\n", a, b);
    int ina = a;

    a = getP(a);
    b = getP(b);
    if (a == b) return false;
    
   
    fixAnswer(a, -1);
    fixAnswer(b, -1);


    // tp[ina] = inb

    if (sz[a] < sz[b] ) swap(a, b);

    p[b] = a;
    sz[a] += sz[b];
    
    sumS2[a] += sumS2[b];
    sumS2[a] -= sqr(n - tsz[ina] );
    sumS2[a] -= sqr(tsz[ina] );

    if (th[up[b] ] < th[up[a] ] )
        up[a] = up[b];

//    eprintf("answer = %lld\n", answer);
//    eprintf("%d %lld\n", sz[a], sumS2[a] );
    fixAnswer(a, 1);
//    eprintf("answer = %lld\n", answer);

//    answer += sqr(n - sz[a] );


    return true;
}

void dfs(int v, int par, int h)
{
    th[v] = h;
    tsz[v] = 1;
    tp[v] = par;
    for (int to : g[v] )
    {
        if (to == par) continue;
        dfs(to, v, h + 1);
        tsz[v] += tsz[to];
        
        sumS2[v] += sqr(tsz[to] );
    }
    sumS2[v] += sqr(n - tsz[v] );
   
    fixAnswer(v, 1);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        up[i] = i;
        p[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dfs(0, 0, 0); 
    printf("%lld\n", answer);

    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;

        while (true)
        {
    //        eprintf("a = %d, b = %d\n", a, b);
            a = up[getP(a) ];
            b = up[getP(b) ];
    //        eprintf("a = %d, b = %d\n", a, b);
            if (a == b) break;
            if (th[a] < th[b] ) swap(a, b);
            uni(a, tp[a] );
        }

        printf("%lld\n", answer);
    }


	return 0;
}