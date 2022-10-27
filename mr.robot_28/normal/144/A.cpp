#include <iostream>
#include<vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int A[n];
	int min = 101 , max = 0, lmax, lmin;
	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
		if(A[i] > max)
		{
			lmax = i;
			max = A[i];
		}
		if(A[i] <= min)
		{
			lmin = n - i - 1;
			min = A[i];
		}
	}
	if (lmax > n - lmin - 1)
	{
		cout << lmax + lmin - 1;
	}
	else
	{
		cout << lmax + lmin;
	}
    return 0;
}