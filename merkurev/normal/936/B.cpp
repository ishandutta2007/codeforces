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
vector <int> g[N], rg[N];
vector <int> ord;
bool used[N];
bool reach[N][2];
int par[N][2];
int pos[N];

void dfsOrd(int v)
{
    used[v] = true;
    for (int to : g[v] )
        if (!used[to] )
            dfsOrd(to);
    ord.push_back(v);
}

void dfsReach(int v, int t)
{
    reach[v][t] = true;
    for (int to : g[v] )
        if (!reach[to][t ^ 1] )
        {
            par[to][t ^ 1] = v;
            dfsReach(to, t ^ 1);
        }
}

void printAns(int v, int t)
{
    if (par[v][t] != -1)
        printAns(par[v][t], t ^ 1);
    printf("%d ", v + 1);
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

    memset(pos, -1, sizeof pos);
    memset(par, -1, sizeof par);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            int x;
            scanf("%d", &x);
            x--;
            g[i].push_back(x);
            rg[x].push_back(i);
        }
    }
    int s;
    scanf("%d", &s);
    s--;
    dfsOrd(s);
    dfsReach(s, 0);

    for (int i = 0; i < n; i++)
        if (reach[i][1] && g[i].empty() )
        {
            printf("Win\n");
            printAns(i, 1);
            printf("\n");
            return 0;
        }
    reverse(ord.begin(), ord.end() );
    for (int i = 0; i < (int) ord.size(); i++)
        pos[ord[i] ] = i;
    for (int v = 0; v < n; v++)
    {
        if (pos[v] == -1) continue;
        for (int to : g[v] )
            if (pos[to] < pos[v] )
            {
                printf("Draw\n");
                return 0;
            }
    }
    printf("Lose\n");

	return 0;
}