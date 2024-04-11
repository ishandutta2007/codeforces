#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int A[n];
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A, A + n);
	if(k == n)
	{
		cout << A[n - 1];
		return 0;
	}
	if(k == 0 && A[0] == 1)
	{
		cout << - 1;
		return 0;
	}
	else if(k == 0)
	{
		cout << A[0] - 1;
		return 0;
	}
	for(int i = 0; i < n; i++)
	{
		if(i == k - 1 && i != n - 1)
		{
			if(A[i] != A[i + 1])
			{
				cout << A[i];
				return 0;
			}
			else
			{
				cout << -1;
				return 0;
			}
		}
	}
	return 0;	
}