#include <iostream>
#include <vector>
using namespace std;


#pragma comment(linker, "/STACK:1500500")

vector <int> q[100500];
long long val[100500];

pair <long long, long long> dfs(int v, int pr)
{
	int len = q[v].size();
	long long up = 0, dwn = 0;
	for (int i = 0; i < len; i++)
	{
		int nv = q[v][i];
		if (nv == pr)
			continue;
		pair <long long, long long> nx = dfs(nv, v);
		up = max(up, nx.first);
		dwn = max(dwn, nx.second);
	}
	long long curVal = val[v] + up - dwn;
	if (curVal > 0)
		dwn += curVal;
	else
		up -= curVal;
	return make_pair(up, dwn);
}




int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);


	int n;
	scanf("%d", &n);
	for (int i = 1; i < n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--;
		b--;
		q[a].push_back(b);
		q[b].push_back(a);
	}


	for (int i = 0; i < n; i++)
		scanf("%I64d", &val[i] );

	pair <long long, long long> ans = dfs(0, - 1);
	printf("%I64d", ans.first + ans.second);


	return 0;
}