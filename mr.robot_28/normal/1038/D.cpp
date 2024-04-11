#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cmath>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin >> n;
	long long A[n];
	for(int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	if(n == 1)
	{
		cout << A[0];
		return 0;
	}
	sort(A, A + n);
	long long min = A[0], i;
	for(i = n - 1; i > 1; i--)
	{
		if(A[i - 1] < 0)
		{
			break;
		}
		else
		{
			min = min - A[i];
		}
	}
	min = A[i] - min;
	for(int j = i - 1; j > 0; j--)
	{
		min -= A[j];
	}
	cout << min;
}