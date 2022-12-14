#include <bits/stdc++.h>
using namespace std;
int dist[2222][2222], n, pa[2222], num1, num2;
bool used[2222][2222];
vector<pair<int, int> > ans;
void ask(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &dist[x][i]);
	}
}
int main()
{
	scanf("%d", &n);
	ask(1);
	for (int i = 2; i <= n; i++)
	{
		if (dist[1][i] & 1) num1 ++;
		else num2 ++;
	}
	if (num1 < num2)
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[1][i] & 1) ask(i);
		}
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (dist[1][i] % 2 == 0) ask(i);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (dist[i][j] == 1 && !used[j][i]) 
			{
				ans.push_back(make_pair(i, j));
				used[i][j] = 1;
			}
		}
	}
	printf("!\n");
	fflush(stdout);
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d %d\n", ans[i].first, ans[i].second);
		fflush(stdout);
	}
	return 0;
}