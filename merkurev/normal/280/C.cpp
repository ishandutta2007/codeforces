#include <iostream>
#include <vector>
using namespace std;


vector <int> q[100500];
int levelCnt[100500];
bool used[100500];
int mxL;
double p[100500];
double ans = 0;

void dfs(int v, int level)
{
	used[v] = true;
	int cnt = 0;
	double cur = 0;
	p[v] = 1. / (level + 1);
	ans += p[v];
	for (int i = 0; i < q[v].size(); i++)
	{
		if (used[q[v][i] ] )
			continue;
		dfs(q[v][i], level + 1);
	}
}



double mCnt[100500];
double probAlive[2][100500];

int main()
{

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		q[a].push_back(b);
		q[b].push_back(a);
	}

	 dfs(0, 0);

	printf("%.10lf", ans);


	return 0;
}