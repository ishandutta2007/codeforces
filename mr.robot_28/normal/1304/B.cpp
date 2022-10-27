#include<bits/stdc++.h>
 
using namespace std;
//#define int long long

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector <bool> used(n);
	vector <string> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	string ans = "";
	for(int i = 0; i < n; i++)
	{
		if(!used[i])
		{
			for(int j = i + 1; j < n; j++)
			{
				if(!used[j])
				{
					bool flag = true;
					for(int p = 0; p < m; p++)
					{
						if(A[i][p] != A[j][m - p - 1])
						{
							flag = false;
						}
					}
					if(flag)
					{
						ans += A[i];
						used[i] = true;
						used[j] = true;
						break;
					}
				}
			}
		}
	}
	string t = "";
	for(int i = 0; i< n; i++)
	{
		if(!used[i])
		{
			bool flag = true;
			for(int j = 0; j < m; j++)
			{
				if(A[i][j] != A[i][m - 1 - j])
				{
					flag = false;
				}
			}
			if(flag && A[i].size() > t.size())
			{
				t = A[i];
			}
		}
	}
	cout << ans.size() * 2 + t.size() << "\n";
	cout << ans << t;
	for(int i = ans.size() - 1; i >= 0; i--)
	{
		cout << ans[i];
	}
	return 0;
}