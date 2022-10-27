#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	cin >> n;
	vector <vector <int> > A(n, vector <int> (n, 1e6));
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			char t;
			cin >> t;
			if(t == '1')
			{
				A[i][j] = 1;
			}
			if(i == j)
			{
				A[i][j] = 1;
			}
		}
	}
	for(int k = 0; k < n; k++)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
			{
				if(A[i][k] + A[k][j] < A[i][j])
				{
					A[i][j] = A[i][k] + A[k][j];
				}
			}
		}
	}
	int m;
	cin >> m;
	vector <int> B(m);
	for(int i = 0; i < m; i++)
	{
		cin >> B[i];
		B[i]--;
	}
	vector <int> ans;
	ans.push_back(0);
	int i = 0;
	while(i < m)
	{
		int j = i + 1;
		while(j < m && A[B[i]][B[j]] == j - i)
		{
			j++;
		}
		ans.push_back(j - 1);
		if(j == m)
		{
			break;
		}
		i = j - 1;
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); i++){
		cout << B[ans[i]] + 1 << " ";
	}
	return 0;
}