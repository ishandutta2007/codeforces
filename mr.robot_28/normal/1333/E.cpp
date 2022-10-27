#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	if(n < 3)
	{
		cout << -1;
		return 0;
	}
	vector <vector <int> > matrix(n, vector <int> (n, -1));
	matrix[0][0] = 9;
	matrix[0][1] = 5;
	matrix[0][2] = 6;
	matrix[1][0] = 7;
	matrix[1][1] = 2;
	matrix[1][2] = 8;
	matrix[2][0] = 1;
	matrix[2][1] = 3;
	matrix[2][2] = 4;
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			matrix[i][j] += n * n - 9;
		}
	}
	int x = n - 1;
	int y = 0;
	string flag = "right";
	if(n % 2 == 0)
	{
		x = 0;
	 	y = n - 1;
	 	flag = "down";
	}
	int cnt = 1;
	while(n != 3 && true)
	{
		matrix[x][y] = cnt;
		if(flag == "down")
		{
			if(x < n - 1 && matrix[x + 1][y] == -1)
			{
				x++;
			}
			else if(y > 0 && matrix[x][y - 1] == -1)
			{
				flag = "left";
				y--;
			}
			else
			{
				break;
			}
		}
		else if(flag == "up")
		{
			if(x > 0 && matrix[x - 1][y] == -1)
			{
				x--;
			}
			else if(y > 0 && matrix[x][y - 1] == -1)
			{
				y--;
				flag = "down";
			}
			else{
				break;
			}
		}
		else if(flag == "left")
		{
			if(y == 0 && x != 0 && matrix[x - 1][y] == -1)
			{
				x--;
				flag = "right";
			}
			else if(y > 0 && matrix[x][y - 1] == -1)
			{
				y--;
			}
			else
			{
				break;
			}
		}
		else
		{
			if(y != n - 1 && matrix[x][y + 1] == -1)
			{
				y++;
			}
			else if(x != 0 && matrix[x - 1][y] == -1)
			{
				x--;
				flag = "up";
			}
			else
			{
				break;
			}
		}
		cnt++;
	}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}
    return 0;
}