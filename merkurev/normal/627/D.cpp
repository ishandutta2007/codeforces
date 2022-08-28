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

const int MX = (int) 1e6;
const int N = (int) 2e5 + 100;
int cost[N];
vector <int> ag[N];
bool bad[N], block[N];
bool removed[N];
int deg[N];
int toRem[N];
int sz[N];
bool used[N];
bool answer;

int n, k;

int dfs(int v)
{
	used[v] = true;
	vector <int> mxsz = {0, 0};
	
	for (int to : ag[v] )
	{
		if (bad[to] || removed[to] || used[to] ) continue;
		mxsz.push_back(dfs(to) );
		sort(mxsz.begin(), mxsz.end() );
		reverse(mxsz.begin(), mxsz.end() );
		if (mxsz.size() > 2)
			mxsz.pop_back();
	}
	if (mxsz[0] + mxsz[1] + sz[v] >= k) answer = true;
	return mxsz[0] + sz[v];
}

bool solve(int minAllowed)
{
	answer = false;
	memset(used, false, sizeof used);
	memset(removed, false, sizeof removed);
	memset(block, false, sizeof block);
	memset(bad, false, sizeof bad);
	for (int i = 0; i < n; i++)
	{
		if (cost[i] < minAllowed)
		{
			bad[i] = true;
			for (int x : ag[i] )
				block[x] = true;
		}
		sz[i] = 1;
		deg[i] = (int) ag[i].size();
	}
	int rsz = 0;
	for (int i = 0; i < n; i++)
	{
		if (!bad[i] && !block[i] && deg[i] == 1)
			toRem[rsz++] = i;
	}

	while (rsz > 0)
	{
		int cur = toRem[--rsz];
		if (deg[cur] != 1) continue;
		removed[cur] = true;
		for (int x : ag[cur] )
		{
			if (bad[x] || removed[x] ) continue;
			deg[x]--;
			sz[x] += sz[cur];
			if (!block[x] && deg[x] == 1)
				toRem[rsz++] = x;
		}
	}

	for (int i = 0; i < n; i++)
		if (!removed[i] && !bad[i] && !used[i] )
			dfs(i);

	return answer;
}

int main(int,  char **)
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &cost[i] );
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		ag[a].push_back(b);
		ag[b].push_back(a);
	}
	int lb = 0;
	int rb = MX + 1;

	while (rb - lb > 1)
	{
		int m = (lb + rb) / 2;
		if (solve(m) )
			lb = m;
		else
			rb = m;
	}

	printf("%d\n", lb);

	return 0;
}