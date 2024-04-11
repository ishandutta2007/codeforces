#include<bits/stdc++.h>
 
using namespace std;
//#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		vector <int> A(n, -1), B(n, -1);
		vector <int> up(n, 0);
		for(int i = 0; i < s.size(); i++)
		{
			if(i == 0 && s[i] == '>')
			{
				up[0] = 1;
			}
			else if(i == 0)
			{
				up[0] = -1;
			}
			if(i == s.size() - 1 && s[i] == '<')
			{
				up[n - 1] = 1;
			}
			else if(i == s.size() - 1)
			{
				up[n - 1] = -1;
			}
			if(i != s.size() - 1)
			{
				if(s[i] == '<' && s[i + 1] == '>')
				{
					up[i + 1] = 1;
				}
				else if(s[i] == '>' && s[i + 1] == '<')
				{
					up[i + 1] = -1;
				}
			}
		}
		int a = 1;
		int b = 1;
		bool flag = false;
		for(int i = n - 1; i >= 0; i--)
		{
			if(up[i] == -1)
			{
				flag = true;
			}
			else if(up[i] == 1)
			{
				flag = false;
			}
			if(flag)
			{
				A[i] = a;
				a++;
			}
		}
		flag = false;
		for(int i = 0; i < n; i++)
		{
			if(up[i] == 1)
			{
				flag = false;
			}
			if(up[i] == -1)
			{
				flag = true;
			}
			if(flag)
			{
				B[i] = b;
				b++;
			}
		}
		for(int i = n - 1; i >= 0; i--)
		{
			if(B[i] == -1)
			{
				B[i] = b;
				b++;
			}
		}
		for(int i = n - 1; i >= 0; i--)
		{
			if(A[i] == -1)
			{
				int j =i;
				while(j >= 0 && A[j] == -1)
				{
					j--;
				}
				for(int t = j + 1; t <= i; t++)
				{
					A[t] = a;
					a++;
				}
				i = j + 1;
			}
		}
		for(int i = 0; i < n; i++)
		{
			cout << A[i] << " ";
		}
		cout << "\n";
		for(int i = 0; i < n; i++)
		{
			cout << B[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}