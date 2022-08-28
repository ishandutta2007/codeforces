#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


#ifdef LOCAL
	#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int N = 2500;

int n, m;
int v[N];
vector<int> graph[N];
bool used[N];

bool cmp(int a, int b)
{
	return v[a] < v[b];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &v[i]);
	for (int i = 0; i < m; i++)
	{
		int v1, v2;
		scanf("%d%d", &v1, &v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}

	vector<int> perm;
	for (int i = 1; i <= n; i++)
		perm.push_back(i);

	sort(perm.begin(), perm.end(), cmp);

	int64 ans = 0;
	for (int ind : perm)
	{
		for (int to : graph[ind])
			if (used[to])
				ans += v[to];
		used[ind] = true;
	}

	printf("%lld\n", ans);


	return 0;
}