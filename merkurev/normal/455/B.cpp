#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


const int maxn = 1e6 + 100;
char str[maxn];
int nx[maxn][30];
int sz = 1;

int has[maxn];
int timer = 146;

int dfs(int v, int leafVal)
{
	bool leaf = true;
	vector <int> ghas;
	for (int i = 0; i < 30; i++)
	{
		if (nx[v][i] == 0)
			continue;
		leaf = false;
		ghas.push_back(dfs(nx[v][i], leafVal) );
	}
	if (leaf)
		return leafVal;
	timer++;
	for (int i = 0; i < (int) ghas.size(); i++)
		has[ghas[i] ] = timer;
	int ans = 0;
	while (has[ans] == timer)
		ans++;
	return ans;
}

void addWord()
{
	int v = 0;
	int n = strlen(str);
	for (int i = 0; i < n; i++)
	{
		int cur = str[i] -  'a';
		if (nx[v][cur] == 0)
		{
			nx[v][cur] = sz++;
		}
		v = nx[v][cur];
	}
}


int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		addWord();
	}
	bool canFirstWin = dfs(0, 0);
	bool canFirstLose = dfs(0, n + 2);


	if (canFirstWin && canFirstLose)
		printf("First");
	else if (!canFirstWin && !canFirstLose)
		printf("Second");
	else if (canFirstLose)
		printf("Second");
	else if (k % 2 == 1)
		printf("First");
	else
		printf("Second");

	return 0;
}