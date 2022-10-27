#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin >> n;
	vector <int> A(n);
	int imax = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(A[i] == n)
		{
			imax = i;
		}
	}
	for(int i = 0; i < imax; i++)
	{
		if(A[i] > A[i + 1])
		{
			cout << "No";
			return 0;
		}
	}
	for(int i = n - 1; i > imax; i--)
	{
		if(A[i] > A[i- 1])
		{
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	return 0;
}