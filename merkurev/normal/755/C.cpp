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


const int N = (int) 1e4 + 100;
int a[N];
vector <int> g[N];
bool used[N];


void dfs(int v)
{
	used[v] = true;
	for (int x : g[v] )
		if (!used[x] )
			dfs(x);
}

int main(int,  char **)
{
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i] );
		a[i]--;
		g[i].push_back(a[i] );
		g[a[i] ].push_back(i);
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		if (!used[i] )
		{
			ans++;
			dfs(i);
		}
	printf("%d\n", ans);
	


	return 0;
}