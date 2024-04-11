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

const int N = (int) 1e5 + 100;
int t[N];
vector <int> g[N], rg[N];
bool used[N];
vector <int> ord;

void dfsOrd(int v)
{
    used[v] = true;
    for (int to : g[v] )
        if (!used[to] ) dfsOrd(to);
    ord.push_back(v);
}


bool bad[N];
int color[N];
int sz[N];


void dfsColor(int v, int c)
{
    sz[c]++;
    color[v] = c;
    for (int to : rg[v] )
        if (color[to] == -1)
            dfsColor(to, c);
        else if (color[to] != color[v] )
            bad[c] = true;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    int n, m, h;
    scanf("%d%d%d", &n, &m, &h);
    for (int i = 0; i < n; i++)
        scanf("%d", &t[i] );
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        if ( (t[a] + 1) % h == t[b] )
        {
//            eprintf("%d -> %d\n", b, a);
            rg[a].push_back(b);
            g[b].push_back(a);
        }
        if ( (t[b] + 1) % h == t[a] )
        {
            rg[b].push_back(a);
            g[a].push_back(b);
//            eprintf("%d -> %d\n", a, b);
        }
    }
    for (int i = 0; i < n; i++)
        if (!used[i] ) dfsOrd(i);


    reverse(ord.begin(), ord.end() );
//    for (int x : ord)
//        eprintf("%d ", x);
//    eprintf("\n");
   
    memset(color, -1, sizeof color);
    int cnt = 0;
    for (int x : ord)
        if (color[x] == -1)
            dfsColor(x, cnt++);

    int bstSz = n + 1;
    int bst = -1;
    for (int i = 0; i < cnt; i++)
        if (!bad[i] && sz[i] < bstSz)
        {
            bstSz = sz[i];
            bst = i;
        }
    printf("%d\n", bstSz);
    for (int i = 0; i < n; i++)
        if (color[i] == bst)
            printf("%d ", i + 1);
    printf("\n");

	return 0;
}