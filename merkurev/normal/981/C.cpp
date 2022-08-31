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
vector <int> g[N];
bool used[N];
vector <int> ans;

void dfs(int v, int p)
{
    used[v] = true;
    for (int to : g[v])
    {
        if (to == p) continue;
        dfs(to, v);
        if (p != -1) return;
    }
    if (p != -1) ans.push_back(v);
}


int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
    int n;
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
    int v = 0;
    for (int i = 0; i < n; i++)
        if ((int) g[i].size() > (int) g[v].size() )
            v = i;
    dfs(v, -1);
    for (int i = 0; i < n; i++)
        if (!used[i] )
        {
            printf("No\n");
            return 0;
        }
    printf("Yes\n");
    printf("%d\n", (int) ans.size() );
    for (int x : ans)
        printf("%d %d\n", v + 1, x + 1);



	return 0;
}