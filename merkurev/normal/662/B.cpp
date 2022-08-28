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


const int INF = (int) 1e9 + 100;
const int N = (int) 1e5 + 100;
int timer = 146;
int used[N];
int xxx[N];
vector <pair <int, int> > g[N];
int n;

vector <int> loc[2];

int dfs(int v, int sw, int type, int color)
{
	int ans = sw;
	if (sw == 1)
		loc[type].push_back(v);
	xxx[v] = sw;
	used[v] = timer;
	for (auto p : g[v] )
	{
		int to = p.first;
		int needSw = p.second ^ color ^ sw;
		if (used[to] == timer && needSw != xxx[to] )
			return INF;
		if (used[to] == timer) continue;
		ans += dfs(to, needSw, type, color);
	}
	return ans;
}

vector <int> answer[2];

int solve(int color)
{
	timer++;
	int st = timer;
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i] >= st)
			continue;
		loc[0].clear();
		loc[1].clear();
		int ans1 = dfs(i, 0, 0, color);
		timer++;
		int ans2 = dfs(i, 1, 1, color);
		timer++;
		ans += min(ans1, ans2);
		if (ans >= INF)
			return INF;
		if (ans1 < ans2)
			for (int x : loc[0] )
				answer[color].push_back(x);
		else
			for (int x : loc[1] )
				answer[color].push_back(x);
		loc[0].clear();
		loc[1].clear();
	}
	return ans;
}


int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif


	int m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
	{
		int a, b;
		char ch[2];
		scanf("%d%d%s", &a, &b, ch);
		a--;
		b--;
		int x = (ch[0] == 'R' ? 1 : 0);
		g[a].push_back(make_pair(b, x) );
		g[b].push_back(make_pair(a, x) );
	}

	int ans1 = solve(0);
	int ans2 = solve(1);
	int ans = min(ans1, ans2);
	if (ans == INF)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d\n", ans);

	if (ans1 < ans2)
		for (int x : answer[0] )
			printf("%d ", x + 1);
	else
		for (int x : answer[1] )
			printf("%d ", x + 1);
	printf("\n");

	return 0;
}