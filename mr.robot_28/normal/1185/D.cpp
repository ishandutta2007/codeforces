#include<bits/stdc++.h> 

using namespace std; 
#define int long long
main() { 
	int n;
	cin >> n;
	vector <pair <int, int> > A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i].first;
		A[i].second = i + 1;;
	}
	sort(A.begin(), A.end());
	if(n == 2)
	{
		cout << 1;
		return 0;
	}
	bool flag = true;
	for(int i = 2; i < n; i++)
	{
		if(A[i].first != A[1].first + (A[2].first - A[1].first) * (i - 1))
		{
			flag = false;
		}
	}
	if(flag)
	{
		cout << A[0].second;
		return 0;
	}
	flag = true;
	for(int i = 2; i < n; i++)
	{
		if(A[i].first != A[0].first + (A[2].first - A[0].first) * (i - 1))
		{
			flag = false;
		}
	}
	if(flag)
	{
		cout << A[1].second;
		return 0;
	}
	int k = 0, imin = -1;
	for(int i = 1; i < n; i++)
	{
		if(A[i].first != A[0].first + (A[1].first - A[0].first) * (i - k))
		{
			if(k == 1)
			{
				cout << -1;
				return 0;
			}
			imin = A[i].second;
			k++;
		}
	}
	cout << imin;
	return 0;
}