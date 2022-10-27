#include<bits/stdc++.h>
using namespace std;
vector <vector <int> > g;
int ans = 0;
void per(int i, int n, vector <int> A)
{
	if(i == n)
	{
		vector <vector <bool> > used1(6, vector <bool> (6, false));
		int cnt = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < g[i].size(); j++)
			{
				if(!used1[A[i]][A[g[i][j]]])
				{
					used1[A[i]][A[g[i][j]]] = used1[A[g[i][j]]][A[i]] = true;
					cnt++;
				}
			}
		}
		if(cnt > ans)
		{
			ans = cnt;
		}
	}
	else
	{
		for(int j = 0; j < 6; j++)
		{
			A[i] = j;
			per(i + 1, n, A);
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n);
	for(int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector <int> A(n, 0);
	per(0, n, A);
	cout << ans;
	return 0;
}