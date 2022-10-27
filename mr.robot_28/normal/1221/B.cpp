#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <vector <char> > A(n, vector <char> (n, 'E'));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			if(A[i][j] == 'E')
			{
				A[i][j] = 'W';
				queue <pair <int, int> > q;
				q.push({i, j});
				while(q.size() != 0)
				{
					pair <int, int> v = q.front();
					q.pop();
					if(v.first > 0 && v.second > 1 && A[v.first - 1][v.second - 2] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first - 1][v.second - 2] = 'B';
						}
						else
						{
							A[v.first - 1][v.second - 2] = 'W';
						}
						q.push({v.first - 1, v.second - 2});
					}
					if(v.first > 1 && v.second > 0 && A[v.first - 2][v.second - 1] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first - 2][v.second - 1] = 'B';
						}
						else
						{
							A[v.first - 2][v.second - 1] = 'W';
						}
						q.push({v.first - 2, v.second - 1});
					}
					if(v.first + 1 < n && v.second + 2 < n && A[v.first + 1][v.second + 2] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first + 1][v.second + 2] = 'B';
						}
						else
						{
							A[v.first + 1][v.second + 2] = 'W';
						}
						q.push({v.first + 1, v.second + 2});
					}
					if(v.first + 2 < n && v.second + 1 < n && A[v.first + 2][v.second + 1] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first + 2][v.second + 1] = 'B';
						}
						else
						{
							A[v.first + 2][v.second + 1] = 'W';
						}
						q.push({v.first + 2, v.second + 1});
					}
					if(v.first > 0 && v.second + 2 < n && A[v.first - 1][v.second + 2] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first - 1][v.second + 2] = 'B';
						}
						else
						{
							A[v.first - 1][v.second + 2] = 'W';
						}
						q.push({v.first - 1, v.second + 2});
					}
					if(v.first + 2 < n && v.second > 0 && A[v.first + 2][v.second - 1] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first + 2][v.second - 1] = 'B';
						}
						else
						{
							A[v.first + 2][v.second - 1] = 'W';
						}
						q.push({v.first + 2, v.second - 1});
					}
					if(v.first + 1 < n && v.second > 1 && A[v.first + 1][v.second - 2] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first + 1][v.second - 2] = 'B';
						}
						else
						{
							A[v.first + 1][v.second - 2] = 'W';
						}
						q.push({v.first + 1, v.second - 2});
					}
					if(v.first > 1 && v.second + 1 < n && A[v.first - 2][v.second + 1] == 'E')
					{
						if(A[v.first][v.second] == 'W')
						{
							A[v.first - 2][v.second + 1] = 'B';
						}
						else
						{
							A[v.first - 2][v.second + 1] = 'W';
						}
						q.push({v.first - 2, v.second + 1});
					}
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << A[i][j];
		}
		cout << "\n";
	}
	return 0;
}