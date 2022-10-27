#include<bits/stdc++.h>
using namespace std;
signed main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int cnt = 1;
	for(int i = 0; i < A.size(); i++)
	{
		if(i == 0 && A[i] > 1)
		{
			A[i]--;
		}
		if(i != 0 && A[i] <= A[i - 1])
		{
			A[i]++;
			if(A[i] != A[i - 1])
			{
				cnt++;
			}
		}
		else if(i != 0 && A[i] > A[i - 1])
		{
			if(A[i] - A[i - 1] > 1)
			{
				A[i]--;
			}
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}