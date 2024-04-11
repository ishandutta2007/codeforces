#include<bits/stdc++.h> 
using namespace std;
vector <pair<int, int> > W, W1;
vector <vector <char> > A;
vector <vector <bool> > used;
void dfs1(int x, int y)
{
	used[x][y] = true;
	W.push_back({x, y});
	if(x > 0 && A[x - 1][y] != '1' && !used[x - 1][y])
	{
		dfs1(x - 1, y);
	}
	if(y > 0 && A[x][y - 1] != '1' && !used[x][y - 1])
	{
		dfs1(x, y - 1);
	}
	if(x < A.size() - 1 && A[x  + 1][y] != '1' && !used[x + 1][y])
	{
		dfs1(x + 1, y);
	}
	if(y < A.size() - 1 && A[x][y + 1] != '1' && !used[x][y + 1])
	{
		dfs1(x, y + 1);
	}
}
void dfs2(int x, int y)
{
	used[x][y] = true;
	W1.push_back({x, y});
	if(x > 0 && A[x - 1][y] != '1' && !used[x - 1][y])
	{
		dfs2(x - 1, y);
	}
	if(y > 0 && A[x][y - 1] != '1' && !used[x][y - 1])
	{
		dfs2(x, y - 1);
	}
	if(x < A.size() -1 && A[x  + 1][y] != '1' && !used[x + 1][y])
	{
		dfs2(x + 1, y);
	}
	if(y < A.size() - 1 && A[x][y + 1] != '1' && !used[x][y + 1])
	{
		dfs2(x, y + 1);
	}
}
int main () {
	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;
	A.resize(n, vector <char> (n));
	used.resize(n, vector <bool> (n, false));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cin >> A[i][j];
		}
	}
	dfs1(x1 - 1, y1 - 1);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			used[i][j] = false;
		}
	}
	int min = 1e9;
	dfs2(x2 - 1, y2 - 1);
	for(int i = 0; i < W.size(); i++)
	{
		for(int j = 0; j < W1.size(); j++)
		{
			if((W[i].first - W1[j].first) * (W[i].first - W1[j].first) + (W[i].second - W1[j].second) * (W[i].second - W1[j].second) < min)
			{
				min = (W[i].first - W1[j].first) * (W[i].first - W1[j].first) + (W[i].second - W1[j].second) * (W[i].second - W1[j].second);
			}
		}
	}
	cout << min;
	return 0;
}