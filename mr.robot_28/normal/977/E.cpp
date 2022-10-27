#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
vector <vector <int> > A;
vector <int> used;
int dfs(int d, int v,  int n)
{
	int count = 0, count1 = 0;
	used[v] = 1;
	for(int i = 0; i < A[v].size(); i++)
	{
		if(used[A[v][i]] == 0)
		{
			count += dfs(v, A[v][i], n);
		}
		else if(used[A[v][i]] == 1 && A[v][i] != d)
		{
			count++;
		}
		count1++;
	}
	used[v] = 2;
	if(count1 == 2 && count == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n, m, count = 0, a, b;
	cin >> n >> m;
	A.resize(n);
	used.resize(n, 0);
	for(int i = 0; i < m; i++)
	{
		cin >> a >> b;
		A[a - 1].push_back(b - 1);
		A[b - 1].push_back(a - 1);
	}
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			count += dfs(i, i, n);
		}
	}
	cout << count;
	return 0;	
}