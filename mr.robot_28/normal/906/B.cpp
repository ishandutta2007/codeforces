#include<bits/stdc++.h>
 
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	int n1 = min(n, m), m1 = max(n, m);
	if(n * m == 1)
	{
		cout << "YES\n";
		cout << 1;
	}
	else if(n1 == 1 && (m1 == 2 || m1 == 3))
	{
		cout << "NO";
	}
	else if(n1 == 2 && (m1 == 3 || m1 == 2))
	{
		cout << "NO";
	}
	else if(n1 == 1 && m1 == 4)
	{
		cout << "YES\n";
		if(n1 == 1)
		{
			cout << 2 << " " << 4 << " " << 1 << " " << 3;
		}
		else
		{
			cout << 2 << "\n" << 4 << "\n" << 1 << "\n" << 3;
		}
	}
	else if(n1 == 1)
	{
		cout << "YES\n";
		if(m >= 5)
		{
			for(int i = 1; i <= m; i++)
			{
				if(i % 2 == 1)
				{
					cout << i << " ";
				}
			}
			for(int i = 1; i <= m; i++)
			{
				if(i % 2 == 0)
				{
					cout << i << " ";
				}
			}
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				if(i % 2 == 1)
				{
					cout << i << "\n";
				}
			}
			for(int i = 1; i <= n; i++)
			{
				if(i % 2 == 0)
				{
					cout << i << "\n";
				}
			}
		}
	}
	else if(n == 3 && m == 3)
	{
		cout << "YES\n";
		cout << "6 1 8\n";
		cout << "7 5 3\n";
		cout << "2 9 4";
	}
	else if(n >= 2 && m >= 4)
	{
		cout << "YES\n";
		vector <vector <int> > matrix(n, vector <int> (m));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				matrix[i][j] = i * m + j + 1;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if((i + 1) % 2 == 1)
			{
				continue;
			}
			int a = matrix[i][m - 1];
			int b = matrix[i][m - 2];
			for(int j = m - 1; j >= 2; j--)
			{
				matrix[i][j] = matrix[i][j - 2];
			}
			matrix[i][1] = a;
			matrix[i][0] = b;
		}
		for(int j = 0; j < m; j++)
		{
			if((j + 1) % 2 == 1)
			{
				continue;
			}
			int a = matrix[0][j];
			for(int i = 0; i <= n - 2; i++)
			{
				matrix[i][j] = matrix[i + 1][j];
			}
			matrix[n - 1][j] = a;
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else
	{
		cout << "YES\n";
		vector <vector <int> > matrix(n, vector <int> (m));
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				matrix[i][j] = i * m + j + 1;
			}
		}
		for(int i = 0; i < n; i++)
		{
			if((i + 1) % 2 == 1)
			{
				continue;
			}
			int a = matrix[i][m - 1];
			for(int j = m - 1; j >= 1; j--)
			{
				matrix[i][j] = matrix[i][j - 1];
			}
			matrix[i][0] = a;
		}
		for(int j = 0; j < m; j++)
		{
			if((j + 1) % 2 == 1)
			{
				continue;
			}
			int a = matrix[0][j];
			int b = matrix[1][j];
			for(int i = 0; i <= n - 3; i++)
			{
				matrix[i][j] = matrix[i + 2][j];
			}
			matrix[n - 1][j] = b;
			matrix[n - 2][j] = a;
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}