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
int mul(int a, int b)
{
    return (a * 1LL * b) % MOD;
}
void smul(int &a, int b)
{
    a = mul(a, b);
}


const int N = (int) 2e5 + 100;
vector <int> g[N], rg[N];
int indeg[N];
bool used[N];

int dfsBack(int v)
{
    used[v] = true;
    int ans = 1;
    
    for (int to : rg[v] )
        ans += dfsBack(to);

    return ans;
}

void dfsAll(int v)
{
    used[v] = true;
    for (int to : g[v] )
        if (!used[to] )
            dfsAll(to);
    for (int to : rg[v] )
        if (!used[to] )
            dfsAll(to);
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
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        g[a].push_back(b);
        rg[b].push_back(a);
    }

    int ans = 1;
    for (int i = 0; i < 2 * n; i++)
        if (g[i].empty() )
            smul(ans, dfsBack(i) );

    for (int i = 0; i < 2 * n; i++)
        if ((int) g[i].size() == 1 && g[i][0] == i)
            dfsAll(i);

    eprintf("ans = %d\n", ans);

    for (int i = 0; i < 2 * n; i++)
        if (!used[i] )
        {
            dfsAll(i);
            smul(ans, 2);
        }
    eprintf("ans = %d\n", ans);

    printf("%d\n", ans);


	return 0;
}