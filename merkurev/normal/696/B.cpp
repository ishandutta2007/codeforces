#define _CRT_SECURE_NO_WARNINGS

#ifndef ONLINE_JUDGE
#pragma comment(linker, "/STACK:100500500")
#endif

#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <cmath>
#include <algorithm>
#include <queue>
using namespace std;


#ifndef ONLINE_JUDGE
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define epritnf(...) 42;
#endif

const int N = (int) 1e5 + 100;
vector <int> ch[N];
int n;
double ans[N];
int h[N], sz[N];

int dfs(int v)
{
	sz[v] = 1;
	for (int to : ch[v])
	{
		h[to] = h[v] + 1;
		sz[v] += dfs(to);
	}
	ans[v] = h[v] + (n - h[v] - sz[v]) / 2.;
	return sz[v];
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("errput.txt", "w", stderr);
#endif

	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int p;
		scanf("%d", &p);
		ch[p - 1].push_back(i);
	}
	dfs(0);
	for (int i = 0; i < n; i++)
	{
		printf("%.10lf ", ans[i] + 1);
	}
	printf("\n");

	return 0;
}