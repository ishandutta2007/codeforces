#include<bits/stdc++.h>
 
using namespace std;
void print(vector <vector <char> > a, bool flag)
{
	if(flag)
	{
		for(int j = 0; j < a[0].size(); j++)
		{
			for(int i = 0; i < a.size(); i++)
			{
				cout << a[i][j] << "";
			}
			cout << "\n";
		}
	}
	else
	{
		for(int i = 0; i < a.size(); i++)
		{
			for(int j = 0; j < a[i].size(); j++)
			{
				cout << a[i][j] << "";
			}
			cout << "\n";
		}
	}
	cout << "\n";
}
signed main(){
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		bool flag = 0;
		if(n < m)
		{
			swap(n, m);
			flag = 1;
		}
		bool found = 0;
		vector <vector <int> > a(n + 2, vector <int> (m + 2));
		for(int s = 1; s <= m; s++)
		{
			for(int i = 0; i <= n + 1; i++)
			{
				for(int j = 0; j <= m + 1; j++)
				{
					a[i][j] = 0; 
				}
			}
			for(int i = 1; i <= s; i++)
			{
				a[1][i] = 1;
			}
			int cnt = 0;
			for(int i = 2; i <= n; i++)
			{
				for(int j = 1; j <= m; j++)
				{
					int add = a[i - 1][j] * (a[i - 1][j - 1] + a[i - 1][j + 1]) + a[i - 1][j] * a[i][j - 1] + a[i][j - 1] * a[i - 1][j - 1];
					if(cnt + add <= k && (a[i - 1][j] + a[i][j - 1]))
					{
						a[i][j] = 1;
						cnt += add;
					}
				}
			}
			if(cnt == k)
			{
				found = 1;
				break;
			}
		}
		if(!found)
		{
			cout << -1 << "\n\n";
		}
		else if(flag)
		{
			for(int j = 1; j <= m; j++)
			{
				for(int i = 1; i <= n; i++)
				{
				//	cout << a[i][j];
					if(a[i][j])
					{
						cout << "*";
					}
					else
					{
						cout << ".";
					}
				}
				cout << "\n";
			}
			cout << "\n";
		}
		else
		{
			for(int i = 1; i <= n; i++)
			{
				for(int j = 1; j <= m; j++)
				{
					if(a[i][j])
					{
						cout << "*";
					}
					else
					{
						cout << ".";
					}
				}
				cout << "\n";
			}
			cout << "\n";
		}
	}
	return 0;
}