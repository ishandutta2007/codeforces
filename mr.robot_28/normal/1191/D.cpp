#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
#include<algorithm>
using namespace std;
int main()
{
	#define int long long
	int n;
	cin >> n;
	vector <int> A(n);
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	sort(A.begin(), A.end());
	int cnt = 0;
	for(int i = 0; i < n - 1; i++)
	{
		if(A[i] == A[i + 1])
		{
			if(A[i] == 0)
			{
				cout << "cslnb";
				return 0;
			}
			cnt++;
		}
	}
	if(cnt > 1){
		cout << "cslnb";
		return 0;
	}
	for(int i = 1; i < n - 1; i++)
	{
		if(A[i - 1] == A[i] - 1 && A[i] == A[i + 1])
		{
			cout << "cslnb";
			return 0;
		}
	}
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		if(A[i] < i)
		{
			cout << "cslnb";
			return 0;
		}
		sum += A[i] - i;
	}
	if(sum % 2 == 0)
	{
		cout << "cslnb";
	}
	else
	{
		cout << "sjfnb";
	}
	return 0;
}