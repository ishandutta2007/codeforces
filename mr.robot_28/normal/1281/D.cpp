#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >>  n >> m;
		vector <vector <char> > A(n, vector <char> (m));
		bool flag = false, flagp = false;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> A[i][j];
				if(A[i][j] == 'A')
				{
					flag = true;
				}
				if(A[i][j] == 'P')
				{
					flagp =true;
				}
			}
		}
		if(!flag)
		{
			cout << "MORTAL\n";
		}
		else if(!flagp)
		{
			cout << 0 << "\n";
		}
		else
		{
			bool flag1 = false, flag2 = false, flag3 = false, flag4 = false;
			vector <vector <bool> > up(n, vector <bool> (m)), down(n, vector <bool> (m)), left(n, vector <bool> (m)), right(n, vector <bool> (m));
			for(int i = 0; i < n; i++)
			{
				for(int j = 0; j < m; j++)
				{
					if((j == 0 || left[i][j - 1]) && A[i][j] == 'A')
					{
						left[i][j] = true;
					}
					if((i == 0 || up[i - 1][j]) && A[i][j] == 'A'){
						up[i][j] = true;
					}
				}
			}
			for(int i = n - 1; i >= 0; i--)
			{
				for(int j = m - 1; j >= 0;j--)
				{
					if((i == n - 1 || down[i + 1][j]) && A[i][j] == 'A')
					{
						down[i][j] = true;
					}
					if((j == m - 1 || right[i][j + 1]) && A[i][j] == 'A')
					{
						right[i][j] = true;
					}
				}
			}
			for(int i = 0; i < n; i++)
			{
				bool flag = true;
				for(int j = 0; j < m; j++)
				{
					if(A[i][j] == 'P')
					{
						flag = false;
					}
					if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && A[i][j] == 'A')
					{
						flag3 = true;
					}
					if(A[i][j] == 'A' && ((i == 0 || i == n - 1) && (left[i][j] || right[i][j]) || (j == 0 || j == m - 1) && (up[i][j] || down[i][j])))
					{
						flag2 = true;
					}
					if(A[i][j] == 'A' && (up[i][j] || down[i][j] || right[i][j] || left[i][j]))
					{
						flag3 = true;
					}
				}
				if(flag && (i == 0 || i == n - 1))
				{
					flag1 = true;
				}
				else if(flag)
				{
					flag2 = true;
				}
			}
			for(int j = 0; j < m; j++)
			{
				bool flag = true;
				for(int i = 0; i < n; i++)
				{
					if(A[i][j] == 'P')
					{
						flag = false;
					}
				}
				if(flag && (j == 0 || j == m- 1))
				{
					flag1 = true;
				}
				else if(flag)
				{
					flag2 = true;
				}
			}
		if(flag1)
		{
			cout << 1 << "\n";
		}
		else if(flag2)
		{
			cout << 2 << "\n";
		}
		else if(flag3)
		{
			cout << 3 << "\n";
		}
		else
		{
			cout << 4 << "\n";
		}
		}
	}
    return 0;
}