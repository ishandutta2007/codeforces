#include <bits/stdc++.h> 
using namespace std;
#define int long long
main()
{
	int n, k;
	cin >> n >> k;
	vector <vector <int> > A(n + 1, vector <int> (2, -1));
	for(int i = 0; i < k; i++) 
	{
		int t;
		cin >> t;
		if(A[t][0] == -1)
		{
			A[t][0] = A[t][1] = i;
		}
		else
		{
			A[t][0] = min(i, A[t][0]);
			A[t][1] = max(i, A[t][1]);
		}
	}
	int ans = 0;
	for(int i = 1; i < n; i++)
	{
		if(A[i][0] > A[i + 1][1] || A[i + 1][0] == -1 || A[i][0] == -1)
		{
			ans++;
		}
		if(A[i][1] < A[i + 1][0] || A[i + 1][0] == -1 || A[i][0] == -1)
		{
			ans++;
		}
	}
	for(int i = 1; i <= n; i++)
	{
		if(A[i][0] == -1)
		{
			ans++;
		}
	}
	cout << ans;
	return 0;
}